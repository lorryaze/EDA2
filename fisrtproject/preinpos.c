#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

int isEmpty (Node *new) {
    if(new == NULL) {
        puts("Is empty");
        return 1;
    }
    else {
        puts("is not empty");
        return 0;
    }
}

Node *newNode(int value) {
    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node *insert(Node *root, int i) {
    if(root == NULL) return newNode(i); //cria uma raiz com dois filhos nulos
    
    if(i < root->value) {
        root->left = insert(root->left, i); //insere um numero a esquerda de r
    }
    else if(i > root->value){
        root->right = insert(root->right, i);
    }

    return root;
}

void freeTree(Node *root) {
    if(root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void PreOrder(Node *tree) {
    if(tree == NULL) return;

    printf("%d ", tree->value);
    PreOrder(tree->left);
    PreOrder(tree->right);
}

void InOrder(Node *tree) {
    if(tree == NULL) return;
    
    InOrder(tree->left);
    printf("%d ", tree->value);
    InOrder(tree->right);
}

void PosOrder(Node *tree) {
    if(tree == NULL) return;

    PosOrder(tree->left);
    PosOrder(tree->right);
    printf("%d ", tree->value);
}

int main() {
    int d;
    Node *root = NULL;
    
    while(scanf("%d", &d) != EOF) {
        root = insert(root, d);
    }
    PreOrder(root);
    printf(".\n");
    InOrder(root);
    printf(".\n");
    PosOrder(root);
    printf(".\n");

    return 0;
}
