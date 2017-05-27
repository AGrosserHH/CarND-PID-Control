#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {     
    
  /*
  * Errors
  */
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  
  cte_prev = 0.0;
  
  /*
  * Coefficients
  */ 
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  
}

void PID::UpdateError(double cte) {   
    
    p_error = cte;
    d_error = cte - cte_prev;
    i_error=i_error+cte;
    
    cte_prev = cte;    
}

double PID::TotalError() {
    
    return -Kp*p_error- Ki*i_error-Kd*d_error;
    
}

