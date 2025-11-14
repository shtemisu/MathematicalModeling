#include <stdio.h>
#include <stdlib.h>

void right_runthrough(int n, double *A, double *B, double *C, double *F, double *x) {
    double *alpha = (double*)malloc((n) * sizeof(double));
    double *beta = (double*)malloc((n) * sizeof(double));

    alpha[0] = B[0] / C[0];
    beta[0] = F[0] / C[0];
    for (int i = 1; i <= n - 1; i++) {
        double num = C[i] - A[i] * alpha[i-1];
        alpha[i] = B[i] / num;
        
    }
    for (int i = 1; i <= n; i++) {
        double num = C[i] - A[i] * alpha[i-1];
        beta[i] = (F[i] + A[i]* beta[i-1]) / num;
    }
    x[n] = beta[n];
    for(int i = n - 1 ; i >= 0; i--) {
       x[i] = alpha[i] * x[i+1] + beta[i]; 

    }
    free(alpha);
    free(beta);
}
void left_runthrough(int n, double *A, double *B, double *C, double *F, double *x) {
    double *alpha = (double*)malloc((n) * sizeof(double));
    double *beta = (double*)malloc((n) * sizeof(double));
    alpha[n] = A[n]/C[n];
    beta[n] = F[n]/C[n];
    
    for(int i = n - 1; i > 2; i--) {
        double num = C[i] - B[i] * alpha[i+1];
        alpha[i] = A[i] / num;
    }
    for(int i = n - 1; i > 1; i--) {
        double num = C[i] - B[i] * alpha[i+1];
        beta[i] = (F[i] + B[i] * beta[i+1])/ num;
    }
    x[0] = beta[0];

    for(int i = 1; i < n; i++) {
        x[i] = alpha[i] * x[i-1] + beta[i];
    }

}


int main() {
    double A[] = {0,3,1,4,1,-2};
    double B[] = {-1,-2,2,1,2,0};
    double C[] = {-2,-6,5,7,-5,-7};
    double F[] = {-1,-9,-3,6,-8,-5};
    int n = 6;
    double *x_right = (double*)malloc(n * sizeof(double));
    double *x_left = (double*)malloc(n * sizeof(double));
    printf("Вариант 7:\n\nМетод правой прогонки\n\n");
    right_runthrough(n, A, B,C, F, x_right);
    for(int i = 0; i < n; i++) {
        printf("x[%d] = %.2lf\n",i+1, x_right[i]);
    }
    printf("\nМетод левой прогонки\n\n");
    left_runthrough(n, A, B,C, F, x_left);
    for(int i = 0; i < n; i++) {
        printf("x[%d] = %.2lf\n",i+1, x_right[i]);
    }
    return 0;
}