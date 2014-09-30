#include <Ultrasonic.h>

int ledPin = 13; //Atribui o pino 13 a variavel ledPin
int dado; //varivel que recebera os dados da porta serial
int buzzer = 12;
int trigger = 10;
int echo = 11;
int ledAzul = 2;

//Inicializa o sensor ultrasonico
Ultrasonic ultrasonic(trigger,echo);

void setup(){
     Serial.begin(9600);//frequencia da porta serial
     pinMode(ledPin,OUTPUT);//define o pino ledPin como saida 
     pinMode(buzzer, OUTPUT); // define o buzzer como saida
     pinMode(ledAzul, OUTPUT); // define o ledAzul como saida
}


void loop(){
  float cmMsec;
  //Le os dados do sensor, com o tempo de retorno do sinal
  long microsec = ultrasonic.timing();
  //Calcula a distancia em centimetros
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  //Apresenta os dados, em centimetros, na Serial
  delay(1000);
  if(cmMsec<100){
      Serial.print("0");
      Serial.print(cmMsec);
      Serial.print("\n"); 
  }else{
      Serial.print(cmMsec);
      //Serial.print(" CM");
      Serial.print("\n");
  }
  //Comunicacao com o programa em java
  if(Serial.available() > 0){  //Verifica se existe comunicaçao com a porta serial
     dado = Serial.read(); //le os dados da porta serial
     switch(dado){
        case 1:
           digitalWrite(ledPin,HIGH); //liga o pino ledPin
           digitalWrite(ledAzul,HIGH); //liga o led Azul
        break;
        case 2:
           digitalWrite(ledPin, LOW); //desliga o pino ledPin  
           digitalWrite(ledAzul, LOW); //desliga o led Azul 
        break;
        case 3:
           digitalWrite(buzzer, HIGH);
           delay(1000);
           digitalWrite(buzzer, LOW); 
        break;
     }
   
  } 
  
}
