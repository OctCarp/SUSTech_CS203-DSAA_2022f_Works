#include <cstdio>
#include <cstring>
#include <queue>
#include <numeric>
#include <algorithm>

#define MAX_SIZE 100005
#define MAX_K 105

using namespace std;

struct vertex {
    int co[MAX_K];
    vector<int> adj;
} vtx[MAX_SIZE];

struct my_que {
    int front = 0;
    int rear = 0;
    int que[MAX_SIZE];

    inline void push(int x);

    inline int poll();

    inline bool empty();
} qs[MAX_K];

int n, m, k, c;

bool is_v[MAX_SIZE];

int read();

void write(int x);

inline void connect(int u, int v);

void init();

void ck_cost(int clr);

void print_ans(int id);

int main() {
    init();

    for (int i = 1; i <= k; ++i) {
        ck_cost(i);
    }

    for (int i = 1; i <= n; ++i) {
        print_ans(i);
    }

    return 0;
}

void init() {
    n = read();
    m = read();
    k = read();
    c = read();

    int st_clr;
    for (int i = 1; i <= n; ++i) {
        st_clr = read();
        vtx[i].co[st_clr] = 0;
        qs[st_clr].push(i);
    }

    while (m--) {
        connect(read(), read());
    }
}

void ck_cost(int clr) {
    memset(is_v, false, sizeof is_v);

    for (int i = 0; i < qs[clr].front; ++i) {
        is_v[qs[clr].que[i]] = true;
    }

    int p;
    while (!qs[clr].empty()) {
        p = qs[clr].poll();

        for (int a: vtx[p].adj) {
            if (!is_v[a]) {
                is_v[a] = true;
                vtx[a].co[clr] = vtx[p].co[clr] + 1;
                qs[clr].push(a);
            }
        }
    }
}

void print_ans(int id) {
    sort(vtx[id].co + 1, vtx[id].co + 1 + k);

    int cost = accumulate(vtx[id].co + 1, vtx[id].co + 1 + c, 0);

    write(cost);
    putchar(' ');
}

void my_que::push(int x) {
    que[front++] = x;
}

int my_que::poll() {
    return que[rear++];
}

bool my_que::empty() {
    return front == rear;
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
