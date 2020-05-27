#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

#define dht_pin 3
#define rain_pin 2

dht DHT;
LiquidCrystal_I2C lcd(0x3F,16,02);

int current_time = 0,published_time = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.init();
  lcd.backlight();
  pinMode(rain_pin,INPUT);
  DHT.read11(dht_pin);
}

void loop() {
  while(!Serial.available()){
  int humidity = DHT.humidity;
  float temperature = DHT.temperature;
  boolean isRaining = digitalRead(rain_pin);
  if (humidity > 0 && temperature > 0){
  lcd.setCursor(0,0);
  lcd.print("hum:");
  lcd.setCursor(4,0);
  lcd.print(String(humidity));
  lcd.setCursor(7,0);
  lcd.print("tem:");
  lcd.setCursor(11,0);
  lcd.print(String(temperature));
  lcd.setCursor(0,1);
  isRaining == false ? lcd.print("RAINING    "):lcd.print("NOT RAINING");
    Serial.print("The Sensor Readings are : \n");
    Serial.print("temperature : "+String(temperature)+"\n");
    Serial.print("humidity : "+String(humidity)+"\n");
    Serial.print("Raining Status : ");
    isRaining == false ? Serial.print("RAINING\n"):Serial.print("NOT RAINING\n");
  }
  delay(1000);
}
}
