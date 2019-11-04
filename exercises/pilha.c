#include <stdio.h>

#define CAPACITY 100

void push(int val) {
    size++;
}

int top() {
    return 
}

void pop() {
    size--;
}

// [1, 2, 4], size = 3
// [1, 2, 4, 7], size = 4

int main() {

    push(1);
    push(2);
    push(3);
    push(4);

    printf("size = %d\n", size);

    for(int i = 0; i < 4; i++) {
        printf("top = %d, size = %d\n", top(), size);
        pop();
    }

    return 0;
}
