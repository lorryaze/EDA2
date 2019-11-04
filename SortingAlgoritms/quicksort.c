#include <stdio.h>
#define MAX 100001

int arr[MAX];

int partition(char *arr, int l, int r) { //l = first position of arr, r = size-1
    int p = arr[r]; //p = pivot 
    int i = l - 1; //index of less number
    int aux = 0;

    for(int j = l; j <= r - 1; j++) {
        if(arr[j] < p) { // strcmp(arr[j], p) <= 0
            i++;
            aux = arr[j];
            arr[j] = arr[i];
            arr[i] = aux;
        }
    }
        int  au = 0;
        au = arr[i+1];
        arr[i+1] = arr[r];
        arr[r] = au;

        return (i+1);
}

void quicksort(int *arr, int l, int r) {
    if(l < r) {
        int q = partition(arr, l, r);
        quicksort(arr, l, q-1);
        quicksort(arr, q+1, r);
    }
}

int main() {
        
    int n = 0;

    while(scanf("%d", &arr[n]) != EOF) {
        n++;
    }
            
    quicksort(arr, 0, n-1);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
                            
}

