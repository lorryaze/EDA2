#include <stdio.h>

int partition(int *arr, int l, int r) { //r = n - 1 ex: n = 7, r = 6
    
    int pivo = arr[r];
    int i = l - 1; 

    for(int j = 0; j <= r - 1; j++) { //r - 1 é a penultima posição do arr
        if(arr[j] <= pivo) {
            i++;
            int aux = arr[j];
            arr[j] = arr[i];
            arr[i] = aux;
        }
    }

    int au = arr[i + 1];
    arr[i + 1] = arr[r]; // i + 1 posição do pivo
    arr[r] = au; //endereço da ultima posição que era onde o pivo tava

    return (i + 1); //posição do meu pivo
}

void quicksort(int *arr, int l, int r) {
    
    if(l < r) {
        int q = partition(arr, l, r); //q = posição do pivô
        quicksort(arr, l, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int main(){
    return 0;
}
