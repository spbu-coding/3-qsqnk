#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

void calculate_in_float() {
    float err = 0.0001f;
    float x2 = (0.0001f + err) / (0.0001f);
    float x1 = 2.000f - x2;
    float distance = sqrtf((x2 - 1) * (x2 - 1) + (x1 - 1) * (x1 - 1));
    int count = 0;
    while (distance >= EPSILON) {
        err /= 2;
        x2 = (0.0001f + err) / (0.0001f);
        x1 = 2.000f - x2;
        distance = sqrtf((x2 - 1) * (x2 - 1) + (x1 - 1) * (x1 - 1));
        count++;
    }
    printf("err in float: %.30f\n", err);
    printf("count of iterations in float: %d\n", count);
}

void calculate_in_double() {
    double err = 0.0001;
    double x2 = (0.0001 + err) / (0.0001);
    double x1 = 2.000 - x2;
    double distance = sqrt((x2 - 1) * (x2 - 1) + (x1 - 1) * (x1 - 1));
    int count = 0;
    while (distance >= EPSILON) {
        err /= 2;
        x2 = (0.0001 + err) / (0.0001);
        x1 = 2.000 - x2;
        distance = sqrt((x2 - 1) * (x2 - 1) + (x1 - 1) * (x1 - 1));
        count++;
    }
    printf("err in double: %.30lf\n", err);
    printf("count of iterations in double: %d\n", count);
}

int main() {
    calculate_in_double();
    calculate_in_float();
    return 0;
}
