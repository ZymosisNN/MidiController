#ifndef _Line6Actions_h
#define _Line6Actions_h

#define LINE6_CHANNEL 1

#define TUNER_ENABLE    69

#define WAH_ENABLE 43
#define WAH_LEVEL 4
#define WAH_MODEL 91
#define WAH_MODEL_TOTAL 8

#define VOLUME_PEDAL_LEVEL     7
#define VOLUME_PEDAL_MIN       46
#define VOLUME_PEDAL_PRE_POST  47  //0~63 = Pre-Amp, 64~127 = Post-Amp

#define AMP_PARAM1  13
#define AMP_PARAM2  14
#define AMP_PARAM3  15
#define AMP_PARAM4  16
#define AMP_PARAM5  21
#define AMP_PARAM6  17

#define MIC_MODEL        70 // 0-3
#define MIC_MODEL_TOTAL  4

#define AMP_MODEL_BANK_SELECT  66 // The setting of this control determines how CC 12 messages (Amp Model Select) will be interpreted. 0=load model from Guitar Amp Model set; 1=load model from Bass Amp Model set; 2=Preamps
#define AMP_MODEL_SELECT       12
#define CAB_MODEL_BANK_SELECT  67  // 0 - Guitar, 1 - Bass
#define CABINET_MODEL_SELECT   71
#define CAB_EARLY_REFLECTIONS  76

#define STOMP_ENABLE        25
#define STOMP_PARAM2        79
#define STOMP_PARAM3        80
#define STOMP_PARAM4        81
#define STOMP_PARAM5        82
#define STOMP_PARAM6        83
#define STOMP_PRE_POST      74 // 0-63: pre-amp, 64-127: post-amp
#define STOMP_MODEL_SELECT  75

#include "midiActions.h"

const uint8_t ampParams[] = {AMP_PARAM1, AMP_PARAM2, AMP_PARAM3, AMP_PARAM4, AMP_PARAM5, AMP_PARAM6};

/*********************************************************************************/
void cc(uint8_t control, uint8_t value) {
  controlChange(LINE6_CHANNEL, control, value);
  delay(2);
}
void cc(uint8_t controlMsb, uint8_t controlLsb, int value) {
  controlChange(LINE6_CHANNEL, controlMsb, controlLsb, value);
  delay(2);
}
uint8_t on_off(uint8_t value) {
  return value ? 127 : 0;
}

/*********************************************************************************/
void sendWahState(uint8_t value) {
  cc(WAH_ENABLE, on_off(value));
}
void sendWahPedal(uint8_t value) {
  cc(WAH_LEVEL, value);
}
void sendWahModel(uint8_t value) {
  cc(WAH_MODEL, value);
}

void sendMicModel(uint8_t value) {
  cc(MIC_MODEL, value);
}

void sendAmpBank(uint8_t value) {
  cc(AMP_MODEL_BANK_SELECT, value);
}

void sendAmpParam(uint8_t n, uint8_t value) {
//  Serial.print("AMP param "); Serial.print(n); Serial.print(" value "); Serial.println(value);
  cc(ampParams[n], value);
}

void sendStomp(uint8_t value) {
  cc(STOMP_ENABLE, on_off(value));
}

void sendTunerState(uint8_t value) {
  cc(TUNER_ENABLE, on_off(value));
}

#endif
