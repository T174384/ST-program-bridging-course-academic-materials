#include <stdio.h>
typedef struct{
    double real;
    double imag;
} Complex;
int main() {
    Complex x, y, ans;
    double den;
    printf("Enter first complex number: ");
    scanf("%lf %lf", &x.real, &x.imag);
    printf("Enter second complex number: ");
    scanf("%lf %lf", &y.real, &y.imag);
    if (y.real == 0 && y.imag == 0) {
        printf("Division by zero error.\n");
        return 0;
    }
    den = y.real * y.real + y.imag * y.imag;
    ans.real = (x.real * y.real + x.imag * y.imag) / den;
    ans.imag = (x.imag * y.real - x.real * y.imag) / den;
    printf("Answer: %lf + %lfi\n", ans.real, ans.imag);
    return 0;
}