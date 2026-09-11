# project
<h1 align="center">👋Hi, I'm < LOW CEN YEE></h1>
<p align="center">A passionate young student that is keen to explore new things and create innovative solutions. Recently exploring AI and AI Agents with Python.</p>

## 🏗️ What I'm Building

<Project RFID STUDENT PICKUP SYSTEM>
  
  THIS IS THE CODE
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

const int buzzerPin = 7;

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(115200);

  // Start buzzer
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  // Start LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("RFID SYSTEM");

  lcd.setCursor(0, 1);
  lcd.print("Scan your card");

  // Start RFID
  SPI.begin();
  mfrc522.PCD_Init();

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan your card");

  Serial.println("RFID System Ready");
}

void beep()
{
  digitalWrite(buzzerPin, HIGH);
  delay(200);
  digitalWrite(buzzerPin, LOW);
}

void loop()
{
  // Check for a new card
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  // Read the card
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  // Create UID string
  String uid = "";

  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    if (mfrc522.uid.uidByte[i] < 0x10)
    {
      uid += "0";
    }

    uid += String(mfrc522.uid.uidByte[i], HEX);
  }

  uid.toUpperCase();

  Serial.print("Card UID: ");
  Serial.println(uid);

  // STUDENT 1
  if (uid == "1CDB6506")
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("LOW YU JIA");

    lcd.setCursor(0, 1);
    lcd.print("3K");

    beep();
    delay(3000);
  }

  // STUDENT 2
  else if (uid == "57F91D62")
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("LEE HUI YANG");

    lcd.setCursor(0, 1);
    lcd.print("4S1");

    beep();
    delay(3000);
  }

  // STUDENT 3
  else if (uid == "BA77F106")
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("ANG XIN HAO");

    lcd.setCursor(0, 1);
    lcd.print("4S1 ");

    beep();
    delay(3000);
  }

  // UNKNOWN CARD
  else
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Unknown Card");

    lcd.setCursor(0, 1);
    lcd.print("Not registered");

    delay(3000);
  }

  // Stop RFID communication
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  // Return to waiting screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan your card");

  delay(500);
}

## 🛠️ Tools I Use

<My languages is English and Chinese I use Arduino >
