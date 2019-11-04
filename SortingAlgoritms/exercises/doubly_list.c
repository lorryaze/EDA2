#include <stdio.h>
#include <stdlib.h>

typedef struct node_1 {
    struct node_1 *next;
    struct node_1 *prev;
    int val;
}Node;

typedef struct list_1{
    Node *head;
    Node *tail;
}List;

void insert(Node *past, int val){
   
    Node *new = malloc(sizeof(Node));
    
    new->next = past->next;
    new->prev = past;
    past->next = new;
}
void printlist(Node *head){
    Node node = malloc(sizeof(Node));
    node = head;
    
    while(node != NULL){
        printf(:wq);
    }
}

int main(){
    List list;
    return 0;
}

