#include <Keyboard.h>
#include "KeypadCodes.h"
#include "KeyboardMacro.h"



// TODO : 
// [X] Parallel inputs readings
// [X] Filter inputs
// [ ] Add more shortcuts

#define NB_MACROS 15

KeyboardMacro macros[NB_MACROS] = {
  KeyboardMacro( 5, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]){KEYPAD_0, KEYPAD_1, KEYPAD_8, KEYPAD_3}), 4), // '·' / Interpunct / point médian
  KeyboardMacro( 7, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]){KEYPAD_9, KEYPAD_6}), 2),                     // '`' / Grave accent / Accent grave (Markdown code)
  KeyboardMacro( 9, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]){KEYPAD_1, KEYPAD_6, KEYPAD_8}), 3),           // '¿'
  KeyboardMacro(10, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]){KEYPAD_1, KEYPAD_7, KEYPAD_3}), 3),           // '¡'
  KeyboardMacro(15, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]){KEYPAD_0, KEYPAD_1, KEYPAD_5, KEYPAD_6}), 4), // 'œ'
  
  KeyboardMacro( 4, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]){KEYPAD_2, KEYPAD_4}), 2),                     // '↑'
  KeyboardMacro( 8, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]){KEYPAD_2, KEYPAD_5}), 2),                     // '↓'
  KeyboardMacro(16, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]){KEYPAD_2, KEYPAD_6}), 2),                     // '→'
  KeyboardMacro(14, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]){KEYPAD_2, KEYPAD_7}), 2),                     // '←'
  KeyboardMacro(A0, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]){KEYPAD_1, KEYPAD_8}), 2),                     // '↕'
  
  KeyboardMacro( 3, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]) {KEYPAD_1}), 1),                              // '☺'
  KeyboardMacro( 2, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]) {KEYPAD_1, KEYPAD_1}), 2),                    // '♂'
  KeyboardMacro(A3, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]) {KEYPAD_1, KEYPAD_2}), 2),                    // '♀'
  KeyboardMacro(A2, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]) {KEYPAD_1, KEYPAD_4}), 2),                    // '♫'
  KeyboardMacro(A1, ((uint8_t[]) {KEY_LEFT_ALT}), 1, ((uint8_t[]) {KEYPAD_1, KEYPAD_5}), 2),                    // '☼'
};


void setup() {
  Keyboard.begin();
}


void loop() {
  for(uint8_t i = 0; i < NB_MACROS; i++) {
    macros[i].update();
  }
}
