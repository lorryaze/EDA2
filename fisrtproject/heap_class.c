#include <stdio.h>
#include <stdlib.h>

#define ROOT 1


typedef long long ll;

#define pc(x) putchar_unlocked(x)
#define gc(x) getchar_unlocked(x)

void scan_int(int *x) {
    register int c = gc();
    *x = 0;
    int neg = 0;
    for(; ((c < 48 || c > 57) && c != '-'); c = gc());
    if(c == '-') {
        neg = 1;
        c = gc();
    }
    for(; c > 47 && c < 58; c = gc()) {
        *x = (*x << 1) + (*x << 3) + c - 48;
    }
    if(neg)
        *x = -*x;
}

void print_int(int n) {
    int N = n, rev, count = 0;
    rev = N;
    if(N == 0) {
        pc('0');
        return;
    }
    if(N < 0) {
        pc('-');
        N = -N;
        rev = N;
    }
    while((rev % 10) == 0) {
        count++; rev /= 10;
    }
    rev = 0;
    while(N != 0) {
        rev = (rev << 3) + (rev<<1) + N % 10;
        N /= 10;
    }
    while(rev != 0) {
        pc(rev % 10 + '0');
        rev /= 10;
    }
    while(count--)
        pc('0');
}


void scan_ll(ll *x) {
    register ll c = gc();
    if(c == EOF) {
        *x = -1LL;
        return;
    }
    *x = 0;
    ll neg = 0;
    for(; ((c < 48 || c > 57) && c != '-'); c = gc());
    if(c == '-') {
        neg = 1;
        c = gc();
    }
    for(; c > 47 && c < 58; c = gc()) {
        *x = (*x << 1) + (*x << 3) + c - 48;
    }
    if(neg)
        *x = -*x;
}

void print_ll(ll n) {
    ll N = n, rev, count = 0;
    rev = N;
    if(N == 0) {
        pc('0');
        return;
    }
    while((rev % 10) == 0) {
        count++; rev /= 10;
    }
    rev = 0;
    while(N != 0) {
        rev = (rev << 3) + (rev<<1) + N % 10;
        N /= 10;
    }
    while(rev != 0) {
        pc(rev % 10 + '0');
        rev /= 10;
    }
    while(count--)
        pc('0');
}
/*
*/
#define N (10000100)

typedef struct s_Node {
    ll code;
    int grade;
} Node;

/* negativo = menor,
 * zero = igual,
 * positivo = maior
 */
ll cmp(Node a, Node b) {
    if(a.grade == b.grade) {
        return a.code - b.code;
    }
    return a.grade - b.grade;
}

Node heap[N];

void swap(int i, int j) {
    Node aux = heap[i];
    heap[i] = heap[j];
    heap[j] = aux;
}

int size = 0;

void add(Node seed) {
    ++size;
    heap[size] = seed;
    int i = size;
    while(i > ROOT) {
        int p = i / 2;
        if(cmp(heap[i], heap[p]) > 0) {
            swap(i, p);
            i = p;
        }
        else {
            break;
        }
    }
}

void pop() {
    swap(1, size);
    size--;
    int i = ROOT, l, r, max_index;
    while(1) {
        l = 2 * i;
        r = l + 1;
        max_index = i;
        if(l <= size && cmp(heap[l], heap[max_index]) > 0) {
            max_index = l;
        }
        if(r <= size && cmp(heap[r], heap[max_index]) > 0) {
            max_index = r;
        }
        if(max_index == i) {
            break;
        }
        swap(i, max_index);
        i = max_index;
    }
}

int cmp_code(const void *a, const void *b) {
    return ((Node *) a)->code - ((Node *) b)->code;
}

void sort() {
    qsort(heap + 1, size, sizeof(Node), cmp_code);
}

int main() {

    int k;
    scanf("%d", &k);
    Node seed;
    while(1) {
        scan_ll(&seed.code);
        if(seed.code < 0) {
            break;
        }
        scan_int(&seed.grade);
        add(seed);
        if(size > k) {
            pop();
        }
    }
    sort();
    for(int i = 1; i <= size; i++) {
        print_ll(heap[i].code);
        pc(' ');
        print_int(heap[i].grade);
        pc('\n');
    }

    return 0;
}
