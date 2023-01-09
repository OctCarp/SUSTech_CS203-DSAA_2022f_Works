#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll long long
#define MAX_SIZE 200005

using namespace std;

struct edge {
    int u;
    int v;
    int w;
} e[MAX_SIZE];

int n, m;

ll minus_sum = 0, sum = 0;

int t[MAX_SIZE];

int read();

void writeL(ll x);

bool cmp(const edge &e1, const edge &e2);

void init();

int find(int p);

bool un(int id);

void span_k();

int main() {
    init();

    span_k();

    ll ans = sum - minus_sum;
    writeL(ans);

    return 0;
}

void init() {
    n = read();
    m = read();

    for (int i = 0; i < m; ++i) {
        e[i].u = read();
        e[i].v = read();
        e[i].w = read();
        sum += max(e[i].w, 0);
    }

    sort(e, e + m, cmp);

    memset(t, -1, sizeof t);
}

void span_k() {
    int rd_num = 0;

    for (int i = 0; i < m; ++i) {
        if (un(i)) {
            if (++rd_num == n - 1) {
                break;
            }
        }
    }
}

bool un(int id) {
    int h1 = find(e[id].u);
    int h2 = find(e[id].v);

    if (h1 == h2) {
        return false;
    } else {
        t[h1] = h2;
        minus_sum += max(e[id].w, 0);

        return true;
    }
}

int find(int p) {
    if (t[p] != -1) {
        return find(t[p]);
    } else {
        return p;
    }
}

bool cmp(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
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

void writeL(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        writeL(x / 10);
        putchar(x % 10 + '0');
    } else putchar(x + '0');
    return;
}
