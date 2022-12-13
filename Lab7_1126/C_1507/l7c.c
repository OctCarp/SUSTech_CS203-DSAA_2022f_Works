#include <stdio.h>

#define MAX_SIZE 500005

struct pile {
    int val;
    int l;
    int r;
    int has_del;
} ls[MAX_SIZE] = {0};

int h[MAX_SIZE] = {0};

int sz = 0;

int n;

int read();

void write(int x);

void init();

inline int needSwap(int pa, int ch);

inline void heapSwap(int x, int y);

void ins(int id);

int pop();

inline void mergeLeft(int p, int l_id);

inline void mergeRight(int p, int r_id);

void mergeOnce();

int main() {
    init();

    while (--n) {
        mergeOnce();
    }

    write(ls[pop()].val);

    return 0;
}

void init() {
    n = read();

    for (int i = 1; i <= n; ++i) {
        ls[i].val = read();
        ls[i].l = i - 1;
        ls[i].r = i + 1;
        ins(i);
    }
    ls[0].r = 1;
    ls[n].r = 0;
}

void mergeOnce() {
    int p = pop();
    int l_id = ls[p].l;
    int r_id = ls[p].r;

    if (l_id && r_id) {
        if ((ls[p].val ^ ls[l_id].val) >= (ls[p].val ^ ls[r_id].val)) {
            mergeLeft(p, l_id);
        } else {
            mergeRight(p, r_id);
        }
        return;
    }

    if (l_id) {
        mergeLeft(p, l_id);
    } else if (r_id) {
        mergeRight(p, r_id);
    }
}

int needSwap(int pa, int ch) {
    return ls[h[pa]].val > ls[h[ch]].val || ls[h[pa]].val == ls[h[ch]].val && h[pa] > h[ch];
}

void ins(int id) {
    h[++sz] = id;
    int p = sz;

    while (p > 1) {
        if (needSwap(p >> 1, p)) {
            heapSwap(p >> 1, p);
            p = p >> 1;
        } else break;
    }
}

int pop() {
    int top_has_del = ls[h[1]].has_del;
    int p = h[1];

    h[1] = h[sz--];
    int s = 2, t = 1;
    while (s <= sz) {
        if (needSwap(s, s + 1) && s <= sz - 1) {
            ++s;
        }
        if (needSwap(t, s)) {
            heapSwap(t, s);
            t = s;
            s = s << 1;
        } else break;
    }

    return top_has_del ? pop() : p;
}

void mergeLeft(int p, int l_id) {
    ls[p].val = (ls[p].val ^ ls[l_id].val) + 1;
    ins(p);

    ls[p].l = ls[l_id].l;
    if (ls[l_id].l) ls[ls[l_id].l].r = p;
    ls[l_id].has_del = 1;
}

void mergeRight(int p, int r_id) {
    ls[p].val = (ls[p].val ^ ls[r_id].val) + 1;
    ins(p);

    ls[p].r = ls[r_id].r;
    if (ls[r_id].r) ls[ls[r_id].r].l = p;
    ls[r_id].has_del = 1;
}

void heapSwap(int x, int y) {
    h[x] = h[x] ^ h[y];
    h[y] = h[x] ^ h[y];
    h[x] = h[x] ^ h[y];
}

int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = (s << 1) + (s << 3) + (ch ^ '0');
        ch = getchar();
    }
    return s * f;
}

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        write(x / 10);
        putchar(x % 10 + '0');
    } else putchar(x + '0');
    return;
}

