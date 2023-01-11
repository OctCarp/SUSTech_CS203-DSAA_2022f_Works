#include <cstdio>
#include <cstring>
#include <queue>

#define MAX_K (1050000)

using namespace std;

struct gift {
    int L = 0;
    int t = 0;
} g[MAX_K];

struct list {
    int K;
    int L;
    int t;

    list(int k, int l, int time);
};

struct cmp {
    bool operator()(const list &g1, const list &g2);
};

int T;

int read();

void write(int x);

void buy_once();

int main() {
    T = read();
    while (T--) {
        buy_once();
    }

    return 0;
}

void buy_once() {
    int M = read();
    int N = read();

    memset(g, 0, sizeof g);
    priority_queue<list, vector<list>, cmp> pri_que;

    int num = 0;
    int cnt = 0;

    int K;
    for (int i = 1; i <= N; ++i) {
        K = read();

        if (g[K].L++) {
            pri_que.emplace(K, g[K].L, g[K].t);
        } else {
            if (num < M) {
                ++num;
            } else {
                list out = pri_que.top();
                while (!(g[out.K].L == out.L && g[out.K].t == out.t)) {
                    pri_que.pop();
                    out = pri_que.top();
                }
                memset(&g[out.K], 0, sizeof(struct gift));

                pri_que.pop();
                ++cnt;
            }

            g[K].t = i;
            pri_que.emplace(K, g[K].L, g[K].t);
        }
    }

    write(cnt);
    putchar('\n');
}

list::list(int k, int l, int time) {
    K = k;
    L = l;
    t = time;
}

bool cmp::operator()(const list &g1, const list &g2) {
    if (g1.L == g2.L) {
        return g1.t > g2.t;
    }
    return g1.L < g2.L;
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
