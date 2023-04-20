// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int red = 6;
int yellow = 7;
int green = 10;
int buzzer = 13;
int triggerpin = 9;
int echopin = 8;
int duration, cm;

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  pinMode(triggerpin, OUTPUT);

  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerpin, LOW);
  pinMode(echopin, INPUT);

  duration = pulseIn(echopin, HIGH);
  cm = (duration / 29) / 2;

  Serial.print(cm);
  Serial.println("cm");

  if (cm >= 230 and cm <= 330)
  {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    lcd.print(cm);
    lcd.setCursor(4, 0);
    lcd.print("cm");
    delay(1000);
    lcd.clear();
  }
  if (cm >= 100 and cm <= 229)
  {
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    tone(13, 523, 500);
    lcd.print(cm);
    lcd.setCursor(4, 0);
    lcd.print("cm");
    delay(1000);
    lcd.clear();
  }
  if (cm >= 5.5 and cm <= 99)
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    tone(13, 555, 510);
    delay(10);
    lcd.print(cm);
    lcd.setCursor(4, 0);
    lcd.print("cm");
    delay(1000);
    lcd.clear();
  }

  delay(1000);
}
