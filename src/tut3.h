#ifndef TUT3_H
#define TUT3_H

/**
 * Compares <code>x</code> and <code>y</code>, and returns the largest value.
 * If the two values are equal, then either <code>x</code> or <code>y</code> may
 * be returned.
 *
 * @param[in]  x  the first value to compare
 * @param[in]  y  the second value to compare
 * @return     the largest value of the given inputs
 */
int max(int x, int y);

/**
 * Computes <code>x</code> to the power of <code>n</code>, where both parameter
 * values are assumed to be nonnegative.
 *
 * @param[in]  x  the base, assumed to be greater than or equal to zero
 * @param[in]  n  the exponent, assumed to be greater than or equal to zero
 * @return     <code>x</code> to the power of <code>n</code>
 */
int power(int x, int n);

/**
 * Returns the greatest common divisor of the two parameter values, both of
 * which are assumed to be positive.
 *
 * @param[in]  a  the first value, assumed to be greater than zero
 * @param[in]  b  the second value, assumed to be greater than zero
 * @return     the GCD of the two parameter values
 */
int gcd(int a, int b);

#endif /* TUT3_H */
