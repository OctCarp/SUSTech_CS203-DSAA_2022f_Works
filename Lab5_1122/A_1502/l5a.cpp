#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX_SP (1000 + 5)
#define MAX_LEN (100 + 5)
#define MAX_len (10 + 5)

using namespace std;

struct match {
    int i;
    int l, r;
    int next;
} m[MAX_SP];

struct way {
    int i;
    int start;
};

vector<way> ways;

bool cmp(const match &m1, const match &m2);

void checkOnce();

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        checkOnce();
    }

    return 0;
}

void checkOnce() {
    ways.clear();
    char t[MAX_LEN], s[MAX_len];
    int n, tl, sl, cnt = 0;

    scanf("%s", &t);
    tl = strlen(t);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", &s);
        sl = strlen(s);

        for (int j = 0; j <= tl - sl; ++j) {
            for (int k = 0; k < sl; ++k) {
                if (s[k] != t[k + j]) {
                    break;
                }
                if (k == sl - 1) {
                    m[++cnt] = {i + 1, j + 1, j + sl, 0};
                }
            }
        }
    }

    sort(m + 1, m + cnt + 1, cmp);

    for (int i = 0; i <= cnt; ++i) {
        m[i].next = i + 1;
    }
    m[cnt].next = -1;
    if (cnt == 0) {
        printf("%d\n", -1);
        return;
    }

    int pi = 0;
    int pn;
    while (m[pi].next != -1 && m[m[pi].next].next != -1) {
        pn = m[pi].next;
        if (m[m[pi].next].l == m[m[pn].next].l) {
            m[pi].next = m[pn].next;
            --cnt;
        } else {
            pi = m[pi].next;
        }
    }

    int p = m[0].next;
    int tr = 0;
    int rMax = 0;
    int ip;
    while (tr < tl) {
        while (m[p].l <= tr + 1) {
            if (m[p].r > rMax) {
                ip = p;
                rMax = m[p].r;
            }
            if (m[p].next != -1) {
                p = m[p].next;
            } else {
                if (rMax < tl) {
                    printf("%d\n", -1);
                    return;
                }
                break;
            }
        }

        if (tr >= rMax) {
            printf("%d\n", -1);
            return;
        } else {
            tr = rMax;
        }

        ways.push_back({m[ip].i, m[ip].l});
    }

    printf("%d\n", ways.size());
    for (int i = 0; i < ways.size(); ++i) {
        printf("%d %d\n", ways[i].i, ways[i].start);
    }
}

bool cmp(const match &m1, const match &m2) {
    if (m1.l == m2.l) {
        return m1.r < m2.r;
    }
    return m1.l < m2.l;
}
