#ifndef Prescaler_Switch_h
#define Prescaler_Switch_h

#include <Arduino.h>



class Prescaler_Switch{
	  public:
	  Prescaler_Switch(uint8_t ioPin, String switchMode, bool invert);
	  bool toggle();
	  bool state(bool state);
	  bool lastState;
	
	
	  
	  private:
    uint8_t ioPin;
    String switchMode;
    bool invert;
	uint8_t _ioPin;
    String _switchMode;
    bool _invert;
};
#endif