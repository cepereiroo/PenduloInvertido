#include "PIDFiltrollIR.h"

PIDFiltrollIR::PIDFiltrollIR(float kp, float ki, float kd, float dt) {
  a0 = kp + ki * dt + kd / dt;
  a1 = -kp - 2 * kd / dt;
  a2 = kd / dt;
  error[0] = error[1] = error[2] = 0;
}

float PIDFiltrollIR::compute(float setpoint, float measured) {
  error[2] = error[1];
  error[1] = error[0];
  error[0] = setpoint - measured;
  return a0 * error[0] + a1 * error[1] + a2 * error[2];
}
