#include <stdio.h>

void selectionSort(int *arr, int size) {
    
    for(int i = 0; i < n - 1; i++) {
        
        int menor_indice = i;

        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[menor_indice]) {
                menor_indice = j;   
            }
        } 
        
        int aux = arr[i];
        arr[i] = arr[menor_indice];
        arr[menor_indice] = aux;
    }
}
int main() {
    return 0;
}
