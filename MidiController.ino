// Buttons timings
#define EB_DEB 50      // дебаунс кнопки, мс
#define EB_HOLD 1000   // таймаут удержания кнопки, мс
#define EB_STEP 500    // период срабатывания степ, мс
#define EB_CLICK 400   // таймаут накликивания, мс

#include <MIDIUSB.h>
#include <EncButton.h>
#include <GyverFilters.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include "Connections.h"
#include "CycleValue.h"
#include "Line6Actions.h"

/*********************************************************************************/
LiquidCrystal_I2C lcd(0x27, 20, 4);

EncButton<EB_CALLBACK, BTN0> btn0;
EncButton<EB_CALLBACK, BTN1> btn1;
EncButton<EB_CALLBACK, BTN2> btn2;
EncButton<EB_CALLBACK, BTN3> btn3;
EncButton<EB_CALLBACK, VIRT_BTN> pedal_btn;
EncButton<EB_CALLBACK, VIRT_BTN> ext_btn_up;
EncButton<EB_CALLBACK, VIRT_BTN> ext_btn_down;

GMedian<10, int> pedal_filter;
GMedian<10, int> knob_filters[6];

CycleValue wah_model(WAH_MODEL_TOTAL);
CycleValue mic_model(MIC_MODEL_TOTAL);

uint8_t knobs[] = {KNOB0, KNOB1, KNOB2, KNOB3, KNOB4, KNOB5};
uint8_t knob_values[] = {255, 255, 255, 255, 255, 255};
void (*knob_funcs[6]) (uint8_t, uint8_t);

uint8_t ext_btn_data = 255;
uint8_t pedal_value = 255;
void (*pedal_func) (uint8_t);

uint8_t wah_state = 0;
uint8_t tuner_state = 0;

enum { MAIN, SETUP } state;

/*********************************************************************************/
void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 6; i++) {
    pinMode(knobs[i], INPUT);
  }
  lcd.init();
  lcd.backlight();
  lcd.noCursor();

  state = MAIN;
  configureMainPage();
}

/*********************************************************************************/
void loop() {
  read_external_module();

  switch(state) {

    case MAIN: {
      mainPage();
      break;
    }

    case SETUP: {
      break;
    }

    default: {
      state = MAIN;
    }
  
  }
}
