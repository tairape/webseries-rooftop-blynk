#include <SerialRelay.h>  //inclui biblioteca do Modulo Rele Serial

const int NumModules = 3;  // Número máximo de módulos

const int ButtonPin2 = 2;    // Pinagem do primeiro botão
const int ButtonPin3 = 3;    // Pinagem do segundo botão
const int ButtonPin4 = 4;    // Pinagem do terceiro botão
const int ButtonPin5 = 5;    // Pinagem do quarto botão
const int ButtonPin6 = 6;    // Pinagem do quinto botão
const int ButtonPin7 = 7;    // Pinagem do sexto botão
const int ButtonPin8 = 8;    // Pinagem do setimo botão
const int ButtonPin9 = 9;    // Pinagem do oitavo botão
const int ButtonPin10 = 10;  // Pinagem do novo botão
const int ButtonPin11 = 11;  // Pinagem do decimo botão
const int ButtonPin12 = 12;  // Pinagem do decimo primeiro botão
const int ButtonPin13 = 13;  // Pinagem do decimo segundo botão

const int PotentiometerPin = A0;  // Pino do potenciômetro

int PauseTime = 100;  // Intervalo padrão entre operações de relês

bool stopExecution = false;  // Variável para controlar a interrupção dos loops

SerialRelay relays(A5, A4, NumModules);  //definicao da pinagem de data e clock do modulo, e da quantidade de modulos

// -----------------------------------------

void setup() {
  pinMode(ButtonPin2, INPUT_PULLUP);   // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin3, INPUT_PULLUP);   // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin4, INPUT_PULLUP);   // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin5, INPUT_PULLUP);   // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin6, INPUT_PULLUP);   // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin7, INPUT_PULLUP);   // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin8, INPUT_PULLUP);   // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin9, INPUT_PULLUP);   // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin10, INPUT_PULLUP);  // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin11, INPUT_PULLUP);  // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin12, INPUT_PULLUP);  // Configura como entrada com resistor pull-up interno
  pinMode(ButtonPin13, INPUT_PULLUP);  // Configura como entrada com resistor pull-up interno
}

// -----------------------------------------

void loop() {
  // Reseta a variável de interrupção
  stopExecution = false;

  // Lê o valor do potenciômetro e ajusta o PauseTime
  int potValue = analogRead(PotentiometerPin);
  PauseTime = map(potValue, 0, 1023, 10, 5000); // Mapeia o valor do potenciômetro para o intervalo desejado

  // Verifica se o botão está pressionado
  if (digitalRead(ButtonPin2) == LOW) {
    tairapeLoop();  // Chama a função apenas se o botão estiver pressionado
  }

  // Verifica se o botão está pressionado
  if (digitalRead(ButtonPin3) == LOW) {
    cndsdLoop(); // Chama a função apenas se o botão estiver pressionado
  }

  // Verifica se o botão está pressionado
  if (digitalRead(ButtonPin4) == LOW) {
    ztaaLoop(); // Chama a função apenas se o botão estiver pressionado
  }

  if (digitalRead(ButtonPin5) == LOW) {
    DeadDreamsLoop();
  }

  if (digitalRead(ButtonPin6) == LOW) {
    nonotakLoop();
  }

  if (digitalRead(ButtonPin7) == LOW) {
    _404ZeroLoop();
  }

  if (digitalRead(ButtonPin8) == LOW) {
    tundraLoop();
  }

  if (digitalRead(ButtonPin9) == LOW) {
    ikedaLoop();
  }

  if (digitalRead(ButtonPin10) == LOW) {
    _1024Loop();
  }

  if (digitalRead(ButtonPin11) == LOW) {
    hikariLoop();
  }

  if (digitalRead(ButtonPin12) == LOW) {
    changLoop();
  }

  // Verifica se o botão de interrupção foi pressionado
  if (digitalRead(ButtonPin13) == LOW) {
    stopExecution = true; // Define a variável de interrupção como verdadeira
  }
}

