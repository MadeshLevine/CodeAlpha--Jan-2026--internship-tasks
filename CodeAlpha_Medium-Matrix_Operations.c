#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int r, int c, int matrix[r][c], char name);
void display(int r,int c,int matrix[r][c]);
void addMatrices(int r,int c,int m1[r][c],int m2[r][c]);
void multiplyMatrices(int r1,int c1,int m1[r1][c1],int r2,int c2,int m2[r2][c2]);
void transposeMatrix(int r,int c,int m[r][c]);

int main() 
{
    int r1,c1,r2,c2;
    printf("--- Matrix Operations Performing System ---\n\n");
    
    printf("Enter rows and columns for Matrix A:\n");
    scanf("%d %d", &r1, &c1);
    int matrixA[r1][c1];
    inputMatrix(r1, c1, matrixA, 'A');
            
    printf("Enter rows and columns for Matrix B:\n");
    scanf("%d %d", &r2, &c2);
    int matrixB[r2][c2];
    inputMatrix(r2, c2, matrixB, 'B');
  
    printf("\n--- Matrix Addition ---");
    if (r1 == r2 && c1 == c2)
    {
        addMatrices(r1, c1, matrixA, matrixB);
    }
    else 
    {
        printf("Error: Dimensions must match for addition.\n");
    }

    printf("\n--- Matrix Multiplication ---\n");
    if (c1 == r2) 
    {
        multiplyMatrices(r1, c1, matrixA, r2, c2, matrixB);
    }
    else
    {
        printf("Error: Columns of A must equal rows of B.\n");
    }

    printf("\n--- Transpose of Matrix A ---");
    transposeMatrix(r1, c1, matrixA);

    printf("\n--- Transpose of Matrix B ---");
    transposeMatrix(r2, c2, matrixB);       
                
    return 0;
}

void inputMatrix(int r, int c, int matrix[r][c], char name)
{
    printf("Enter elements for Matrix %c:\n", name);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display(int r, int c, int matrix[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int r, int c, int m1[r][c], int m2[r][c]) {
    int sum[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sum[i][j] = m1[i][j] + m2[i][j];
    
    printf("\nResultant Sum Matrix:\n");
    display(r, c, sum);
}

void multiplyMatrices(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]) {
    int res[r1][c2];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    printf("\nResultant Product Matrix:\n");
    display(r1, c2, res);
}

void transposeMatrix(int r, int c, int m[r][c]) {
    int trans[c][r];
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = m[i][j];
    
    printf("\nTranspose of Matrix:\n");
    display(c, r, trans);
}
