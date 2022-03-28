#include "Prescaler_Switch.h"


Prescaler_Switch::Prescaler_Switch(uint8_t ioPin, String switchMode, bool invert) {
  _ioPin = ioPin;
  _switchMode = switchMode;
  _invert = invert;
}


bool Prescaler_Switch::toggle() {
  state(!lastState);
}

bool Prescaler_Switch::state (bool state) {
  lastState = state;
  if (_invert) state = !state;
  if (_switchMode == "OC") {
    if (state) {
      pinMode(_ioPin, OUTPUT);
      digitalWrite(_ioPin, LOW);
    }
    else {
      pinMode(_ioPin, INPUT);
    }
  }
  else if (_switchMode == "OCPU") {
    if (state) {
      pinMode(_ioPin, OUTPUT);
      digitalWrite(_ioPin, LOW);
    }
    else {
      pinMode(_ioPin, INPUT_PULLUP);
    }
  }
  else if (_switchMode == "OE") {
    if (state) {
      pinMode(_ioPin, OUTPUT);
      digitalWrite(_ioPin, HIGH);
    }
    else {
      pinMode(_ioPin, INPUT);
    }
  }
  else { //switchMode = PP
    pinMode(_ioPin, OUTPUT);
    if (state) {
      digitalWrite(_ioPin, HIGH);
    }
    else {
      digitalWrite(_ioPin, LOW);
    }
  }
  return state;
}