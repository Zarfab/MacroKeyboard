#ifndef KEYBOARD_MACRO_H
#define KEYBOARD_MACRO_H

#include "Debouncer.h"
#include "KeypadCodes.h"

class KeyboardMacro {
  private :
  bool _isInit;
  Debouncer _deb;
  uint8_t* _macro;
  size_t _macroSize;
  uint8_t* _modifiers;
  size_t _modifiersSize;

  public :
  KeyboardMacro() : _isInit(false) {}
  KeyboardMacro(uint8_t pin, const uint8_t* modifiers, const size_t modifiersSize, const uint8_t* macro, const size_t macroSize) :
  _modifiersSize(modifiersSize), _macroSize(macroSize)
  {
    _deb = Debouncer(pin);
    _macro = (uint8_t*) malloc(_macroSize);
    memcpy(_macro, macro, _macroSize);
    _modifiers = (uint8_t*) malloc(_modifiersSize);
    memcpy(_modifiers, modifiers, _modifiersSize);
    _isInit = true;
  }

  ~KeyboardMacro() {
    free(_macro);
    free(_modifiers);
  }

  void update() {
    if(!_isInit) return;
    
    ButtonState state = _deb.updateAndGetState();
    if(state == BUT_PRESSED) {
      for(uint8_t i = 0; i < _modifiersSize; i++) {
        Keyboard.press(_modifiers[i]);
        delay(20);
      }
      for(uint8_t i = 0; i < _macroSize; i++) {
        Keyboard.press(_macro[i]);
        delay(20);
        Keyboard.release(_macro[i]);
        delay(20);
      }
      Keyboard.releaseAll();
      delay(100);
    }
  }
};

#endif // KEYBOARD_MACRO_H
