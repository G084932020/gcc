#include <stdio.h>
#include <time.h>
#define len 400

int main() {
    clock_t start, end;

    // 開始時刻を記録
    start = clock();

    // ここに実行時間を計測したいコードを書く
    int a [len][len];
    int b [len][len];
    int c [len][len];
    //int num;
    int i,j,k;
    int t;
    //srand( (unsigned int)time( 0 ) );
    
   

    for ( i = 0; i < len; i++ ) {
        for ( j = 0; j < len; j++ ) {
            //a[i][j] = ( rand() % 10 ) + 1;
            //b[i][j] = ( rand() % 10 ) + 1;
            a[i][j] = 5;
            b[i][j] = 5;
            c[i][j] = 0;
        }
    }

    for ( i = 0; i < len; i+= 2 ) {
        for ( j = 0; j < len; j+= 2 ) {
            for ( k = 0; k < len; k++ ) {
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

    
    // 終了時刻を記録
    end = clock();

    
    // 結果を出力
    printf("実行時間: %d\n", (int)(difftime(end,start)));
    
    return 0;
}