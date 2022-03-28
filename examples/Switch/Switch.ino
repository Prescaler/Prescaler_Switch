#include <Prescaler_Switch.h>

Prescaler_Switch ledRed(33, "PP", 0);
Prescaler_Switch ledYellow(32, "PP", 0);
Prescaler_Switch ledGreen(23, "PP", 0);
Prescaler_Switch ledbuiltin(LED_BUILTIN, "OC", 0);

void setup() {
  Serial.begin(115200);
  delay(200);
}

void loop() {
  ledRed.toggle(); Serial.print("\nledRed HIGH");
  //delay(50);
  //ledRed.state(LOW); Serial.print(", ledRed LOW");
  delay(500);
  ledYellow.state(1); Serial.print("\nledYellow HIGH");
  delay(50);
  ledYellow.state(0); Serial.print(", ledYellow LOW");
  delay(500);
  ledGreen.state(1); Serial.print("\nledGreen HIGH");
  delay(50);
  ledGreen.state(0); Serial.print(", ledGreen LOW");
  delay(500);
  ledbuiltin.state(1); Serial.print("\nledbuiltin HIGH");
  delay(50);
  ledbuiltin.toggle(); Serial.print("\nledbuiltin toggle \n");
  delay(500);
}