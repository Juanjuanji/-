#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define ONE_WIRE_BUS 7
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
OneWire OneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&OneWire);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
}




void loop() {
  sensors.requestTemperatures();
  float temperature=sensors.getTempCByIndex(0);
  display.println(temperature);
  Serial.print("Tem:");
  Serial.print(sensors.getTempCByIndex(0));
  delay(10);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(temperature);
  display.display();
  delay(100);  //oled屏幕代码
  // put your main code here, to run repeatedly:
}
