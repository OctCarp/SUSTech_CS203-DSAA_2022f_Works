#include <stdio.h>

#define MAX_SIZE 500005

struct node {
    int w;
    int init;
    int inner;
} ns[MAX_SIZE] = {0};

int n, num, cnt = 0;

int read();

void write(int x);

void init();

int main() {
    init();

    for (int i = 1; i <= n; ++i) {
        if (ns[i].init && !ns[i].inner && ns[i].w == num) {
            ++cnt;
        }
    }

    write(cnt);

    return 0;
}

void init() {
    n = read();
    num = read();

    ns[1].init = 1;

    int T = n, u, v, parent, child;
    while (--T) {
        u = read();
        v = read();

        if (ns[u].init) {
            parent = u;
            child = v;
        } else {
            parent = v;
            child = u;
        }

        ns[child].w = read();
        ns[child].w += ns[parent].w;
        ns[parent].inner = 1;
        ns[child].init = 1;
    }
}

int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
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
