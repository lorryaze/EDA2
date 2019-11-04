#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000001
#define M 65

typedef struct t_Pair {
    char s[M], prev[M], next[M];
} Pair;

int pcmp(const void *a, const void *b) {
    return strcmp(((Pair *) a)->s, ((Pair *) b)->s);
}

int n;
Pair arr[N];
char previous[N][M];
char go[N][M];

int bs(const char *s) {
    if(strcmp(s, "0") == 0) {
        return -1;
    }

    int l = 0;
    int r = n - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int cmp = strcmp(arr[mid].s, s);
//        //printf("cmp(%s, %s) = %d\n", arr[mid].s, s, cmp);
        if(cmp == 0) {
            return mid;
        }
        else if(cmp < 0) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    //printf("%s not in arr\n", s);
    return -1;
}

int ida[N];
int good(char *source, char *goal) {
    int goal_index = bs(goal);
    int source_index = bs(source);
    int cur = source_index;
    //printf("source=%s, source_index=%d\n", source, cur);
    //printf("goal=%s, goal_index=%d\n", goal, goal_index);
    int ida_size = 0;
    ida[ida_size++] = cur;
    for(int i = 0; (cur != goal_index) && i < n; i++) {
        int v = bs(arr[cur].next);
        //printf("cur=%s, cur_index=%d, next=%d\n", arr[cur].s, cur, v);
        if(v == -1) {
            return 0;
        }
        cur = v;
        ida[ida_size++] = cur;
    }
    if(cur != goal_index) {
        return 0;
    }

    ida_size--;
    while(ida_size >= 1) {
        int top = ida[ida_size - 1];
        int prev = bs(arr[goal_index].prev);
        //printf("top = %d, prev = %d\n", top, prev);
        if(top != prev) {
            return 0;
        }
        if(top == source_index) {
            return 1;
        }
        ida_size--;
        goal_index = prev;
    }
    return -1;
}

char source[M], goal[M];


int main() {

    for(n = 0; (scanf("%s %s %s", arr[n].s, arr[n].prev, arr[n].next) == 3); n++) {
        if(n == 0) {
            strcpy(source, arr[0].s);
        }
        else if(n == 1) {
            strcpy(goal, arr[1].s);
        }
    }
    qsort(arr, n, sizeof(Pair), pcmp);
    //printf("n = %d\narr=\n", n);
    for(int i = 0; i < n; i++) {
        //printf("(%s, %s, %s)\n", arr[i].s, arr[i].prev, arr[i].next);
    }

    int ok = good(source, goal);
    puts(ok ? "sana" : "insana");
}
