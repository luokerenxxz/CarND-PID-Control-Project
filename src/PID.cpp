#include "PID.h"
#include <stddef.h>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;
  cte_sum = 0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  if (cte_prev == NULL)
  {
    cte_prev = cte;
  }

  p_error = cte;
  d_error = (cte - cte_prev);
  cte_prev = cte;
  i_error = cte_sum + cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return -Kp*p_error - Kd*d_error - Ki*i_error;  // TODO: Add your total error calc here!
}