void tairapeLoop() {
  // Liga e desliga relês sequencialmente
  for (int i = 1; i <= NumModules; i++) {
    for (int j = 1; j <= 4; j++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int l = 1; l <= 4; l++) {
            relays.SetRelay(l, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      relays.SetRelay(j, SERIAL_RELAY_ON, i);
      delay(PauseTime / 12);
    }
  }

  for (int i = 1; i <= NumModules; i++) {
    for (int j = 1; j <= 4; j++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int l = 1; l <= 4; l++) {
            relays.SetRelay(l, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      relays.SetRelay(j, SERIAL_RELAY_OFF, i);
      delay(PauseTime / 12);
    }
  }
}

void cndsdLoop() {
  // https://www.instagram.com/cndsd/
  // Loop principal
  int numOperations = random(5, 15);  // Número aleatório de operações
  for (int k = 0; k < numOperations; k++) {
    // Verifica se o botão foi pressionado
    if (digitalRead(ButtonPin13) == LOW) {
      // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
      for (int i = 1; i <= NumModules; i++) {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, SERIAL_RELAY_OFF, i);
        }
      }
      return;
    }
    
    int module = random(1, NumModules + 1);
    int relay = random(1, 5);

    // Liga ou desliga aleatoriamente
    int state = random(0, 2) ? SERIAL_RELAY_ON : SERIAL_RELAY_OFF;

    relays.SetRelay(relay, state, module);
    delay(PauseTime / 12);
  }

  // Desliga todos os relés ao encerrar o loop
  for (int i = 1; i <= NumModules; i++) {
    for (int j = 1; j <= 4; j++) {
      relays.SetRelay(j, SERIAL_RELAY_OFF, i);
    }
  }
}

void ztaaLoop() {
  // https://www.ztaa.xyz
  // Loop principal
  const int waveLength = 4;   // Comprimento da "onda" de luz
  const int waveSpeed = PauseTime;  // Velocidade de movimento da "onda"
  const int numSteps = 10;    // Número de etapas na animação da "onda"

  for (int step = 0; step < numSteps; step++) {
    // Verifica se o botão foi pressionado
    if (digitalRead(ButtonPin13) == LOW) {
      // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
      for (int i = 1; i <= NumModules; i++) {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, SERIAL_RELAY_OFF, i);
        }
      }
      return;
    }
    
    // Calcula a posição da "onda" nesta etapa
    int wavePosition = step % (NumModules * waveLength);

    // Liga os relés conforme a posição da "onda"
    for (int i = 1; i <= NumModules; i++) {
      for (int j = 1; j <= 4; j++) {
        int relayIndex = j + (i - 1) * 4;               // Calcula o índice do relé no array
        int distance = abs(relayIndex - wavePosition);  // Calcula a distância do relé à "onda"

        // Define a intensidade do relé com base na distância à "onda"
        // Quanto mais próximo da "onda", mais intenso o relé será
        int intensity = max(0, waveLength - distance);

        // Liga o relé com a intensidade calculada
        relays.SetRelay(j, intensity > 0 ? SERIAL_RELAY_ON : SERIAL_RELAY_OFF, i);
      }
    }

    delay(PauseTime / 12);  // Aguarda um pouco antes de avançar para a próxima etapa
  }

  // Desliga todos os relés ao encerrar o loop
  for (int i = 1; i <= NumModules; i++) {
    for (int j = 1; j <= 4; j++) {
      relays.SetRelay(j, SERIAL_RELAY_OFF, i);
    }
  }
}

void DeadDreamsLoop() {
  // https://www.instagram.com/deaddreamsjp/
  // Padrão 1: Onda de acionamento dos relés
  for (int t = 0; t < 4; t++) {
    for (int i = 1; i <= NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i);
        delay(PauseTime / 8);
      }
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i);
        delay(PauseTime / 8);
      }
    }
  }

  // Padrão 2: Piscar aleatório
  for (int t = 0; t < 8; t++) {
    // Verifica se o botão foi pressionado
    if (digitalRead(ButtonPin13) == LOW) {
      // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
      for (int k = 1; k <= NumModules; k++) {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, SERIAL_RELAY_OFF, k);
        }
      }
      return;
    }
    
    int module = random(1, NumModules + 1);
    int relay = random(1, 5);

    relays.SetRelay(relay, SERIAL_RELAY_ON, module);
    delay(PauseTime / 4);
    relays.SetRelay(relay, SERIAL_RELAY_OFF, module);
    delay(PauseTime / 4);
  }

  // Padrão 3: Onda de acionamento inversa
  for (int t = 0; t < 4; t++) {
    for (int i = NumModules; i > 0; i--) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i);
        delay(PauseTime / 8);
      }
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i);
        delay(PauseTime / 8);
      }
    }
  }

  // Padrão 4: Piscar sequencial
  for (int t = 0; t < 8; t++) {
    // Verifica se o botão foi pressionado
    if (digitalRead(ButtonPin13) == LOW) {
      // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
      for (int k = 1; k <= NumModules; k++) {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, SERIAL_RELAY_OFF, k);
        }
      }
      return;
    }
    
    for (int i = 1; i <= NumModules; i++) {
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i);
        delay(PauseTime / 32);
        relays.SetRelay(j, SERIAL_RELAY_OFF, i);
      }
    }
  }

  // Desliga todos os relés ao encerrar o loop
  for (int i = 1; i <= NumModules; i++) {
    for (int j = 1; j <= 4; j++) {
      relays.SetRelay(j, SERIAL_RELAY_OFF, i);
    }
  }
}

