#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150000
int n;
int pro[MAX];

int comp(const void *pa, const void *pb) {
    int a = *((int *) pa);
    int b = *((int *) pb);
    
    return a - b;
}

int bs(int val){
    int l = 0, r = n-1;
    
    while(l<=r) {
        int m = l + ((r - l) / 2);
        
        if(pro[m] == val) {
            return 1;
        } 
        else if(pro[m] > val) {
            r = m - 1;
        }
        else{
            l = m + 1;
        }

    }

    return 0;
}

int main() {
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &pro[i]);
    }
    
    qsort(pro, n, sizeof(int), comp);
    
    int in;
    
    while(scanf("%d", &in) != EOF){
       
        if(bs(in) == 0) {
            printf("nao\n");
        }
        else {
            puts("sim");
        }
    }
    return 0;
}
