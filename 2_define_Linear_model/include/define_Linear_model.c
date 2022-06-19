#include <stdio.h>
#include <math.h>

#include "define_Linear_model_function.h"

float A[4][4];
float B[4];

float g = 9.8;

void IP_linear_model(struct parameter r, struct parameter p)
{
    /* Define parameter */
    float mp     = p.mass;
    float lr     = r.length;
    float lp     = p.length;
    float dr     = r.viscosity;
    float dp     = p.viscosity;
    float Jr     = r.inertia;
    float Jp_sub = p.inertia;
    float Jp     = Jp_sub + mp * 0.5*lp * 0.5*lp;

    /* Define sub variable */
    float L1   = mp * lr * 0.5*lp;
    float L2   = Jr + mp * lr * lr;
    float L3   = mp * 0.5*lp * g;
    float detM = Jp*L2 - L1*L1;
    
    /* System matrix */
    A[0][0] = 0; A[0][1] = 0;           A[0][2] = 1;           A[0][3] = 0;
    A[1][0] = 0; A[1][1] = 0;           A[1][2] = 0;           A[1][3] = 1;
    A[2][0] = 0; A[2][1] = -L1*L3/detM; A[2][2] = -dr*Jp/detM; A[2][3] =  dp*L1/detM;
    A[3][0] = 0; A[3][1] =  L2*L3/detM; A[3][2] =  dr*L1/detM; A[3][3] = -dp*L2/detM;

    /* Input dstribute vector */
    B[0] = 0;
    B[1] = 0;
    B[2] =  Jp/detM;
    B[3] = -L1/detM;

    return;
}