/*switchMode: OC, OCPU, OE, PP
   OC = Open Collector = OpenSource
   OCPU = Open Collector with internal PullUp resistor
   OE = Open Emitter = OpenDrain
   PP = PushPull
*/

class Switch
{
  private:
    const byte ioPin;
    String switchMode;
    bool invert;

  public:
    Switch(byte ioPin, String switchMode, bool invert):
      ioPin{ioPin},
      switchMode{switchMode},
      invert{invert}
    {}

    bool lastState;

    bool toggle() {
      state(!lastState);

    }
    bool state (bool state) {
      lastState = state;
      if (invert) state = !state;
      if (switchMode == "OC") {
        if (state) {
          pinMode(ioPin, OUTPUT);
          digitalWrite(ioPin, LOW);
        }
        else {
          pinMode(ioPin, INPUT);
        }
      }
      else if (switchMode == "OCPU") {
        if (state) {
          pinMode(ioPin, OUTPUT);
          digitalWrite(ioPin, LOW);
        }
        else {
          pinMode(ioPin, INPUT_PULLUP);
        }
      }
      else if (switchMode == "OE") {
        if (state) {
          pinMode(ioPin, OUTPUT);
          digitalWrite(ioPin, HIGH);
        }
        else {
          pinMode(ioPin, INPUT);
        }
      }
      else { //switchMode = PP
        pinMode(ioPin, OUTPUT);
        if (state) {
          digitalWrite(ioPin, HIGH);
        }
        else {
          digitalWrite(ioPin, LOW);
        }
      }
      return state;
    }
};
