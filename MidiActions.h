#ifndef _MidiActions_h
#define _MidiActions_h

/*********************************************************************************/
// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).
/*********************************************************************************/
void controlChange(uint8_t channel, uint8_t control, uint8_t value) {
  midiEventPacket_t event = {0x0B, (uint8_t) (0xB0 | channel), control, value};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}
/*********************************************************************************/
// For 14-bit values
/*********************************************************************************/
void controlChange(uint8_t channel, uint8_t controlMsb, uint8_t controlLsb, int value) {
  const uint8_t ch = 0xB0 | channel;
  midiEventPacket_t event = {0x0B, ch, controlMsb, (uint8_t) (value >> 7)};
  MidiUSB.sendMIDI(event);
  event = {0x0B, ch, controlLsb, (uint8_t) (value && 127)};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}

/*********************************************************************************/
// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).
/*********************************************************************************/
void noteOn(uint8_t channel, uint8_t pitch, uint8_t velocity) {
  midiEventPacket_t noteOn = {0x09, uint8_t(0x90 | channel), pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
  MidiUSB.flush();
}
/*********************************************************************************/
void noteOff(uint8_t channel, uint8_t pitch, uint8_t velocity) {
  midiEventPacket_t noteOff = {0x08, uint8_t(0x80 | channel), pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
  MidiUSB.flush();
}

/*********************************************************************************/
void printMidiRx() {
  midiEventPacket_t rx = MidiUSB.read();
  if (rx.header == 0) return;

  Serial.print("RX: ");
  Serial.print(rx.header, HEX);
  Serial.print("-");
  Serial.print(rx.byte1, HEX);
  Serial.print("-");
  Serial.print(rx.byte2, HEX);
  Serial.print("-");
  Serial.println(rx.byte3, HEX);
}

#endif
