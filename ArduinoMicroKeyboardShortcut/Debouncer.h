#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#define DEBOUNCER_SIZE 5

enum ButtonState {
  BUT_UP,
  BUT_PRESSED,
  BUT_DOWN,
  BUT_RELEASED
};



class Debouncer {
  private : 
  uint8_t _pin;
  uint8_t _raw[DEBOUNCER_SIZE];
  uint8_t _rawIndex;
  uint8_t _curDigitalValue;
  uint8_t _preDigitalValue;

  public :
  Debouncer(){}
  Debouncer(uint8_t pin) : _pin(pin), _rawIndex(0), _curDigitalValue(HIGH), _preDigitalValue(HIGH){
    pinMode(_pin, INPUT_PULLUP);
    for(uint8_t i = 0; i < DEBOUNCER_SIZE; i++) {
      _raw[i] = HIGH;
    }
  }
  
  ButtonState updateAndGetState() {
    _rawIndex++;
    if(_rawIndex >= DEBOUNCER_SIZE) _rawIndex = 0;
    _raw[_rawIndex] = digitalRead(_pin);
    uint16_t sum = 0;
    for(uint8_t i = 0; i < DEBOUNCER_SIZE; i++) {
      sum += _raw[i];
    }
    _curDigitalValue = sum / (DEBOUNCER_SIZE * HIGH);

    ButtonState state = BUT_UP;
    if(_curDigitalValue == HIGH && _preDigitalValue == HIGH) {
      state = BUT_UP;
    }
    if(_curDigitalValue == LOW && _preDigitalValue == HIGH) {
      state = BUT_PRESSED;
    }
    if(_curDigitalValue == LOW && _preDigitalValue == LOW) {
      state = BUT_DOWN;
    }
    if(_curDigitalValue == HIGH && _preDigitalValue == LOW) {
      state = BUT_RELEASED;
    }
    _preDigitalValue = _curDigitalValue;
    return state;
  }
};

#endif // DEBOUNCER_H
