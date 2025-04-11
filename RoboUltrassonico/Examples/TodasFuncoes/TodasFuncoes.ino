#include <RoboUltrassonico.h>

// Definindo os pinos: trig, echo, IN1, IN2, IN3, IN4
RoboUltrassonico robo(10, 11, 3, 5, 6, 9);

// Parâmetros
const uint8_t VELOCIDADE = 150; // Velocidade padrão para os movimentos (0 a 255)
const int TEMPO_MOVIMENTO = 1000; // Tempo de cada movimento em milissegundos

void setup() {
  // Inicializa a comunicação serial para exibir resultados
  Serial.begin(9600);
  Serial.println("Iniciando demonstração de todas as funções do RoboUltrassonico");
}

void loop() {
  // Demonstração da função lerSensor()
  Serial.println("--- Testando lerSensor ---");
  float distancia = robo.lerSensor();
  Serial.print("Distância medida: ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(1000); // Pausa para leitura clara

  // Demonstração da função frente()
  Serial.println("--- Testando frente ---");
  robo.frente(VELOCIDADE);
  Serial.println("Movendo para frente");
  delay(TEMPO_MOVIMENTO);
  robo.frente(0); // Para o robô
  Serial.println("Parado");
  delay(500);

  // Demonstração da função re()
  Serial.println("--- Testando re ---");
  robo.re(VELOCIDADE);
  Serial.println("Movendo para trás");
  delay(TEMPO_MOVIMENTO);
  robo.re(0); // Para o robô
  Serial.println("Parado");
  delay(500);

  // Demonstração da função vireDireita()
  Serial.println("--- Testando vireDireita ---");
  robo.vireDireita(VELOCIDADE);
  Serial.println("Virando à direita");
  delay(TEMPO_MOVIMENTO);
  robo.vireDireita(0); // Para o robô
  Serial.println("Parado");
  delay(500);

  // Demonstração da função vireEsquerda()
  Serial.println("--- Testando vireEsquerda ---");
  robo.vireEsquerda(VELOCIDADE);
  Serial.println("Virando à esquerda");
  delay(TEMPO_MOVIMENTO);
  robo.vireEsquerda(0); // Para o robô
  Serial.println("Parado");
  delay(500);

  // Pequena pausa antes de repetir o ciclo
  Serial.println("Fim do ciclo. Reiniciando em 2 segundos...");
  delay(2000);
}