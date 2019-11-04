#include <stdio.h>
#include <stdlib.h>

typedef unsigned long int ui;


typedef struct node {
    char *str;
    struct node *prev, *next;
} Node;

Node *init() {
    return NULL;
}

Node *insert(Node *node, char *str) {
    if(node == NULL) {
        node->str = str;
        node->prev = NULL;
        node->next = NULL;
        return node;
    } 
    

}
int main() {
        
    return 0;       
}
