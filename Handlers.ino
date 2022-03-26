void switchTuner() {
  tuner_state = !tuner_state;
  sendTunerState(tuner_state);
  printAt(6, 2, tuner_state);
  Serial.print("tuner:"); Serial.println(tuner_state);
}

void changeWahModel() {
  sendWahModel(wah_model.next());
  printAt(12, 3, wah_model.current());
  Serial.print("Wah model:"); Serial.println(wah_model.current());
}

void changeMicModel() {
  sendMicModel(mic_model.next());
  printAt(12, 2, mic_model.current());
  Serial.print("mic:"); Serial.println(mic_model.current());
}

void switchWah() {
  wah_state = !wah_state;
  sendWahState(wah_state);
  printAt(16, 3, wah_state);
  Serial.print("Wah state:"); Serial.println(wah_state);
}

void setWahPedal(uint8_t value) {
  if (wah_state) {
    sendWahPedal(value);
  }
}
