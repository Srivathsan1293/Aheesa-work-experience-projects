#include <stdio.h>
#include <stdlib.h>
#include <math.h>
          
// Function to allocate memory for a matrix
double** allocateMatrix(int degree) {
    double** matrix = (double**)malloc(degree * sizeof(double*));
    for (int i = 0; i < degree; i++) {
        matrix[i] = (double*)malloc(degree * sizeof(double));
    }
    return matrix;
}
void gaussElimination(double** matrix, double** inverse, int degree) {
    for (int i = 0; i < degree; i++) { //to cycle through every row
        double pivot = matrix[i][i]; //is the value in matrix, with the position where a 1 will be in identity matrix
        if (pivot == 0) { //check if it is 0, as will use it to divide later
            for (int k = i + 1; k < degree; k++) { //if it is 0, we trying to swap this row with the one below
                if (matrix[k][i] != 0) { 
                    for (int j = 0; j < degree; j++) {
                        double temp = matrix[i][j]; //swapping one element at a time in the row
                        matrix[i][j] = matrix[k][j];
                        matrix[k][j] = temp;

                        temp = inverse[i][j]; //copying the same action in indentity matrix
                        inverse[i][j] = inverse[k][j];
                        inverse[k][j] = temp;
                    }
                    pivot = matrix[i][i]; //updating pivot
                    break;
                }
            }
            if (pivot == 0) { // if the pivot is still 0, then an inverse can't be calculated
                printf("Matrix is singular and cannot be inverted\n");
                return;
            }
        }
        for (int j = 0; j < degree; j++) { //dividing every element in the row by the pivot, to make value at pivot position 1
            matrix[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }
        for (int k = 0; k < degree; k++) { // we are subtracting pivot row from other rows, in an effort to make values in the same column as pivot = 0
            if (k != i) {
                double factor = matrix[k][i]; //setting value that we want to become 0
                for (int j = 0; j < degree; j++) {
                    matrix[k][j] -= factor * matrix[i][j]; //multiplying and subtracting to ensure the factor value turns to 0, but the others are still non-zero. factor becomes 0, because the value in pivot position is 1 from previous division which is selected in first iteration of j loop. 
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }
}
int main() {
    int degree;
    double x;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    degree += 1;
    //intialising matrices, as 2d arrays
    double** matrix = allocateMatrix(degree);
    double** inverse = allocateMatrix(degree);
    //intialising vectors as 1d arrays
    double* y = (double*)malloc(degree * sizeof(double));
    double* result =  (double*)malloc(degree * sizeof(double));
    //gathering inputs
    for (int i = 0; i < degree; i++) {
      printf("Enter the coordinates:\n");
        scanf("%lf %lf", &x, &y[i]);
        for (int j = 0; j < degree; j++) { 
            matrix[i][(degree - 1) - j] = pow(x, j); //setting up matrix with X^n to X^0. 
            if (i == j) { //setting up inverse matrix
                inverse[i][j] = 1.0;
            } else {
                inverse[i][j] = 0.0;
            }
        }
    }
    gaussElimination(matrix, inverse, degree);
    //perform multiplication with vector by calculating the dot product between each row in the inverse matrix and the y coordinate vector
    for (int i = 0; i < degree; i++){
      for (int j = 0; j < degree; j++){
        result[i] += inverse[i][j] * y[j];
      }
    }
  printf("The coefficients are: \n");
    for (int i =0; i < degree; i++){
      printf("%.2lf ", result[i]);
    }
    return 0;
}
