#include <LiquidCrystal.h>
const int sensor = 5; //
int val = 0;
LiquidCrystal lcd (8,9,4,5,6,7); // lcd - RS,E, D4, D5, D6, D7

void setup() {
//Serial.begin(9600);// проверка значений на монитор порта
lcd.begin (16,2);
lcd.clear();
lcd.setCursor(0,0); lcd.print("Hello :-) ");
lcd.setCursor(0,1); lcd.print("Ready to go!");
delay(3000);
}

void loop() {
val = analogRead(sensor);
val = map(val, 0, 1023, 100, 0); // вызов функции map - перевод диапазона от 0 до 1023 к диапазону от 100 до 0

lcd.clear();
lcd.setCursor(0,0); lcd.print("Water in the");
lcd.setCursor(0,1); lcd.print("soil: ");
lcd.setCursor(8,1); lcd.print("% "); 
lcd.setCursor(5,1); lcd.print(val);
//Serial.println(val);  // проверка значений на монитор порта

if (val<=35){lcd.setCursor(10,1); lcd.print("dry"); }
if (val>=70){lcd.setCursor(10,1); lcd.print("very wet"); }
if (val>=36 && val<=69){lcd.setCursor(10,1); lcd.print("wet ok"); } 
delay(500);
}
