/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL28NFKSsNi"
#define BLYNK_TEMPLATE_NAME "webseries-rooftop"
#define BLYNK_AUTH_TOKEN "FlDTcY9bMDLx_tRaRZrt-tTqGGAcraI3"

#define BLYNK_FIRMWARE_VERSION "0.1.0"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

// Inclusão de biblioteca do modulo relé
#include <SerialRelay.h>
const int NumModules = 1;
int PauseTime = 200;
SerialRelay relays(4, 5, NumModules);  //4 data, 5 clock, NumModules: numero de modulos

#include <Arduino.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(10, 11);  // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

// Synca a interface com o código
BLYNK_CONNECTED() {
  Blynk.syncAll();
}

//SLIDER
BLYNK_WRITE(V0) {   // Função para controlar o valor do PauseTime a partir do Blynk
  PauseTime = param.asInt();  // // Atualiza o pauseTime com o valor do slider no Blynk
}

// SEQUENCIAL
BLYNK_WRITE(V1) {  // Run this "sequencial" function while V1 pin switch.
  int pinValue = param.asInt();  // Get status of V0.
  if (pinValue == 1) {           // If status of V1 is 1 then do stuff in if().

    // turn on one by one starting from relay 1 & module 1
    for (int i = 1; i <= NumModules; i++) {
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i);
        delay(PauseTime);
      }
    }

    // turn off one by one starting from relay 1 & module 1
    for (int i = 1; i <= NumModules; i++) {
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i);
        delay(PauseTime);
      }
    }

    Blynk.run();            // Run rest of show in-between waiting for this loop to repeat or quit.
    int pinValue = 0;       // Set V0 status to 0 to quit, unless button is still pushed (as per below)
    Blynk.syncVirtual(V1);  // ...Then force BLYNK_WRITE(V0) function check of button status to determine if repeating or done.
  }
}

// RANDOM
BLYNK_WRITE(V2) {  // Run this "random" function while V2 pin switch
  int pinValue = param.asInt();

  if (pinValue == 1) {

    int numOperations = random(5, 15);  // Número aleatório de operações
    for (int k = 0; k < numOperations; k++) {
      int module = random(1, NumModules + 1);
      int relay = random(1, 5);

      // Liga ou desliga aleatoriamente
      int state = random(0, 2) ? SERIAL_RELAY_ON : SERIAL_RELAY_OFF;

      relays.SetRelay(relay, state, module);
      delay(PauseTime);
    }

    Blynk.run();
    int pinValue = 0;
    Blynk.syncVirtual(V2);
  }
}

// LIKE A NONOTAK
BLYNK_WRITE(V3) {
  int pinValue = param.asInt();
  if (pinValue == 1) {

    const int relaysPerModule = 4;  // 4 relés por módulo
    const int totalRelays = NumModules * relaysPerModule;

    // Efeito de "corrida" entre módulos e relés
    for (int i = 1; i <= NumModules; i++) {
      for (int j = 1; j <= relaysPerModule; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i);
        delay(PauseTime);  // Intervalo para dar um efeito de corrida
      }
    }

    delay(500);  // Pausa maior após completar um ciclo

    // Efeito de "onda" indo e voltando
    for (int i = NumModules; i >= 1; i--) {
      for (int j = relaysPerModule; j >= 1; j--) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i);
        delay(PauseTime);  // Intervalo para dar um efeito de onda
      }
    }

    delay(1000);  // Uma pausa antes de iniciar um novo ciclo

    // Efeito de "zigue-zague" entre os relés e módulos
    for (int i = 1; i <= NumModules; i++) {
      if (i % 2 == 0) {  // Para módulos pares
        for (int j = relaysPerModule; j >= 1; j--) {
          relays.SetRelay(j, SERIAL_RELAY_ON, i);
          delay(PauseTime);
        }
      } else {  // Para módulos ímpares
        for (int j = 1; j <= relaysPerModule; j++) {
          relays.SetRelay(j, SERIAL_RELAY_ON, i);
          delay(PauseTime);
        }
      }
    }

    delay(500);  // Pausa antes de desligar todos

    // Desligar todos os relés para finalizar
    for (int i = 1; i <= NumModules; i++) {
      for (int j = 1; j <= relaysPerModule; j++) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i);
      }
    }

    delay(2000);  // Pausa longa antes de repetir


    Blynk.run();            // Executa o resto do show aguardando que este loop se repita ou saia.
    int pinValue = 0;       // Defina o status V0 como 0 para sair, a menos que o botão ainda esteja pressionado (conforme abaixo)
    Blynk.syncVirtual(V3);  // ...Então força a verificação da função BLYNK_WRITE(V0) do status do botão para determinar se está repetindo ou pronto.
  }
}

// STROBE
BLYNK_WRITE(V4) {  // Stobe
  int pinValue = param.asInt();
  if (pinValue == 1) {

    // Ligar todos os relés
    for (int i = 1; i <= 4; i++) {
      relays.SetRelay(i, SERIAL_RELAY_ON, 1);
      relays.SetRelay(i, SERIAL_RELAY_ON, 2);
      relays.SetRelay(i, SERIAL_RELAY_ON, 3);
    }
    delay(PauseTime);

    // Desligar todos os relés
    for (int i = 1; i <= 4; i++) {
      relays.SetRelay(i, SERIAL_RELAY_OFF, 1);
      relays.SetRelay(i, SERIAL_RELAY_OFF, 2);
      relays.SetRelay(i, SERIAL_RELAY_OFF, 3);
    }
    delay(PauseTime);

    Blynk.run();            // Executa o resto do show aguardando que este loop se repita ou saia.
    int pinValue = 0;       // Defina o status V0 como 0 para sair, a menos que o botão ainda esteja pressionado (conforme abaixo)
    Blynk.syncVirtual(V4);  // ...Então força a verificação da função BLYNK_WRITE(V0) do status do botão para determinar se está repetindo ou pronto.
  }
}


void setup() {
  // Debug console
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  //  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);
  // You can also specify server:
  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass, "blynk.cloud", 80);  // fica syncado na nuvem
  //Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop() {
  Blynk.run();
}