void nonotakLoop() {
  // http://nonotak.com
  // Loop principal
  for (int t = 0; t < 2; t++) {
    // Loop de transição para cima
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);   // Liga o relé
        delay(PauseTime / 8);                        // Breve pausa para criar efeito
        relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
      }
    }

    // Loop de transição para baixo
    for (int i = NumModules - 1; i >= 0; i--) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);   // Liga o relé
        delay(PauseTime / 8);                        // Breve pausa para criar efeito
        relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
      }
    }

    // Loop de efeitos aleatórios
    for (int t = 0; t < 8; t++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      int module = random(1, NumModules + 1);
      int relay = random(1, 5);

      relays.SetRelay(relay, SERIAL_RELAY_ON, module);   // Liga um relé aleatório
      delay(PauseTime / 4);                              // Breve pausa para criar efeito
      relays.SetRelay(relay, SERIAL_RELAY_OFF, module);  // Desliga o relé
      delay(PauseTime / 4);                              // Breve pausa entre os efeitos
    }

    // Loop de flash
    for (int t = 0; t < 4; t++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      for (int i = 1; i <= NumModules; i++) {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, SERIAL_RELAY_ON, i);  // Liga todos os relés
        }
      }
      delay(PauseTime / 8);  // Breve pausa para criar efeito
      for (int i = 1; i <= NumModules; i++) {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, SERIAL_RELAY_OFF, i);  // Desliga todos os relés
        }
      }
      delay(PauseTime / 8);  // Breve pausa entre os efeitos
    }
  }

  // Desliga todos os relés ao encerrar o loop
  for (int k = 1; k <= NumModules; k++) {
    for (int j = 1; j <= 4; j++) {
      relays.SetRelay(j, SERIAL_RELAY_OFF, k);
    }
  }
}

void _404ZeroLoop() {
  // http://404.zero
  // Loop principal
  for (int t = 0; t < 3; t++) {
    // Efeito de varredura horizontal
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);   // Liga o relé
        delay(PauseTime / 32);                        // Pausa para criar efeito
        relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
      }
      delay(PauseTime / 16);  // Pausa entre as colunas
    }

    // Efeito de luz pulsante
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);  // Liga o relé
      }
      delay(PauseTime / 8);  // Pausa para criar efeito de pulso
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
      }
      delay(PauseTime / 8);  // Pausa entre os pulsos
    }

    // Efeito de movimento aleatório
    for (int i = 0; i < 20; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      int module = random(1, NumModules + 1);
      int relay = random(1, 5);

      relays.SetRelay(relay, SERIAL_RELAY_ON, module);   // Liga um relé aleatório
      delay(PauseTime / 16);                             // Breve pausa para criar efeito
      relays.SetRelay(relay, SERIAL_RELAY_OFF, module);  // Desliga o relé
      delay(PauseTime / 16);                             // Breve pausa entre os efeitos
    }

    // Efeito de transição suave
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);   // Liga o relé
        delay(PauseTime / 32);                        // Pausa para criar efeito de transição
        relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
      }
    }
  }

  // Desliga todos os relés ao encerrar o loop
  for (int i = 1; i <= NumModules; i++) {
    for (int j = 1; j <= 4; j++) {
      relays.SetRelay(j, SERIAL_RELAY_OFF, i);
    }
  }
}

