#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 101 //number of strings, and 23 is the size of strings

typedef struct {
    char str[21];
}STR; 

STR arr[N];

/*
int strcmp(char *a, char *b) {
    
    while(*a != '\0' && *b != '\0') {
        if(*a < *b) {
            return -1;
        }
        else if(*a == *b) {
            a++;
            b++;
        }
        else {
            return 1;
        }
    }
    if(*a == '\0' && *b == '\0') {
        return 0;
    }
    if(*a == '\0') {
        return -1;
    }
    else {
        return 1;
    }
}
*/

int partition(STR *arr, int l, int r) { //l = first position of arr, r = arr.size - 1
        
    STR p = arr[r]; //p = pivot 
    int i = l - 1; //index of less number
    STR aux;

     for(int j = l; j <= r-1; j++) {
         if(strcmp(arr[j].str, p.str) <= 0) { // strcmp(arr[j], p) <= 0
         
             i++;
             aux = arr[j];
             arr[j] = arr[i];
             arr[i] = aux;
             
         }
     }
     
     STR au;
     au = arr[i+1];
     arr[i+1] = arr[r];
     arr[r] = au;

     return (i+1);
}

void quicksort(STR *arr, int l, int r) {
        if(l < r) {
            int q = partition(arr, l, r);
            quicksort(arr, l, q-1);
            quicksort(arr, q+1, r);
            
        }
}

int main() {
    
    int n, k;
    scanf("%d", &n); //n strings
    scanf("%d", &k); //numero sortedo

    for(int i = 0; i < n; i++) {
        scanf("%s", arr[i].str);
    } 
    
    quicksort(arr, 0, n-1);

    /*for(int i = 0; i < n; i++) {
        printf("%s\n", arr[i].str);
    }*/
    
    printf("%s\n", arr[k-1].str);
    return 0;
}
