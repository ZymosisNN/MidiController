/*********************************************************************************/
void printBits(uint8_t b) {
  for(int i = 7; i >= 0; i--)
    Serial.print(bitRead(b, i));
}


/*********************************************************************************/
//#include <stdio.h>
//static int serial_fputchar(const char ch, FILE *stream) { Serial.write(ch); return ch; }
//static FILE *serial_stream = fdevopen(serial_fputchar, NULL);
//void __setup(void) {
//    stdout = serial_stream; // эта строка первая в setup
//    // А ТЕПЕРЬ ТУПО ПОЛЬЗУЕМСЯ printf
////    Serial.begin(115200);
//    int a = 28;
//    printf("a=%d, a=%03d, a=%04d, a=%05d, a=%06d\n", a, a, a, a, a);
//    printf("a=%d, a=%03x, a=%04x, a=%05x, a=%06x\n", a, a, a, a, a);
//    printf("a=%d, a=%03X, a=%04X, a=%05X, a=%06X\n", a, a, a, a, a);
//}
