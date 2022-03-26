#ifndef _CycleVaram_h
#define _CycleVaram_h

class CycleValue {
  public:
    CycleValue(uint8_t total) {
      this->total = total;
    }

    uint8_t current() {
      return value;
    }

    uint8_t next() {
      if (value < total - 1) value++;
      else value = 0;
      return value;
    }

  private:
    uint8_t total = 1;
    uint8_t value = 0;
};

#endif
