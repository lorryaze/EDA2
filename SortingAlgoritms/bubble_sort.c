#include <stdio.h>

void bubble_sort(int *arr, int n) { //n array size
    int troca = 0, cmp = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++){
            cmp++;
            if(arr[j] > arr[j + 1]) {
                int aux = 0;
                aux = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = aux;
                troca++;   
            }
        }
    }
    printf("Trocas= %d\n", troca);
    printf("Comparações= %d\n", cmp);
    printf("Teoria = %d\n", (n * (n - 1)) / 2);
}
int main() {
    int arr [] = {5, 1, 4, 2, 8, 9};
    int n = 6;
    bubble_sort(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
