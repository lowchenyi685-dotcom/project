#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>


// --- NEW PIN DEFINITIONS BASED ON YOUR WIRING ---
#define TFT_CS   -1   // Not used
// #define TFT_DC    2   // Pin 2 -> DC
// #define TFT_RST   3   // Pin 3 -> RES
// #define TFT_SDA   11   // Pin 4 -> SDA (MOSI)
// #define TFT_SCL   13   // Pin 5 -> SCL (CLK)


#define TFT_DC   10
#define TFT_RST  9


const int buttonA_Pin = 2;  // Right Bumper -> Counter A
const int buttonB_Pin = 3;  // Left Bumper  -> Counter B


// --- INITIALIZE WITH CUSTOM SPI PINS ---
// Constructor format: (CS, DC, MOSI, SCLK, RST)
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);


int counterA = 0;
int counterB = 0;
int lastStateA = HIGH;
int lastStateB = HIGH;


void setup() {
  Serial.begin(9600);


  // Initialize Bumpers with Internal Pullups
  pinMode(buttonA_Pin, INPUT_PULLUP);
  pinMode(buttonB_Pin, INPUT_PULLUP);


  // Initialize TFT Screen
  tft.init(240, 240, SPI_MODE3);
  tft.setRotation(0);
  tft.fillScreen(ST77XX_RED);
  delay(2000);

  tft.fillScreen(ST77XX_BLACK);

  tft.drawRect(0,0,239,239,ST77XX_WHITE);

  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(3);
  tft.setCursor(20,20);
  tft.print("HELLO");
  delay(2000);
 
  // Welcome Screen
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(40, 100);
  tft.print("DUAL COUNTER");
  delay(2000);
 
  // Layout setup
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 40);
  tft.print("Count A");
  tft.setCursor(140, 40);
  tft.print("Count B");


  // Initial values
  tft.setTextSize(4);
  tft.setCursor(40, 100);
  tft.print(counterA);
  tft.setCursor(160, 100);
  tft.print(counterB);
}


void loop() {
  int stateA = digitalRead(buttonA_Pin);
  int stateB = digitalRead(buttonB_Pin);
  Serial.print(stateA);
  Serial.print("|");
  Serial.println(stateB);


  // Button A Logic
  if (lastStateA == HIGH && stateA == LOW) {
    counterA++;
    tft.fillRect(20, 90, 80, 50, ST77XX_BLACK);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(4);
    tft.setCursor(40, 100);
    tft.print(counterA);
    delay(150);
  }
  lastStateA = stateA;


  // Button B Logic
  if (lastStateB == HIGH && stateB == LOW) {
    counterB++;
    tft.fillRect(140, 90, 80, 50, ST77XX_BLACK);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(4);
    tft.setCursor(160, 100);
    tft.print(counterB);
    delay(150);
  }
  lastStateB = stateB;
  delay(100);
}

