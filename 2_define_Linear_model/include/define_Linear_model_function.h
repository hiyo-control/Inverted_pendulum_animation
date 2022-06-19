#ifndef DEFINE_LINEAR_MODEL_FUNCTION_H
#define DEFINE_LINEAR_MODEL_FUNCTION_H

/* Define global variable */
extern float A[4][4];
extern float B[4];

/* Define stucture */
struct parameter
{
    float mass;
    float length;
    float viscosity;
    float inertia;
};

void IP_linear_model(struct parameter rotor, struct parameter pendulum);

#endif