#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address for the LCD display

int ledPin = 3; // Pin for the LED
int buttonPin = 6; // Pin for the pushbutton
int points = 0;
unsigned long startTime = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Points: 0");

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Randomly turn on the LED
  digitalWrite(ledPin, HIGH);
  delay(random(100, 500)); // LED stays on for a random duration

  // Turn off the LED and start the timer
  digitalWrite(ledPin, LOW);
  startTime = millis();

  // Wait for button press
  while (digitalRead(buttonPin) == HIGH) {
    // Display elapsed time and points
    unsigned long elapsedTime = (millis() - startTime) / 1000;
    lcd.setCursor(0, 1);
    lcd.print("Time: " + String(elapsedTime) + "s   ");
    lcd.setCursor(0, 0);
    lcd.print("Points: " + String(points) + "   ");
  }

  // Button pressed within time frame
  points++;

  // Wait for next set (around 30 seconds)
  delay(30000);
}
