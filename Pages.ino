/*
    CLICK_HANDLER,      // 5
    HOLDED_HANDLER,     // 6
    STEP_HANDLER,       // 7
    PRESS_HANDLER,      // 8
    CLICKS_HANDLER,     // 9
    RELEASE_HANDLER,    // 10
    HOLD_HANDLER,       // 11
 */

void mainPage() {
  handle_pedal();
  handle_knobs();
  handle_buttons();
}

void configureMainPage() {
  btn2.attach(CLICK_HANDLER, switchTuner);
  btn3.attach(CLICK_HANDLER, changeMicModel);
  pedal_btn.attach(PRESS_HANDLER, switchWah);
  ext_btn_down.attach(CLICK_HANDLER, changeWahModel);
  pedal_func = setWahPedal;
  for (int i = 0; i < 6; i++) {
    knob_funcs[i] = sendAmpParam;
  }
  renderMainPage();

  btn0.attach(PRESS_HANDLER, []() {
    printAt(0, 3, "X");
    Serial.println("btn0 pressed");
    });
  btn0.attach(RELEASE_HANDLER, []() {
    printAt(0, 3, " ");
    Serial.println("btn0 released");
    });
  btn1.attach(PRESS_HANDLER, [](){
    printAt(1, 3, "X");
    Serial.println("btn1 pressed");
    });
  btn1.attach(RELEASE_HANDLER, [](){
    printAt(1, 3, " ");
    Serial.println("btn1 released");
    });
  ext_btn_up.attach(PRESS_HANDLER, [](){
    printAt(2, 3, "X");
    Serial.println("ext_btn_up pressed");
    });
  ext_btn_up.attach(RELEASE_HANDLER, [](){
    printAt(2, 3, " ");
    Serial.println("ext_btn_up released");
    });
}

void renderMainPage() {
  lcd.clear();
  printAt(0, 0, "P1:--- P2:--- P3:---");
  printAt(0, 1, "P4:--- P5:--- P6:---");
  printAt(0, 2, "Tuner:- Mic:- W:    ");
  printAt(0, 3, "        Wah:- w:-   ");

  printAt(6, 2, tuner_state);
  printAt(12, 2, mic_model.current());

  printAt(12, 3, wah_model.current());
  printAt(16, 3, wah_state);

}

/*********************************************************************************/
void handle_buttons() {
  btn0.tick();
  btn1.tick();
  btn2.tick();
  btn3.tick();

  pedal_btn.tick(bitRead(ext_btn_data, 0));
  ext_btn_up.tick(bitRead(ext_btn_data, 1));
  ext_btn_down.tick(bitRead(ext_btn_data, 2));
}

/*********************************************************************************/
void read_external_module() {
  Wire.requestFrom(WAH_ADDR, 2);
  if (Wire.available()) {
    pedal_value = Wire.read();
    ext_btn_data = Wire.read();
  }
}

/*********************************************************************************/
void handle_pedal() {
  static uint8_t old_value = 255;
  if (old_value == pedal_value) return;
  old_value = pedal_value;
  pedal_func(pedal_value);
  printAt(16, 2, "   ");
  printAt(16, 2, pedal_value);
  Serial.print("Pedal value:"); Serial.println(pedal_value);
}

/*********************************************************************************/
void handle_knobs() {
  for(uint8_t i = 0; i < 6; i++) {
    int raw_value = analogRead(knobs[i]);
    raw_value = knob_filters[i].filtered(raw_value);

    uint8_t value = map(raw_value, 0, 1023, 0, 127);
    if (knob_values[i] == value) continue;

    knob_values[i] = value;
    knob_funcs[i](i, value);

    uint8_t delta = i < 3 ? i : (i - 3);
    uint8_t x = 3 + delta * 7;
    uint8_t y = i < 3 ? 0 : 1;
    
    printAt(x, y, "   ");
    printAt(x, y, value);

    Serial.print("Knob"); Serial.print(i); Serial.print(":"); Serial.println(value);
  }
}
