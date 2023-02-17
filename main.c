/**
 * @file            main.c
 * @author          Masoud Heidari (m.heidari92@gmail.com)
 * @brief           A simple Example of the poly library. 
 * @version         0.1
 * @date            2023-02-18
 * 
 * @copyright       Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "inc/poly.h"

int main()
{ 
    //double x[6] = {-3, -2, -1, -0.2, 1, 3};
    //double y[6] = {0.9, 0.8, 0.4, 0.2, 0.1, 0};
    //int len = 6;

    //An array of x values (Each value corresponds to the y value of the same index)
    double x[9] = {97.5, 122, 147.5, 173, 199, 218, 236.5, 253, 273};
    //An array of y values (Each value corresponds to the x value of the same index)
    double y[9] = {100, 125, 150.5, 176.5, 202, 227, 254.5, 278, 305};
    //Length of the x and y
    int len = 9;
    //Order of the polynomial. Change to any value in range of 0 ~ MAX_ORDER
    int order = 6;
    //Declaring an array for coefficients
    double P[order];
    //Calculate the coefficients. The return value should be checked to see if it is OK.
    int status = polyfit(P, x, y, order, len);
    if(status != STATUS_OK)
    {
        //Check the Error code
        printf("Error: %d\n", status);
        return 0;
    }
    //Display the coefficients
    for(int i=0; i<order+1; i++)
    {
        printf("P%i= %lf\n", i, P[i]);
    }

    //Now lets check if everything is ok.
    //By changing xIndex you can check if every x value in x array returns the desire y or not.
    //Every x value will be replaced to the equation (with calculated coefficients) to calculate the y
    int xIndex = 4;
    double res = 0.0;
    for(int i=order; i>=0; i--)
    {
        res = res + P[i]*pow(x[xIndex], i);
    }
    printf("x=%lf, y=%lf, result=%lf\n",x[xIndex], y[xIndex], res);
    //If everything was okay, the y value and the result value should be almost the same.
    return 0;
}