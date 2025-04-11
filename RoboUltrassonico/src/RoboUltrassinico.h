#ifndef ROBOULTRASSONICO_H
#define ROBOULTRASSONICO_H

#include <Arduino.h>

class RoboUltrassonico {
private:
    // Pinos do sensor ultrassônico HC-SR04
    uint8_t trigPin;
    uint8_t echoPin;
    
    // Pinos do driver L298N
    uint8_t in1; // IN1 do L298N
    uint8_t in2; // IN2 do L298N
    uint8_t in3; // IN3 do L298N
    uint8_t in4; // IN4 do L298N
    
public:
    // Construtor
    RoboUltrassonico(uint8_t trig, uint8_t echo, uint8_t pinIN1, uint8_t pinIN2, uint8_t pinIN3, uint8_t pinIN4);
    
    // Funções de movimento
    void frente(uint8_t velocidade);
    void re(uint8_t velocidade);
    void vireDireita(uint8_t velocidade);
    void vireEsquerda(uint8_t velocidade);
    
    // Função para leitura do sensor ultrassônico
    float lerSensor();
};

#endif