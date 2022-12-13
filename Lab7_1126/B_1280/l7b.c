#include <stdio.h>

#define MAX_SIZE 1005

int heap[MAX_SIZE * 2];

#define sz heap[0]

int n;

void swap(int i, int j);

void initOnce();

void ins(int in);

int pop();

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        initOnce();

        int cost = 0;
        int cut;
        while (sz > 1) {
            cut = pop() + pop();
            cost += cut;
            ins(cut);
        }

        printf("%d\n", cost);
    }

    return 0;
}

void initOnce() {
    scanf("%d", &n);

    sz = 0;
    int in;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in);
        ins((int) in);
    }
}

void ins(int in) {
    heap[++sz] = in;
    int p = sz;

    while (p > 1) {
        if (heap[p] < heap[p >> 1]) {
            swap(p, p >> 1);
            p = p >> 1;
        } else break;
    }
}

int pop() {
    int min_val = heap[1];

    heap[1] = heap[sz--];
    int s = 2, t = 1;
    while (s <= sz) {
        if (s <= sz - 1 && heap[s + 1] < heap[s]) {
            ++s;
        }
        if (heap[s] < heap[t]) {
            swap(s, t);
            t = s;
            s = s << 1;
        } else break;
    }

    return min_val;
}

void swap(int i, int j) {
    heap[i] = heap[i] ^ heap[j];
    heap[j] = heap[j] ^ heap[i];
    heap[i] = heap[i] ^ heap[j];
}
