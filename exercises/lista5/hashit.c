#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 101

char *table[MAX]; //guarda minhas chaves
int size = 0;

void initTable() {
    for(int i = 0; i < MAX; i++) {
        free(table[i]); // sentinela
        table[i] = NULL;
    }
}

int h(char *key) {
    int len = 0, sum = 0;
    len = strlen(key);

    for(int i = 0; i < len; i++) {
        sum += (key[i]*(i+1));
    }
    sum = sum * 19;
    return sum;
}

int Hash(char *key) {
    int hash = h(key) % 101;
    return hash; 
}

int hj(char *key, int j) {
    return (Hash(key) + j * j + 23 * j) % 101;
}


int exists(char *key) {
    for(int j = 0; j <= 19; j++) {
        int hash = hj(key, j);
        if(table[hash] == NULL) {
            continue;
        }
        if(strcmp(key, table[hash]) == 0) {
            return 1;
        }
    }
    return 0;
}

void add(char *key) {
    if(exists(key)) {
        return;
    }
    int len = strlen(key);
    for(int j = 0; j <= 19; j++) {
        int f = hj(key, j);
        if(table[f]) {
            continue;
        }
        table[f] = malloc(len + 1);
        memcpy(table[f], key, len + 1);
        size++;
        break;
     }
 }

void delete(char *key) {
    for(int j = 0; j <= 19; j++) {
        int f = hj(key, j);
        if(table[f] && strcmp(key, table[f]) == 0) {
            free(table[f]);
            table[f] = NULL;
            size--;
            return;
        }
    }
}

int main() {

    int t, n;
    scanf("%d", &t); //number of test cases
    
    char *str;
    char line[100];

    for(int test = 1; test <= t; test++) {
        scanf("%d", &n); //number of operations
        size = 0;
        initTable();

        for(int i = 0; i < n; i++) {
            scanf("%s", line);
            str = &line[4];
            if(line[0] == 'A') {
                add(str); 
                /*
                for(int k = 0; k < MAX; k++){
                    if(table[k] == NULL) continue; 
                    printf("%d:%s\n", k, table[k]);
                }
                */
            }
            else {
                delete(str);
                /*
                for(int k = 0; k < MAX; k++){
                     if(table[k] == NULL) continue; 
                     printf("%d:%s\n", k, table[k]);
                }
                */

            }    
//            puts("");  
        }
        printf("%d\n", size);
        for(int k = 0; k < MAX; k++){
            if(table[k]) printf("%d:%s\n", k, table[k]);
        }
    } 
   

    return 0;
}
