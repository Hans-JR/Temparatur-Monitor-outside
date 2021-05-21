#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// set the I2C address to 0x27
// for 4 line display with 20 char per line
// connect I2C Adapter as follows: A4 - SDA, A5 - SCL
// connect DS18B20 to pin D3
// connect DHT to pin D8
// Die Programme werden mit dem USBasp Programmer geladen
// Die Einstellungen für das Board: ATMega 168, Internal, 8Mhz, ohne Bootloader

 LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

#define ONE_WIRE_BUS 3
#define DHTPIN 8
 #define DHTTYPE DHT22
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);                       

// aktuelle Adresse des DS Sensors
// Aussen: 28AAED8A161302E7


float Temperatur[1];

// Sensor 0 feste Vorgabe der Adresse des Aussen-Temperatursensors
DeviceAddress Sensor0 = {0x28, 0xAA, 0xED, 0x8A, 0x16, 0x13, 0x02, 0xE7}; // Aussen

// DHT Sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(20, 4);
  lcd.clear();
  lcd.backlight();
  dht.begin();
  sensors.begin();
 }

void loop() {
  sensors.requestTemperatures();
  Temperatur[0] = sensors.getTempC(Sensor0);

float humidity_data = (float)dht.readHumidity();
float temperature_data = (float)dht.readTemperature();
  
//  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Aussen : ");
  lcd.print(Temperatur[0]);
  lcd.setCursor(16,0);
  lcd.write(223);             // ergibt das "Grad" Zeichen
  lcd.print("C  ");

  lcd.setCursor(0, 1);
   lcd.print("     ----------     ");

  lcd.setCursor(0, 2);
  lcd.print("  Innen  : ");
  lcd.print(temperature_data);
  lcd.setCursor(16,2);
  lcd.write(223);             // ergibt das "Grad" Zeichen
  lcd.print("C  ");

  lcd.setCursor(0, 3);
  lcd.print("  Feuchte: ");
  lcd.print(humidity_data);
  lcd.setCursor(16,3);
  lcd.print("%   ");
  delay(5000);
 
}
