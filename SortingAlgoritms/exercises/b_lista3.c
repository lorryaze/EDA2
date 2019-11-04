#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
void mergeAB(int *c, int *a, int n, int *b, int m) {
    
    int i = 0,  j = 0, k = 0;

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
void merge(int *arr, int l, int m, int r) {
    
    int *c = malloc(sizeof(int) * (r - l + 1));

    mergeAB(c, &arr[l], (m - l + 1), &arr[m + 1], (r - (m+1) + 1));
    
    int k = 0, i = l;

    while(i <= r){ // (certo: i <= r, errado: l <= r)
        arr[i] = c[k];
        i++;
        k++;
    }

    free(c);
}
void mergesort(int *arr, int l, int r) {
    
    if(l == r) return;
    
    int m = (l + r) / 2;

    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr, l, m, r); 
}
int bs(int n) {
    int l = 0, r = n - 1;
    int m = l + (r - l) / 2;
    return m;
}

int main() {
    
    int n;
    int arr[MAX];

    while(scanf("%d", &n) == 1 && n != 0) {
        
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        mergesort(arr, 0, n - 1);
        
        int meio = bs(n);

        printf("%d\n", arr[meio]);

    }
   return 0;
}
