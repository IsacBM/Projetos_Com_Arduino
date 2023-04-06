// Biblioteca LCD
#include <LiquidCrystal.h>
#include <Adafruit_LiquidCrystal.h>

// Inicializa a biblioteca LCD
LiquidCrystal LCD(10,9,5,4,3,2);
Adafruit_LiquidCrystal lcd_1(0);
float seno;
int frequencia;
int led_vermelho = 13;
int led_verde = 11;
int led_amarelo = 12;
int SensorTempPino=0;

void setup() {
  // Telas LCD
  lcd_1.begin(16, 2);
  LCD.begin(16,2);
  LCD.print("Temperatura:");
  LCD.setCursor(0,1);
  LCD.print("        C");
  
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(8,OUTPUT);
}

void piscar(int led,int tempo, int quantidade) {
  int cont = 0;
  
  while(cont < quantidade) {
    delay(tempo); // Wait for 1000 millisecond(s)
    digitalWrite(led, HIGH);
    delay(tempo); // Wait for 1000 millisecond(s)
    digitalWrite(led, LOW);
    cont = cont + 1;
  }
}

void loop() {
  int controlador = 0;
  int velocidade = 200;
	// Faz a leitura da tensao no Sensor de Temperatura
  int SensorTempTensao=analogRead(SensorTempPino);
  	// Converte a tensao lida
  float Tensao=SensorTempTensao*5.4;
  Tensao/=1024;
  	// Converte a tensao lida em Graus Celsius
  float TemperaturaC=(Tensao-0.5)*100;
  LCD.setCursor(0,1);
  LCD.print(TemperaturaC);
  // Led - Vermelho:
  digitalWrite(8, HIGH);
  tone(8,332,5);
  digitalWrite(8, LOW);
  digitalWrite(led_vermelho, HIGH);
  lcd_1.print("Vermelho");
  delay(3000);
  digitalWrite(led_vermelho, LOW);
  lcd_1.clear();
  
  
  // Led - Verde:
  digitalWrite(8, HIGH);
  tone(8,432,7);
  digitalWrite(8, LOW);
  digitalWrite(led_verde, HIGH);
  lcd_1.print("Verde");
  delay(4000);
  
  while(controlador < 4){
    controlador++;
    digitalWrite(led_verde, LOW);
    digitalWrite(8, HIGH);
    tone(8,432,25);
    digitalWrite(8, LOW);
    lcd_1.clear();
    delay(velocidade);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_verde, HIGH);
    lcd_1.print("Verde");
    delay(velocidade);
    velocidade = velocidade - 50;
  }
  
  digitalWrite(led_verde, LOW);
  lcd_1.clear();
  
  // Led - Amarelo:
    digitalWrite(led_amarelo, HIGH);
    digitalWrite(8, HIGH);
  tone(8,432,7);
  digitalWrite(8, LOW);
    lcd_1.print("Amarelo");
    delay(500);
    digitalWrite(led_amarelo, LOW);
    lcd_1.clear();
  
}