void tundraLoop() {
  // https://wearetundra.org
  // Loop principal
  for (int t = 0; t < 3; t++) {
    // Efeito de luzes estroboscópicas e transições suaves
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      // Liga e desliga rapidamente os relés para criar um efeito estroboscópico
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);  // Liga o relé
      }
      delay(PauseTime / 8);  // Breve pausa para criar efeito estroboscópico
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
      }
      delay(PauseTime / 8);  // Breve pausa entre os pulsos

      // Efeito de transição suave
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);  // Liga o relé gradualmente
        delay(PauseTime / 8);                       // Pausa para criar efeito de transição
      }
    }

    // Efeito de corrente elétrica percorrendo os módulos
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      relays.SetRelay(1, SERIAL_RELAY_ON, i + 1);  // Liga o primeiro relé
      delay(PauseTime / 4);                        // Breve pausa para criar efeito
      for (int j = 2; j <= 4; j++) {
        relays.SetRelay(j - 1, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé anterior
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);       // Liga o próximo relé
        delay(PauseTime / 4);                             // Breve pausa para criar efeito
      }
      relays.SetRelay(4, SERIAL_RELAY_OFF, i + 1);  // Desliga o último relé
    }

    // Efeito de explosão de luzes
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }
      
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);  // Liga todos os relés
      }
      delay(PauseTime / 8);  // Breve pausa para criar efeito
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga todos os relés
      }
    }
  }

  // Desliga todos os relés ao encerrar o loop
  for (int k = 1; k <= NumModules; k++) {
    for (int j = 1; j <= 4; j++) {
      relays.SetRelay(j, SERIAL_RELAY_OFF, k);
    }
  }
}

void ikedaLoop() {
  // https://www.ryojiikeda.com
  // Loop principal
  for (int t = 0; t < 2; t++) {
    // Efeito de luzes pulsantes e sonoridade minimalista
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, encerra imediatamente o loop
        return;
      }

      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);   // Liga o relé
        delay(PauseTime / 4);                        // Pausa para criar efeito de pulso
        relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
      }
    }

    // Efeito de movimento vertical
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, encerra imediatamente o loop
        return;
      }

      // Liga todos os relés em um módulo
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);  // Liga o relé
      }
      delay(PauseTime / 2);  // Breve pausa para criar efeito de movimento
      // Desliga todos os relés em um módulo
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
      }
    }

    // Efeito de luzes piscantes aleatórias
    for (int i = 0; i < 20; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, encerra imediatamente o loop
        return;
      }

      int module = random(1, NumModules + 1);  // Seleciona um módulo aleatório
      int relay = random(1, 5);                // Seleciona um relé aleatório

      relays.SetRelay(relay, SERIAL_RELAY_ON, module);   // Liga o relé
      delay(PauseTime / 8);                             // Breve pausa para criar efeito de piscar
      relays.SetRelay(relay, SERIAL_RELAY_OFF, module);  // Desliga o relé
    }
  }

  // Desliga todos os relés ao encerrar o loop
  for (int i = 1; i <= NumModules; i++) {
    for (int j = 1; j <= 4; j++) {
      relays.SetRelay(j, SERIAL_RELAY_OFF, i);
    }
  }
}

void _1024Loop() {
  // https://www.1024architecture.net
  static bool sequential = true;  // Variável para controlar se a sequência é sequencial ou randômica
  // Loop principal
  for (int t = 0; t < 3; t++) {
    // Verifica se o botão foi pressionado
    if (digitalRead(ButtonPin13) == LOW) {
      // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
      for (int i = 1; i <= NumModules; i++) {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, SERIAL_RELAY_OFF, i);
        }
      }
      return;
    }

    // Efeito de luzes em movimento com variação
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, desliga imediatamente todos os relés e encerra o loop
        for (int k = 1; k <= NumModules; k++) {
          for (int j = 1; j <= 4; j++) {
            relays.SetRelay(j, SERIAL_RELAY_OFF, k);
          }
        }
        return;
      }

      // Liga os relés em uma direção
      if (sequential) {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);  // Liga o relé
          delay(PauseTime / 8);                       // Pausa para criar efeito espaçado
        }
      } else {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, SERIAL_RELAY_ON, NumModules - i);  // Liga o relé na direção contrária
          delay(PauseTime / 8);                                // Pausa para criar efeito espaçado
        }
      }
      delay(PauseTime / 8);  // Pausa entre direções
      // Desliga os relés na direção oposta ou de forma aleatória
      for (int j = 4; j >= 1; j--) {
        if (sequential || random(2)) {
          relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
        }
        delay(PauseTime / 8);  // Pausa para criar efeito espaçado
      }
    }
    sequential = false;  // Define para randômico após a primeira execução do loop
  }

  // Desliga todos os relés ao encerrar o loop
  for (int i = 1; i <= NumModules; i++) {
    for (int j = 1; j <= 4; j++) {
      relays.SetRelay(j, SERIAL_RELAY_OFF, i);
    }
  }
  sequential = true;  // Reseta o estado de sequential
}

