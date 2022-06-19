#include <stdio.h>
#include <math.h>

#include "./include/define_Linear_model_function.h"

int main(int argc, char *argv[])
{
    /* Define parameter by structure */
    struct parameter rotor   ;
    struct parameter pendulum;

    printf("%s\n", argv[1]);
    rotor.mass      = 0.057;
    rotor.length    = 0.137*2;
    rotor.viscosity = 2.919*pow(10,-3);
    rotor.inertia   = 2.67 *pow(10,-4);

    pendulum.mass      = 0.067;
    pendulum.length    = 0.155*2;
    pendulum.viscosity = 1.671*pow(10,-4);
    pendulum.inertia   = 0.971*pow(10,-3);

    /* Calculare Linear model of Inverted pendulum */
    IP_linear_model(rotor, pendulum);

    /* Display Linear model */
    printf("System Matrix of Inverted Pendulum ------------------\n");
    printf("A[4][4]=\n");
    printf("[%f, %f, %f, %f] \n", A[0][0], A[0][1], A[0][2], A[0][3]);
    printf("[%f, %f, %f, %f] \n", A[1][0], A[1][1], A[1][2], A[1][3]);
    printf("[%f, %f, %f, %f] \n", A[2][0], A[2][1], A[2][2], A[2][3]);
    printf("[%f, %f, %f, %f] \n", A[3][0], A[3][1], A[3][2], A[3][3]);
    printf("\n");

    /* Display Linear model */
    printf("Input destribute vector of Inverted Pendulum --------\n");
    printf("B[4]=\n");
    printf("[%f] \n", B[0]);
    printf("[%f] \n", B[1]);
    printf("[%f] \n", B[2]);
    printf("[%f] \n", B[3]);
}
