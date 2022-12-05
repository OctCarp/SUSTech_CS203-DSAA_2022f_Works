#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_SIZE 400005

using namespace std;

struct city {
    int d;
    bool is_v;
    bool has_k;
    vector<int> con;
} c[MAX_SIZE] = {0};

int ans = 0;

void init();

int bfsOnce(int root);

int main() {
    init();

    c[1].is_v = true;
    for (int lv1: c[1].con) {
        ans = max(ans, bfsOnce(lv1));
    }
    printf("%d", ans);

    return 0;
}

void init() {
    int n, u, v;

    scanf("%d", &n);
    while (--n) {
        scanf("%d %d", &u, &v);
        c[u].con.push_back(v);
        c[v].con.push_back(u);
    }

    int m, kyojin;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &kyojin);
        c[kyojin].has_k = true;
    }
}

int bfsOnce(int root) {
    queue<int> que;
    vector<int> ds;

    c[root].is_v = true;
    c[root].d = 1;
    que.push(root);

    int p;
    while (!que.empty()) {
        p = que.front();
        if (c[p].has_k) {
            ds.push_back(c[p].d);
        }

        for (int p_ch: c[p].con) {
            if (!c[p_ch].is_v) {
                c[p_ch].is_v = true;
                c[p_ch].d = c[p].d + 1;
                que.push(p_ch);
            }
        }

        que.pop();
    }

    int sz = ds.size();
    if (!sz) {
        return 0;
    } else {
        if (sz != 1) {
            for (int i = 1; i < sz; i++) {
                if (ds[i] <= ds[i - 1]) {
                    ds[i] = ds[i - 1] + 1;
                }
            }
        }
    }

    return ds[sz - 1];
}
