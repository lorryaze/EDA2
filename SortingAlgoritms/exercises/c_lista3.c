#include <stdio.h>
#define MAX 45001

int main() {
    int n, end[MAX]; //numero de endereços
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &end[i]);
    }

    int m, enc[MAX]; //n de encomendas
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &enc[i]);
    }
    return 0;
}
