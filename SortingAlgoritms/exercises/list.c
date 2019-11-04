#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100

typedef struct Node_t {
    int val;
    struct Node_t *next;
} Node;

void printf_list(Node *it) {
    Node *cur;
    cur = it;
    while(cur != NULL) {
        printf(" %d ->", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

void erase() {
}

void insert_back(Node *node, int val) {
    Node *new = malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;

    node->next = new;
}

void insert(Node *node, int val) {
    Node *new = malloc(sizeof(Node));
    new->val = val;
    new->next = node->next;
    node->next = new;
}

typedef struct {
    Node *head;
    int size;
} List;

List newList() {
    List list;
    list.head = malloc(sizeof(Node));
    list.size = 0;
}

int main() {

    Node one;
    one.val = 1;
    insert_back(&one, 2);
    insert(one.next, 3);
    insert_back(one.next->next, 4);
    printf_list(&one);

    Node *two = one.next;
    insert(two, -13);

    printf_list(&one);

    return 0;
}
