#include <LiquidCrystal.h>

/*
LCD CONNECTIONS
RS -> D2
EN -> D3
D4 -> D4
D5 -> D5
D6 -> D6
D7 -> D7
RW -> GND
*/

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Pin definitions
const int potPin = A0;
const int greenLED  = 8;
const int yellowLED = 9;
const int redLED    = 10;
const int buzzer    = 11;

float voltage = 0;
int health = 0;

void setup() {
  lcd.begin(16, 2);
  
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  lcd.setCursor(0,0);
  lcd.print("Battery Monitor");
  lcd.setCursor(0,1);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  int adcValue = analogRead(potPin);
  
  // ADC → Voltage (0–5V)
  voltage = adcValue * (5.0 / 1023.0);
  
  // Voltage → Health %
  health = (voltage / 5.0) * 100;
  
  // Reset outputs
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);
  
    // ----- STATUS LOGIC (PERCENTAGE BASED) -----
  String status;
  if (health >= 66) {                // 66% and above
    digitalWrite(greenLED, HIGH);
    status = "HEALTHY ";
  }
  else if (health >= 33) {           // 33%-66%
    digitalWrite(yellowLED, HIGH);
    status = "WARNING ";
  }
  else {                             // Below 33%
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    status = "CRITICAL";
  }
  
  // ----- LCD DISPLAY -----
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("V:");
  lcd.print(voltage, 2);
  lcd.print("V H:");
  lcd.print(health);
  lcd.print("%");
  
  lcd.setCursor(0,1);
  lcd.print("Status:");
  lcd.print(status);
  
  delay(500);
}
