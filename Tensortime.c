#include <stdio.h>
#include <time.h>
#define dim1 200
#define dim2 200
#define dim3 4

int main() {
    clock_t start, end;

    int i,j,k;
    int w,x,y,z;
    int tensor[dim1][dim2][dim3];
    int tensor1[dim1][dim2][dim3];
    int tensor2[dim1][dim2][dim3];

    for ( i = 0; i < dim1; i++ ) {
        for ( j = 0; j < dim2; j++ ) {
            for ( k = 0; k < dim3; k++ ) {
                tensor1[i][j][k] = 5;
                tensor2[i][j][k] = 5;
                tensor[i][j][k] = 0;
            }
        }
    }

    
    start = clock();
    for (i = 0; i < dim1; i+= 2) {
        for (j = 0; j < dim2; j+= 2) {
            for (k = 0; k < dim3; k++) {
                w = tensor[i][j][k] + (tensor1[i][j][k] * tensor2[i][j][k]);
                x = tensor[i + 1][j][k] + (tensor1[i + 1][j][k] * tensor2[i + 1][j][k]);
                y = tensor[i][j + 1][k] + (tensor1[i][j + 1][k] * tensor2[i][j + 1][k]);
                z = tensor[i + 1][j + 1][k] + (tensor1[i + 1][j + 1][k] * tensor2[i + 1][j + 1][k]);

                tensor[i][j][k] = w;
                tensor[i + 1][j][k] = x;
                tensor[i][j + 1][k] = y;
                tensor[i + 1][j + 1][k] = z;
            }
        }
    }
    end = clock();
    printf("Tensortime.c\n");
    printf("実行時間: %d\n", (int)(difftime(end,start)));
    return 0;
}