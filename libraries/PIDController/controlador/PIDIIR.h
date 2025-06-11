#ifndef PID_FILTRO_IIR_H
#define PID_FILTRO_IIR_H

class PIDFiltrollIR {
public:
  PIDFiltrollIR(float kp, float ki, float kd, float dt);
  float compute(float setpoint, float measured);

private:
  float a0, a1, a2;
  float error[3];
};

#endif
