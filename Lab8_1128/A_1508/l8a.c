#include <stdio.h>

#define MAX_SIZE 1005

struct vertex {
    int edge[MAX_SIZE];
} vtx[MAX_SIZE];

int read();

inline void connect(int u, int v);

inline void query(int y, int x);

int main() {
    int n = read();
    int m = read();
    int q = read();

    while (m--) {
        connect(read(), read());
    }

    while (q--) {
        query(read(), read());
    }

    return 0;
}

void connect(int u, int v) {
    vtx[u].edge[v] = 1;
    vtx[v].edge[u] = 1;
}

void query(int y, int x) {
    printf(vtx[x].edge[y] ? "Yes\n" : "No\n");
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