void hikariLoop() {
  // https://www.hikarimune.com
  // Loop principal
  for (int t = 0; t < 3; t++) {
    // Verifica se o botão foi pressionado
    if (digitalRead(ButtonPin13) == LOW) {
      // Se o botão foi pressionado, encerra imediatamente o loop
      return;
    }

    for (int i = 0; i < NumModules; i++) {
      for (int intensity = 0; intensity <= 1; intensity++) {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, intensity ? SERIAL_RELAY_ON : SERIAL_RELAY_OFF, i + 1);  // Liga ou desliga o relé dependendo da intensidade
        }
        delay(PauseTime / 8);  // Pausa para criar efeito suave
      }
      // Desliga os relés gradualmente
      for (int intensity = 1; intensity >= 0; intensity--) {
        for (int j = 1; j <= 4; j++) {
          relays.SetRelay(j, intensity ? SERIAL_RELAY_ON : SERIAL_RELAY_OFF, i + 1);  // Liga ou desliga o relé dependendo da intensidade
        }
        delay(PauseTime / 16);  // Pausa para criar efeito suave
      }
    }

    for (int i = 0; i < 42; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, encerra imediatamente o loop
        return;
      }

      for (int j = 1; j <= 4; j++) {
        for (int k = 0; k < NumModules; k++) {
          relays.SetRelay(j, i > 21 ? SERIAL_RELAY_ON : SERIAL_RELAY_OFF, k + 1);  // Liga ou desliga o relé dependendo da intensidade de cor
        }
      }
      delay(PauseTime / 32);  // Pausa para criar efeito de transição de cor suave
    }
  }

  // Desliga todos os relés ao encerrar o loop
  for (int i = 1; i <= NumModules; i++) {
    for (int j = 1; j <= 4; j++) {
      relays.SetRelay(j, SERIAL_RELAY_OFF, i);  // Desliga o relé
    }
  }
}

void changLoop() {
  // https://hsiinyu.com
  // Loop principal
  for (int t = 0; t < 3; t++) {
    // Efeito de luz em movimento suave e contínuo
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, encerra imediatamente o loop
        return;
      }
      
      // Liga os relés gradualmente
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);  // Liga o relé
        delay(PauseTime / 8);                       // Pausa para criar efeito suave
      }
      // Desliga os relés gradualmente
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
        delay(PauseTime / 8);                        // Pausa para criar efeito suave
      }
    }

    // Efeito de movimento aleatório
    for (int i = 0; i < NumModules; i++) {
      // Verifica se o botão foi pressionado
      if (digitalRead(ButtonPin13) == LOW) {
        // Se o botão foi pressionado, encerra imediatamente o loop
        return;
      }
      
      // Liga e desliga os relés de forma aleatória
      for (int j = 1; j <= 4; j++) {
        if (random(2)) {
          relays.SetRelay(j, SERIAL_RELAY_ON, i + 1);  // Liga o relé
        } else {
          relays.SetRelay(j, SERIAL_RELAY_OFF, i + 1);  // Desliga o relé
        }
      }
      delay(PauseTime / 4);  // Pausa para criar efeito de movimento
    }

    // Desliga todos os relés ao encerrar o loop
    for (int i = 1; i <= NumModules; i++) {
      for (int j = 1; j <= 4; j++) {
        relays.SetRelay(j, SERIAL_RELAY_OFF, i);  // Desliga o relé
      }
    }
  }
}