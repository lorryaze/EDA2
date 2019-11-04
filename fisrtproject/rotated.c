#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node *rotR(Node *root) {
    Node *x = root->left;
    root->left = x->right;
    x->right = root;
    return x;
}

Node *rotL(Node *root) {
    Node *x = root->right;
    root->right = x->left;
    x->left = root;
    return x;
}

Node *newNode(int value) {
     Node *new = malloc(sizeof(Node));
     new->value = value;
     new->left = NULL;
     new->right = NULL;
     return new;
}
 
Node *root = NULL;
Node *insert(Node *node, int i) {
     if(node == NULL) {
        node = newNode(i); //cria uma raiz com dois filhos nulos
        return node;
     }
 
     if(i < node->value) {
        node->left = insert(node->left, i);
        node = rotR(node);
     }
     else {
         node->right = insert(node->right, i);
         node = rotL(node);
     }
     root = node;
     return node;
}

void InOrder(Node *tree) {
    if(tree == NULL) return;
    
    InOrder(tree->left);
    if(tree == root) {
        putchar('*');
    }
    printf("%d ", tree->value);
    InOrder(tree->right);
}

int main() {
    int d;

    while(scanf("%d", &d) != EOF) {
        root = insert(root, d);
        InOrder(root);  
        printf(".\n");
    }
    return 0;
}
