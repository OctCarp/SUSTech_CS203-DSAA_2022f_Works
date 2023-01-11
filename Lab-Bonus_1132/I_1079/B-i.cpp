#include <cstdio>
#include <cstring>
#include <vector>

#define MAX_SIZE 5005

using namespace std;

struct course {
    vector<int> pre_co;
} cs[MAX_SIZE];

int T;
bool DAG, is_v[MAX_SIZE];
vector<int> res;

int read();

void write(int x);

void dfs(int p, int root);

inline void reset();

void sel_once();

int main() {
    T = read();
    while (T--) {
        reset();
        sel_once();
    }

    return 0;
}

void reset() {
    DAG = true;
    memset(is_v, false, sizeof is_v);
    res.clear();
}

void sel_once() {
    int n = read();
    int m = read();

    int x, y;
    while (m--) {
        x = read();
        y = read();
        cs[y].pre_co.push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        if (!is_v[i]) dfs(i, i);
    }

    if (DAG) {
        for (int id: res) {
            write(id);
            putchar(' ');
        }
        putchar('\n');
    } else {
        printf("impossible\n");
    }
}

void dfs(int p, int root) {
    is_v[p] = true;

    if (DAG) {
        for (int ch: cs[p].pre_co) {
            if (ch == root) {
                DAG = false;
                break;
            }
            if (!is_v[ch]) {
                dfs(ch, root);
            }
        }

        res.push_back(p);
    }

    cs[p].pre_co.clear();
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
