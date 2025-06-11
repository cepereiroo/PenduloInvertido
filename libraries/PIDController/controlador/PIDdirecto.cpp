#include "PIDBasico.h"

PIDBasico::PIDBasico(float kp_, float ki_, float kd_, float dt_)
  : kp(kp_), ki(ki_), kd(kd_), dt(dt_), integral(0), prev_error(0) {}

float PIDBasico::compute(float setpoint, float measured) {
  float error = setpoint - measured;
  integral += error * dt;
  float derivative = (error - prev_error) / dt;
  prev_error = error;
  return kp * error + ki * integral + kd * derivative;
}
