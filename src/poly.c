/**
 * @file            poly.c
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

#include "poly.h"

double sigma(int start, int end, double* arr, int power);
double determinant(int order, double matBase[order][order]);

/**
  * @brief           Fit a polynomial p(x) = p[0] * x**deg + ... + p[deg] of degree 
 *                  deg to points (x, y). 
 *                  Returns an array of coefficients p that minimises the squared 
 *                  error in the order 0, 1, ..., deg-1, deg.
 * 
 * @param p         Pointer to an array for returning the coefficients
 * @param x         An array of x values
 * @param y         An array of y values
 * @param order     The degree of the polynomial (0 ~ MAX_ORDER)
 * @param len       The lenght of the x and y (both should have same sizes) 
 * @return int      Return status 
 */
int polyfit(double* p, double* x, double* y, int order, int len)
{
    order++;
    double mat[order][order];  
    double mat0[order][order];
    double matY[order];

    if(order > MAX_ORDER+1)
    {
        return ERR_INVALID_ORDER;
    }
    for(int i=0; i<order; i++)
    {
        double pMatY = 0.0;
        for(int j=0; j<len; j++)
        {
            pMatY = pMatY + pow(x[j], i)*y[j];
        }
        matY[i] = pMatY;
    }

    for(int i=0; i<order; i++)
    {
        for(int j=0; j<order; j++)
        {
            mat[i][j] = sigma(0 , len, x, i+j);
        }
    }

    for(int k=0; k<order; k++)
    {
        for(int i=0; i<order; i++)
        {
            for(int j=0; j<order; j++)
            {
                mat0[i][j] = mat[i][j];
            }
            mat0[i][k] = matY[i];        
        }
        p[k] = determinant(order, mat0)/determinant(order, mat);
    }
    return STATUS_OK;
}

/**
 * @brief           Calculate the sigma of an array with the given power       
 * 
 * @param start     Start point of the sigma (should be greater than 0) 
 * @param end       End point of the sigma  (should not exceed the array length) 
 * @param arr       An array that consists the values 
 * @param power     The power of the array's values     
 * @return double   Return the sigma value 
 */
double sigma(int start, int end, double* arr, int power)
{
    double res = 0.0;

    for(int i=start; i<end; i++)
    {
        res = res + pow(arr[i], (double)power);
    }
    return res;
}
  
/**
 * @brief           Calculate the determinant of the given matrix.
 * 
 * @param order     Order of the matrix (ex: 3*3 (order=3), 4*4 (order=4), ...) 
 * @param matBase   The matrix for calculating its determinant. 
 * @return double   Return the determinant 
 */
double determinant(int order, double matBase[order][order])
{
    double res = 1.0;
    double ratio = 0.0;
    double mat[order][order];
    
    for(int i=0; i<order; i++)
    {
        for(int j=0; j<order; j++)
            mat[i][j] = matBase[i][j];
    }

    for(int i=0; i<order; i++)
    {
        if(mat[i][i] == 0.0)
        {
            printf("Mathematical Error!");  
            return 0.0;
        }
        for(int j=i+1; j<order; j++)
        {
            ratio = mat[j][i]/mat[i][i];
            for(int k=0; k<order; k++)
            {
                mat[j][k] = mat[j][k] - ratio*mat[i][k]; 
            }
        }
    }
    for(int i=0; i<order; i++)
    {
        res = res * mat[i][i];
    }
    return res;
}