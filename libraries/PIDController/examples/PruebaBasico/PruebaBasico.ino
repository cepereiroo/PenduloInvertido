#include <PIDBasico.h>

PIDBasico pid(2.0, 0.5, 1.0, 0.01); // Kp, Ki, Kd, dt

void setup() {
  Serial.begin(115200);
}

void loop() {
  float setpoint = 100.0;
  float sensor = analogRead(34);  // Entrada A0 en ESP32
  float output = pid.compute(setpoint, sensor);

  analogWrite(5, constrain(output, 0, 255)); // PWM en pin 5
  Serial.println(output);
  delay(10);
}
