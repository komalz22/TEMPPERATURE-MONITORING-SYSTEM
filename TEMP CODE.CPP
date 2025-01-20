#include <DHT.h>                   // Include DHT sensor library
#include <Wire.h>                  // Include I2C communication library
#include <LiquidCrystal_I2C.h>     // Include LCD library

// Sensor setup
#define DHTPIN 2                   // DHT sensor data pin connected to Arduino Pin 2
#define DHTTYPE DHT11              // DHT11 sensor type
DHT dht(DHTPIN, DHTTYPE);          // Initialize DHT sensor

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2); // 16x2 LCD at I2C address 0x27

void setup() {
  Serial.begin(9600);              // Initialize serial monitor
  dht.begin();                     // Initialize DHT sensor
  lcd.begin();                     // Initialize LCD
  lcd.backlight();                 // Turn on LCD backlight

  lcd.setCursor(0, 0);             // Set cursor position
  lcd.print("Temp Monitor");       // Initial message
  delay(2000);                     // Delay for 2 seconds
  lcd.clear();                     // Clear the screen
}

void loop() {
  // Read temperature from DHT11
  float temperature = dht.readTemperature(); // Read temperature in Celsius

  // Display temperature on Serial Monitor
  Serial.print("Temperature: ");
  if (isnan(temperature)) {
    Serial.println("Error reading sensor");
  } else {
    Serial.print(temperature);
    Serial.println(" °C");
  }

  // Display temperature on LCD
  lcd.setCursor(0, 0);             // Set cursor to the first row
  lcd.print("Temp: ");
  if (isnan(temperature)) {
    lcd.print("Error");
  } else {
    lcd.print(temperature);
    lcd.print(" C");
  }

  delay(2000); // Update every 2 seconds
}