#include <stdio.h>

#define N 2

int M[N][N]; // 0,0 : 0,1 : 1,0 : 1,1

int main() {

    M[0][0] = 1;
    M[0][1] = 2;
    M[1][0] = 3;
    M[1][1] = 4;

    printf("M[%d][%d] = %d\n", 0, 0, M[0][0]);
    printf("M[%d][%d] = %d\n", 0, 0, M[0][2]);

    return 0;
}
