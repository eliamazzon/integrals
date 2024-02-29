#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*! \file
    \brief Math functions header file
*/

/*! \brief Computes the output value of a polynomial.
    \param coeff Coefficients of the polynomial (pointer to).
    \param size Length of the coeff array.
    \param in The input value.
    \return The output value.

    The polynomial is structured as follows: coeff[0] + coeff[1]*x + ....
*/
float Polynomial(float *coeff, int size, float in) {
  int i;          /*!< Counter for loops */
  float out = 0.; /*!< Used as accumulator to compute the value of the function
                     given an input */
  float x = in;   /*!< To represent the different elements of the polynomial (x,
                     x^2, x^3,...) */

  out = coeff[0];
  for (i = 1; i < size; i++) {
    out += coeff[i] * x;
    x *= in; /* x^i */
  }

  return out;
}

/*! \brief Numerical integration according to the rectangular rule.
    \param values Points that set the equally spaced intervals (pointer to).
    \param size Length of the values array.
    \param stepsize The interval between two points.
    \param integ1 Integral computed using as reference the first point of each
   interval. \param integ2 Integral computed using as reference the second point
   of each interval.
*/
void Rectangular(float *values, int size, float stepsize, float *integ1,
                 float *integ2) {
  int i; /*!< Counter for loops */

  (*integ1) = 0.;
  (*integ2) = 0.;

  (*integ1) += stepsize * values[0];
  for (i = 1; i < (size - 1); i++) {
    (*integ1) += stepsize * values[i];
    (*integ2) += stepsize * values[i];
  }
  (*integ2) += stepsize * values[i];
}

/*! \brief Numerical integration according to the trapezoidal rule.
    \param values Points that set the equally spaced intervals (pointer to).
    \param size Length of the values array.
    \param stepsize The interval between two points.
    \return The computed integral.
*/
float Trapezoidal(float *values, int size, float stepsize) {
  int i; /*!< Counter for loops */

  float integ = 0.; /*!< Used as accumulator to compute the integral */
  float h =
      stepsize / 2.; /*!< To avoid dividing by 2 at each round of the loop */

  for (i = 0; i < (size - 1); i++)
    integ += h * (values[i + 1] + values[i]);

  return integ;
}
