#include <cstdio>
#include <algorithm>
#include <cstring>

#define ll long long
#define MAX_SIZE 10005

using namespace std;

struct road {
    int u;
    int v;
    int w;
} rd[MAX_SIZE];

int n, m;

ll ans = 0;

int t[MAX_SIZE];

int read();

void writeL(ll x);

bool cmp(const road &r1, const road &r2);

void init();

int find(int p);

bool un(int id);

void span_k();

int main() {
    init();

    span_k();

    writeL(ans);

    return 0;
}

void init() {
    n = read();
    m = read();

    for (int i = 0; i < m; ++i) {
        rd[i].u = read();
        rd[i].v = read();
        rd[i].w = read();
    }

    sort(rd, rd + m, cmp);

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
    int h1 = find(rd[id].u);
    int h2 = find(rd[id].v);

    if (h1 == h2) {
        return false;
    } else {
        if (t[h1] < t[h2]) {
            t[h2] = h1;
        } else {
            t[h1] = h2;
        }
        ans += rd[id].w;

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

bool cmp(const road &r1, const road &r2) {
    return r1.w < r2.w;
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
