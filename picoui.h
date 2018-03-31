#include "Arduino.h"

#define DISPLAY_TYPE_SSD1306 1

#ifdef DISPLAY_TYPE_SSD1306
#include <SPI.h>
#include <OLED_SSD1306.h>
#endif

typedef struct Control {
  unsigned int type;
  unsigned int id;
  const char *label;
  void (*callback)(Control, int);
  String value;
  unsigned int color;
} Control;

typedef enum EncoderTypes
{
  SLIDER_HORIZONTAL,
  SLIDER_VERTICAL,
  FADER,
  MULTIPOS_SWITCH
} EncoderType;


class PicoUI_RotaryEncoder
{
  public:
    PicoUI_RotaryEncoder();

    String label = String("Unnamed");
    EncoderType type = (EncoderType)FADER;

    int pin_a, pin_b;
    bool useAcceleration = false;
    float accelerationFactor = 0.5;

    float minValue = -64.0;
    float maxValue = 64.0;
    float stepSize = 0.1;

    int *callback = NULL;

  private:
    int _pin_a, _pin_b;

};

class PicoUI_Label
{
  PicoUI_Label();
  public:
    String label = String("Unnamed");
};

class PicoUI_Button
{
  PicoUI_Button();
  public:
    String label = String("Unnamed");
    int *callback = NULL;
};

class PicoUI_Switch
{
  PicoUI_Switch();
  public:
    String label = String("Unnamed");
    int *callback = NULL;

    bool defaultState = 0;
};

class PicoUI
{
  public:
    PicoUI();

    void addElement(PicoUI_RotaryEncoder element, int pos_x, int pos_y);
    void addElement(PicoUI_Label element, int pos_x, int pos_y);
    void addElement(PicoUI_Button element, int pos_x, int pos_y);
    void addElement(PicoUI_Switch element, int pos_x, int pos_y);

    void attachLCD(const OLED_SSD1306 *oled);

    void update();

  private:
    int _pin;
};
