#ifndef PID_DERIVADA_FILTRADA_H
#define PID_DERIVADA_FILTRADA_H

class PIDDerivadaFiltrada {
public:
  PIDDerivadaFiltrada(float kp, float ki, float kd, float dt, int N = 5);
  float compute(float setpoint, float measured);

private:
  float kp, ki, kd, dt, alpha_1, alpha_2;
  float integral, fd0, fd1;
  float error[3];
};

#endif
