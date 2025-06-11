#include <PIDDerivadaFiltrada.h>

PIDDerivadaFiltrada pid(2.0, 0.5, 1.0, 0.01, 10); // N=10

void setup() {
  Serial.begin(115200);
}

void loop() {
  float setpoint = 100.0;
  float sensor = analogRead(34);
  float output = pid.compute(setpoint, sensor);

  analogWrite(5, constrain(output, 0, 255));
  Serial.println(output);
  delay(10);
}
