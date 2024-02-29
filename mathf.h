#ifndef MATHF_H
#define MATHF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*! \file mathf.h
    \brief Header file containing mathematical functions.
*/

/*! \brief Computes the output value of a polynomial.
    \param coeff Pointer to the coefficients of the polynomial.
    \param size Length of the coeff array.
    \param in The input value.
    \return The output value of the polynomial.

    The polynomial is structured as follows: coeff[0] + coeff[1]*x + ...
*/
float Polynomial(float *coeff, int size, float in);

/*! \brief Computes numerical integration using the rectangular rule.
    \param values Pointer to the points defining equally spaced intervals.
    \param size Length of the values array.
    \param stepsize The interval between two points.
    \param integ1 Pointer to store the integral computed using the first point
   of each interval. \param integ2 Pointer to store the integral computed using
   the second point of each interval.
*/
void Rectangular(float *values, int size, float stepsize, float *integ1,
                 float *integ2);

/*! \brief Computes numerical integration using the trapezoidal rule.
    \param values Pointer to the points defining equally spaced intervals.
    \param size Length of the values array.
    \param stepsize The interval between two points.
    \return The computed integral.
*/
float Trapezoidal(float *values, int size, float stepsize);

#endif /* MATHF_H */
