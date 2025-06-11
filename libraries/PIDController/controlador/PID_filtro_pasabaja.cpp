#include "PIDDerivadaFiltrada.h"

PIDDerivadaFiltrada::PIDDerivadaFiltrada(float kp_, float ki_, float kd_, float dt_, int N)
  : kp(kp_), ki(ki_), kd(kd_), dt(dt_), integral(0), fd0(0), fd1(0) {
  error[0] = error[1] = error[2] = 0;
  float tau = kd / (kp * N);
  float alpha = dt / (2 * tau);
  alpha_1 = alpha / (alpha + 1);
  alpha_2 = (alpha - 1) / (alpha + 1);
}

float PIDDerivadaFiltrada::compute(float setpoint, float measured) {
  error[2] = error[1];
  error[1] = error[0];
  error[0] = setpoint - measured;

  integral += error[0] * dt;

  float deriv_raw = (error[0] - error[2]) / (2 * dt);
  fd1 = fd0;
  fd0 = alpha_1 * deriv_raw + alpha_2 * fd1;

  return kp * error[0] + ki * integral + kd * fd0;
}
