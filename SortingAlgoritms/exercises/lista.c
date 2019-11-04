#include <stdio.h>
#include <stdlib.h>

typedef struct Node_1{
    int val;
    struct Node_1 *next;
}Node;

void printNode(Node *node){
    Node *no;
    no = node; 
    while(no != NULL){ //minha lista acaba quando meu node = NULL
        printf("%d -> ", no->val);
        no = no->next; //atualiza o valor do meu nó para o próximo nó da lista
    } 
    printf("NULL\n");
}
void insert(Node *past, int val){ //past = posição anterior a que eu quero inserir
    Node *new = malloc(sizeof(Node)); //lembra de alocar a memória 
    new->next = past->next;
    new->val = val;
    past->next = new;
}

int main(){
    
    Node one;
    one.val= 1;
    

    Node two;
    two.val=2;
    one.next = &two;
    two.next = NULL;

    insert(&two, 3);
    printNode(&one);
    return 0;
}



