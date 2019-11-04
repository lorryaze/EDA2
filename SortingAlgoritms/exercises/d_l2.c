#include <stdio.h>
#include <stdlib.h>
#define MAX 45001

int n, end[MAX]; //numero de endereços

int bs(int val) {
    int l = 0, r = n - 1;

    while(l <= r) {
        int meio = l + (r - l) / 2;
        if(end[meio] == val) {
            return meio; //pois quero achar o indice do valor 
        }
        else if(end[meio] > val) {
            r = meio - 1;
        }
        else {
            l = meio + 1;
        }
    }

    return 0; //valor procurado não tá no array
}

int m, enc[MAX]; //n de encomendas
int acha() {
    
    int  soma = 0, i = 0;

    for(int j = 0; j < m; j++) {
        int val  = enc[j]; //encomenda
        int i_val = bs(val); //indice valor no array endereço
         soma = soma + abs(i_val - i);
         i = i_val;
     }

    return soma;
}
int main() {

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &end[i]);
    }
    
    for(int i = 0; i < m; i++) {
        scanf("%d", &enc[i]);
    }

    printf("%d\n", acha());
    return 0;
}
