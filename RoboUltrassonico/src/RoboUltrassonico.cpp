#include "RoboUltrassonico.h"

RoboUltrassonico::RoboUltrassonico(uint8_t trig, uint8_t echo, uint8_t pinIN1, uint8_t pinIN2, uint8_t pinIN3, uint8_t pinIN4) {
    // Inicializa os pinos do sensor ultrassônico
    trigPin = trig;
    echoPin = echo;
    
    // Inicializa os pinos do driver L298N
    in1 = pinIN1;
    in2 = pinIN2;
    in3 = pinIN3;
    in4 = pinIN4;
    
    // Configura os pinos como saídas
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
    // Garante que os motores estejam parados inicialmente
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 0);
}

void RoboUltrassonico::frente(uint8_t velocidade) {
    // Motor esquerdo para frente (IN1 PWM, IN2 LOW)
    analogWrite(in1, velocidade);
    analogWrite(in2, 0);
    
    // Motor direito para frente (IN3 PWM, IN4 LOW)
    analogWrite(in3, velocidade);
    analogWrite(in4, 0);
}

void RoboUltrassonico::re(uint8_t velocidade) {
    // Motor esquerdo para trás (IN1 LOW, IN2 PWM)
    analogWrite(in1, 0);
    analogWrite(in2, velocidade);
    
    // Motor direito para trás (IN3 LOW, IN4 PWM)
    analogWrite(in3, 0);
    analogWrite(in4, velocidade);
}

void RoboUltrassonico::vireDireita(uint8_t velocidade) {
    // Motor esquerdo para frente (IN1 PWM, IN2 LOW)
    analogWrite(in1, velocidade);
    analogWrite(in2, 0);
    
    // Motor direito para trás (IN3 LOW, IN4 PWM)
    analogWrite(in3, 0);
    analogWrite(in4, velocidade);
}

void RoboUltrassonico::vireEsquerda(uint8_t velocidade) {
    // Motor esquerdo para trás (IN1 LOW, IN2 PWM)
    analogWrite(in1, 0);
    analogWrite(in2, velocidade);
    
    // Motor direito para frente (IN3 PWM, IN4 LOW)
    analogWrite(in3, velocidade);
    analogWrite(in4, 0);
}

float RoboUltrassonico::lerSensor() {
    // Envia um pulso de 10µs no pino Trigger
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Mede o tempo de retorno do pulso no pino Echo
    long duracao = pulseIn(echoPin, HIGH);
    
    // Calcula a distância em centímetros (velocidade do som: 343 m/s)
    // Distância = (tempo * velocidade do som) / 2
    float distancia = duracao * 0.0343 / 2;
    
    return distancia;
}