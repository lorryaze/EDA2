#include <stdio.h>
#include <stdlib.h>

#define N 100000

int a[8][N];
int size[8];
int idx[8];

int main() {

    int total = 0;
    for(int i = 0; i < 8; i++) {
        scanf("%d", &size[i]);
        total += size[i];
        for(int j = 0; j < size[i]; j++) { 
            scanf("%d", &a[i][j]);
        }
    }

    for(int j = 0; j < total; j++) {
        int min_at = -1;
        for(int i = 0; i < 8; i++) {
            int at = idx[i];
            if(at >= size[i]) {
                continue;
            }
            if(min_at == -1) {
                min_at = i;
                continue;
            }
            if(a[i][at] < a[min_at][idx[min_at]]) {
                min_at = i;
            }
        }
        if(min_at >= 0) {
            printf("%d ", a[min_at][idx[min_at]]);
        }
        idx[min_at]++;
    }
    puts("");

    return 0;
}
