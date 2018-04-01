#include <SPI.h>
#include <PicoUI.h>
#include <Adafruit_SSD1306.h>

//Uncomment this block to use hardware SPI
#define OLED_DC     21
#define OLED_CS     10
#define OLED_RESET  6
Adafruit_SSD1306 oledDisp(OLED_CS, OLED_DC, OLED_RESET);

PicoUI ui;

PicoUI_Page settings_page;

PicoUI_RotaryEncoder dataWheel;
PicoUI_Button confirm;
PicoUI_Button cancel;

void setup() {
  ui.attachDisplay(oledDisp);
  settings_page.addElement(dataWheel, 0, 0);
  settings_page.addElement(confirm, 64, 0);
  settings_page.addElement(cancel, 80, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
