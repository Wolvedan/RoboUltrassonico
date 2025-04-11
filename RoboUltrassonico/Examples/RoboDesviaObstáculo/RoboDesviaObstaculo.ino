#include <RoboUltrassonico.h>

// Definindo os pinos: trig, echo, IN1, IN2, IN3, IN4
RoboUltrassonico robo(10, 11, 3, 5, 6, 9);

// Parâmetros do robô
const float DISTANCIA_MINIMA = 20.0; // Distância mínima para desviar (em cm)
const uint8_t VELOCIDADE_PADRAO = 150; // Velocidade padrão (0 a 255)

void setup() {
  // Inicializa a comunicação serial para depuração (opcional)
  Serial.begin(9600);
  
  // Semente para números aleatórios (para escolher direção de giro)
  randomSeed(analogRead(0));
}

void loop() {
  // Lê a distância do sensor ultrassônico
  float distancia = robo.lerSensor();
  
  // Exibe a distância (opcional, para depuração)
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  // Verifica se há um obstáculo muito próximo
  if (distancia < DISTANCIA_MINIMA && distancia > 0) {
    // Para o robô
    robo.frente(0);
    delay(500); // Pequena pausa para estabilizar
    
    // Escolhe aleatoriamente virar à esquerda ou à direita
    if (random(2) == 0) {
      robo.vireEsquerda(VELOCIDADE_PADRAO);
      Serial.println("Virando à esquerda");
    } else {
      robo.vireDireita(VELOCIDADE_PADRAO);
      Serial.println("Virando à direita");
    }
    
    // Gira por um tempo para evitar o obstáculo
    delay(800); // Ajuste conforme o robô (tempo de giro)
    
    // Para o giro
    robo.frente(0);
    delay(500);
  } else {
    // Se não há obstáculo, move para frente
    robo.frente(VELOCIDADE_PADRAO);
    Serial.println("Movendo para frente");
  }
  
  // Pequeno atraso para evitar leituras muito rápidas
  delay(100);
}