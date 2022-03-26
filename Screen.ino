template <typename T>
void printAt(uint8_t col, uint8_t row, const T data) {
  lcd.setCursor(col, row);
  lcd.print(data);
}


/*********************************************************************************/
void handle_lcd() {
  if (Serial.available()) {
    delay(100);
    RXLED0;
    TXLED0;
    lcd.clear();
    while (Serial.available() > 0) {
      lcd.write(Serial.read());
    }
    RXLED1;
    TXLED1;

    delay(50);
    RXLED0;
    TXLED0;
    delay(50);
    RXLED1;
    TXLED1;
  }
}
