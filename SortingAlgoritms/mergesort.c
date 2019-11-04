#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
//dá um merge em dois vetores ordenados.
void mergeAB(int *c, int *a, int n, int *b, int m) { //c é o merge de a e bn e m são o tamanho de a e b
    
    int i = 0, j = 0, k = 0; //variaves de controle de a, b e c 
    
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

// a = arr[l, m], tamanho m - l + 1
// b = arr[m + 1, r], tamanho r - (m + 1) + 1
// c = ordena(a + b)
// preencher a[l, ..., r] = c = a[l..r]
void merge(int *arr, int l, int m, int r) {
    
    int *c = malloc(sizeof(int) * (r - l + 1)); //(r-l+1) é o número de elementos no interval de [l, r]

    mergeAB(c, &arr[l], (m - l + 1), &arr[m + 1], (r - (m + 1) + 1)); // (q-l+1) é o número de elementos de [l, meio]
    
    int k = 0, i = l;

    while(i <= r) {
        arr[i] = c[k];
        i++;
        k++;
    }

    free(c);
}

// ordena, inplace, arr[l, r]
void mergesort(int *arr, int l, int r) {
    
    if(l == r) return;
    
    int m = (l + r) / 2; // Pq meio é l+r/2 e não l+(r-l)/2????? tirar dúvida dps

    mergesort(arr, l, m); //começa a dividir o vetor de l(inicio) até o meio
    mergesort(arr, m + 1, r); // --  - ------- - ----- -- m+1 até o fim (r)
    merge(arr, l, m, r);
}

int main() {
    int arr[MAX];
    int n = 0;

    while(scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    
    mergesort(arr, 0, n-1);

    for(int i  = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return 0;
}
