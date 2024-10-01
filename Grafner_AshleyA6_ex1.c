//Ashley Grafner
//10/1/2024
//CS 2060

/* Question 1:
Create one 2-D array of 3x10
2nd Array with numbers using first 2 numbers in rows forming Fibonacci series
a. Display the sum of two arrays (A+B)
b. Display Transpose Array of B
c. Display the product of A and transpose of B
*/


#include <stdio.h>

// Macros for 2-D array of 3x10 size:
#define ROWS 3
#define COLS 10

// Macro to fill array A with values from 1 to 30
#define INIT_A(arr) \
    int a_vales[] = {  \
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,  \
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, \
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30  \
    }; \
    for (int i = 0; i < ROWS; i++)  \
        for (int j = 0; j < COLS; j++) \
            arr[i][j] = a_vales[i * COLS + j]; \

// Macro to fill array B with the Fibonacci-like values you provided
#define INIT_B(arr) \
    int b_vales[] = {   \
        1, 2, 3, 5, 8, 13, 21, 34, 55, 89,   \
        11, 12, 23, 35, 58, 93, 151, 244, 395, 639, \
        21, 22, 43, 65, 108, 173, 281, 454, 735, 1189  \
    };  \
    for (int i = 0; i < ROWS; i++) \
        for (int j = 0; j < COLS; j++) \
            arr[i][j] = b_vales[i * COLS + j]; \

// Macro to display the sum of two arrays A and B
#define DISPLAY_SUM(A, B)  \
    printf("Sum of arrays A and B:\n"); \
    for (int i = 0; i < ROWS; i++) {  \
        for (int j = 0; j < COLS; j++)   \
            printf("%d ", A[i][j] + B[i][j]);  \
        printf("\n"); \
    } \

//Macro to display the transpose of B  (B^T)
#define DISPLAY_TRANSPOSE(B)  \
    printf("Transpose of array B:\n"); \
    for (int j = 0; j < COLS; j++) {  \
        for (int i = 0; i < ROWS; i++) {  \
            printf("%d ", B[i][j]);  \
} \
        printf("\n");  \
} \


// Macro to display the product of array A and transpose of B B (A * B^T):
#define DISPLAY_PRODUCT(A, B) \
    printf("Product of A and transpose of B:\n"); \
    for (int i = 0; i < ROWS; i++) {  \
        for (int j = 0; j < ROWS; j++) { \
            int product = 0; \
            for (int k = 0; k < COLS; k++)  \
                product += A[i][k] * B[j][k];  \
            printf("%d ", product);  \
        }  \
        printf("\n");  \
    }\

int main() {
    int A[ROWS][COLS];
    int B[ROWS][COLS];

    // Initialize arrays A and B
    INIT_A(A);
    INIT_B(B);

    // Display the sum of arrays A and B
    DISPLAY_SUM(A, B);
    printf("\n");

    // Display the transpose of array B
    DISPLAY_TRANSPOSE(B);
    printf("\n");

    // Display the product of array A and transpose of B
    DISPLAY_PRODUCT(A, B);
    return 0;
}
