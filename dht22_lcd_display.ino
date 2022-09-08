#include <DHT.h>;
#include <LiquidCrystal.h>
#include <Wire.h>

int Con = 100;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DHTPIN 13     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE); 

int chk;
float hum;  
float temp; 

void setup()
{
  analogWrite(6, Con);
  lcd.begin(20, 4);
  Wire.begin();
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temperature: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  delay(500); //Delay 2 sec.

  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.setCursor(0, 1);
  lcd.print(hum);
  lcd.print("%");
  lcd.setCursor(0, 2);
  lcd.print("Temperature: ");
  lcd.setCursor(0, 3);
  lcd.print(temp);
  lcd.print(" Celsius");

  delay(5000);
  lcd.clear();
}
