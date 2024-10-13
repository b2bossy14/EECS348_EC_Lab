#include <stdio.h>
#define SIZE 5

// prototypes
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int sumMatrix[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int productMatrix[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int transpose[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    // Hold results of sum, product, and transpsoe of matrices
    int sumMatrix[SIZE][SIZE];
    int productMatrix[SIZE][SIZE];
    int transposeMatrix_m1[SIZE][SIZE];  
    int transposeMatrix_m2[SIZE][SIZE];

    // Call functions to add and multiply matrices
    addMatrices(m1, m2, sumMatrix);
    multiplyMatrices(m1, m2, productMatrix);
    transposeMatrix(m1, transposeMatrix_m1);
    transposeMatrix(m2, transposeMatrix_m2);
    

    // Print the resulting sum, product, and transpore matrices using printMatrix function
    printf("\nSum of matrices:\n\n");
    printMatrix(sumMatrix);

    printf("\nProduct of matrices:\n\n");
    printMatrix(productMatrix);

    printf("\nTranspose of matrix m1:\n\n");
    printMatrix(transposeMatrix_m1);

    printf("\nTranspose of matrix m2:\n\n");
    printMatrix(transposeMatrix_m2);

    return 0;
}

// Function for adding two matrices
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int sumMatrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            sumMatrix[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function for multiplying two matrices
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int productMatrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            productMatrix[i][j] = 0;  // Initialize to zero to avoid random values in memory
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {

                productMatrix[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Function for transposing a matrix
void transposeMatrix(int matrix[SIZE][SIZE], int transpose[SIZE][SIZE]) {

    if (SIZE <= 0) {
        printf("Error: Invalid dimensions for transposition.\n");
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            transpose[j][i] = matrix[i][j];  
        }
    }
}


// Function to print the matrices
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


