//#include <stdlib.h>
#include <stdio.h>
//#include <time.h>
int main(void) {
    int N = 4;
    int a [4][4];
    int b [4][4];
    int c [4][4];
    //int num;
    int i,j,k;
    int t;
    //srand( (unsigned int)time( 0 ) );

    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < N; j++ ) {
            //a[i][j] = ( rand() % 10 ) + 1;
            //b[i][j] = ( rand() % 10 ) + 1;
            a[i][j] = 5;
            b[i][j] = 5;
            c[i][j] = 0;
        }
    }

    for ( i = 0; i < N; i+= 2 ) {
        for ( j = 0; j < N; j+= 2 ) {
            for ( k = 0; k < N; k++ ) {
                t = c[i][j] + (a[i][k] * b[k][j]);
                c[i][j] = t;
                t = c[i + 1][j] + (a[i + 1][k] * b[k][j]);
                c[i + 1][j] = t;
                t = c[i][j + 1] + (a[i][k] * b[k][j + 1]);
                c[i][j + 1] = t;
                t = c[i + 1][j + 1] + (a[i + 1][k] * b[k][j + 1]);
                c[i + 1][j + 1] = t;
                //c[i][j] += a[i][k] * b[k][j];
                //c[i + 1][j] += a[i + 1][k] * b[k][j];
                //c[i][j + 1] += a[i][k] * b[k][j + 1];
                
                //c[i + 1][j + 1] += a[i + 1][k] * b[k][j + 1];
                
            }
        }
    }

    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < N; j++ ) {
            printf("%2d ", c[i][j]);
        }
        printf("\n");
    }
   
    return 0;
}