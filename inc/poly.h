/**
 * @file            poly.h
 * @author          Masoud Heidari (m.heidari92@gmail.com)
 * @brief           Fit a polynomial p(x) = p[0] * x**deg + ... + p[deg] of degree 
 *                  deg to points (x, y). 
 *                  Returns an array of coefficients p that minimises the squared 
 *                  error in the order 0, 1, ..., deg-1, deg.          
 * @version         0.1
 * @date            2023-02-18
 * 
 * @copyright       Copyright (c) 2023
 * 
 */

#ifndef __POLY_H__
#define __POLY_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <math.h>
#include <stdio.h>

/**
 * @brief           Value should be more than 0 and less than 7. 
 *                  Otherwise the coefficients are not valid
 * 
 */
#define MAX_ORDER               6

/**
 * @brief           Error flags
 * 
 */
#define STATUS_OK               0
#define ERR_INVALID_ORDER       1



int polyfit(double* res, double* x, double* y, int order, int len);


#ifdef __cplusplus
}
#endif

#endif