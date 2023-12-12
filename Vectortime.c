#include <stdio.h>
#include <time.h>
#define rows 50000
#define cols 3

int main() {
    clock_t start, end;
    
    int i,j;
    int w,x,y,z;

    int matrix1[rows][cols];
    int matrix2[rows][cols];
    int sumMatrix[rows][cols];

    for ( i = 0; i < rows; i++ ) {
        for ( j = 0; j < cols; j++ ) {
           
            matrix1[i][j] = 5;
            matrix2[i][j] = 5;
            sumMatrix[i][j] = 0;
           
        }
    }
    start = clock();
    for (i = 0; i < rows; i+= 2) {
        for (j = 0; j < cols; j+= 2) {
            w = sumMatrix[i][j] + (matrix1[i][j] + matrix2[i][j]);
            x = sumMatrix[i + 1][j] + (matrix1[i + 1][j] + matrix2[i + 1][j]);
            y = sumMatrix[i][j + 1] + (matrix1[i][j + 1] + matrix2[i][j + 1]);
            z = sumMatrix[i + 1][j + 1] + (matrix1[i + 1][j + 1] + matrix2[i + 1][j + 1]);

            sumMatrix[i][j] = w;
            sumMatrix[i + 1][j] = x;
            sumMatrix[i][j + 1] = y;
            sumMatrix[i + 1][j + 1] = z;

        }
    }
    end = clock();
    printf("Vectortime.c\n");
    printf("実行時間: %d\n", (int)(difftime(end,start)));
    return 0;
   
    
    
}