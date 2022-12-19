#include <cstdio>
#include <vector>
#include <queue>

#define MAX_SIZE 100005

using namespace std;

struct vertex {
    int deg = 0;
    vector<int> adj;
} vtx[MAX_SIZE];

int n, m;

inline int read();

inline void connect(int u, int v);

void init();

bool has_circle();

int main() {
    init();

    printf(has_circle() ? "Bad" : "Good");

    return 0;
}

void init() {
    n = read();
    m = read();

    while (m--) {
        connect(read(), read());
    }
}

bool has_circle() {
    queue<int> que;

    for (int i = 1; i <= n; ++i) {
        vtx[i].deg = vtx[i].adj.size();

        if (vtx[i].deg <= 1) {
            que.push(i);
        }
    }

    int cnt = 0;
    while (!que.empty()) {
        ++cnt;

        int p = que.front();

        for (int p_adj: vtx[p].adj) {
            if (--vtx[p_adj].deg == 1) {
                que.push(p_adj);
            }
        }

        que.pop();
    }

    return cnt != n;
}

void connect(int u, int v) {
    vtx[u].adj.push_back(v);
    vtx[v].adj.push_back(u);
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
