#include <cstdio>
#include <vector>

#define MAX_SIZE 100005

using namespace std;

struct vertex {
    int max_val = 0;
    bool is_v = false;
    vector<int> edge;
} vtx[MAX_SIZE];

int n, m;

inline int read();

inline void write(int x);

inline void rev_con(int u, int v);

void init();

void bfs(int root, int val_in);

int main() {
    init();

    for (int i = n; i >= 1; --i) {
        bfs(i, i);
    }

    for (int i = 1; i <= n; ++i) {
        write(vtx[i].max_val);
        putchar(' ');
    }

    return 0;
}

void bfs(int root, int val_in) {
    if (!vtx[root].is_v) {
        vtx[root].is_v = true;
        vtx[root].max_val = val_in;

        for (int root_adj: vtx[root].edge) {
            bfs(root_adj, val_in);
        }
    }
}

void init() {
    n = read();
    m = read();

    while (m--) {
        rev_con(read(), read());
    }
}

void rev_con(int u, int v) {
    vtx[u].edge.push_back(v);
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
