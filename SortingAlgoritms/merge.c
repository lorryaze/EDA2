#include <stdio.h>
#include <stdlib.h>

#define N 100000

void mergeAB(int *c, int *a, int n, int *b, int m) {

    int i = 0, j = 0, k = 0;

    while(i < n && j < m) {
        
        if(a[i] <= b[j]) {
            c[k] = a[i];
            i++;
            k++;
        }
        else {
          c[k] = b[j];
          j++;
          k++;
        }
    }

    while(i < n) {
        c[k] = a[i];
        i++;
        k++;
    }
    while(j < m) {
        c[k] = b[j];
        j++;
        k++;
    }
}

void intercala4(int *arr, int *a, int n, int *b, int m, int *c, int o, int *d, int p) {

    int *arr1 = malloc(sizeof(int) * (n + m));
    mergeAB(arr1, a, n, b, m);

    int *arr2 = malloc(sizeof(int) * (o + p));
    mergeAB(arr2, c, o, d, p);

    mergeAB(arr, arr1, (n+ m), arr2, (o + p));
}

void intercala8(int *arr, int *a, int n, int *b, int m, int *c, int o, int *d, int p, int *e, int q, int *f, int r, int *g, int s, int *h,int t) {

    int *arr1 = malloc(sizeof(int) * (n + m + o + p));
    intercala4(arr1, a, n, b, m, c, o, d, p);

    int *arr2 = malloc(sizeof(int) * (q + r + s + t));
    intercala4(arr2, e, q, f, r, g, s, h, t);

    mergeAB(arr, arr1, (n + m + o + p), arr2, (q + r + s + t));
}

int *a[8];
int size[8];
int ans[N * 8];

int main() {
    int total = 0;
    for(int i = 0; i < 8; i++) {
        scanf("%d", &size[i]);
        total += size[i];
        a[i] = malloc(sizeof(int) * size[i]);
        for(int j = 0; j < size[i]; j++) { 
            scanf("%d", &a[i][j]);
        }
    }

    intercala8(ans,
            a[0], size[0],
            a[1], size[1],
            a[2], size[2],
            a[3], size[3],
            a[4], size[4],
            a[5], size[5],
            a[6], size[6],
            a[7], size[7]
    );

    for(int i = 0; i < total; i++) {
        printf("%d ", ans[i]);
    }
    puts("");

    return 0;
}
