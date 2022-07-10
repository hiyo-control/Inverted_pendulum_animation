#include <stdio.h>
#include <stdlib.h>
#include "./include/calc_Optimal_Linear_FB_vector.h"

int main(int argc, char *argv[])
{
    /* LQR parameter */
    float Q[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };

    float scale = atof(argv[1]);
    float R = 1*scale;

    /* Linear system of Inverted pendulum */
    float A[4][4] = {
        {0,   0  ,  1   ,  0     },
        {0,   0  ,  0   ,  1     },
        {0, -52.0, -1.35,  0.0853},
        {0,  96.7,  1.49, -0.159 },
    };

    float B[4] = {
        {0},
        {0},
        { 463},
        {-511},
    };

    /* Calculate Optimal Linear FB vector*/
    cpp_func::calc_Optimal_Linear_FB_vector(A, B, Q, R);
    float F[4];

    for (int i=0; i<4; i++){
        F[i] = cpp_func::F_cpp[i];
    }

    /* Display Optimal Linear FB vector */
    printf("Weight for Input R ---------------------------\n");
    printf("R=%s\n", argv[1]);
    printf("Optimal FB vector ---------------------------\n");
    printf("F[4] = \n");
    printf("[%f, %f, %f, %f] \n", F[0], F[1], F[2], F[3]);
    printf("\n");

    return 0;
}