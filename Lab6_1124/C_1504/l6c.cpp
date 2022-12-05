#include <cstdio>
#include <cstring>
#include <vector>

#define MAX_SIZE 200005

using namespace std;

int n, m;
bool legal;
bool is_v[MAX_SIZE];

struct city {
    int pa;
    int l;
    int r;
    int sz = 1;
    vector<int> con;

    void set(int l_in, int r_in) {
        l = max(0, l_in);
        r = min(sz, r_in);

        if (l > r) legal = false;
    }

    void inter(int l_in, int r_in) {
        l = max(l, l_in);
        r = min(r, r_in);

        if (l > r) legal = false;
    }
} c[MAX_SIZE];

struct constraint {
    int a;
    int b;
    int na;
} cons[MAX_SIZE * 2];

void init();

int buildDown(int root);

void constrain(int a, int b, int na, int k);

void unitedUp(int root);

bool checkOnce(int k);

int main() {
    init();
    buildDown(1);

    int ans = 0;

    int l = 0, r = n, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (checkOnce(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (ans) {
        printf("%d", ans);
    } else {
        printf("%d", -1);
    }

    return 0;
}

bool checkOnce(int k) {
    legal = true;
    memset(is_v, false, sizeof(is_v));

    for (int i = 0; i < m; ++i) {
        constrain(cons[i].a, cons[i].b, cons[i].na, k);
    }

    unitedUp(1);

    if (legal) {
        return (c[1].l <= k && k <= c[1].r);
    }

    return false;
}

void unitedUp(int root) {
    int l_sum = 0, r_sum = 1;

    for (int child: c[root].con) {
        if (child != c[root].pa) {
            unitedUp(child);

            l_sum += c[child].l;
            r_sum += c[child].r;
        }
    }

    if (is_v[root]) {
        c[root].inter(l_sum, r_sum);
    } else {
        c[root].set(l_sum, r_sum);
    }
}

void constrain(int a, int b, int na, int k) {
    if (b == c[a].pa) {
        if (is_v[a]) {
            c[a].inter(na, c[a].sz);
        } else {
            c[a].set(na, c[a].sz);
            is_v[a] = true;
        }
    } else {
        if (is_v[b]) {
            c[b].inter(0, k - na);
        } else {
            c[b].set(0, k - na);
            is_v[b] = true;
        }
    }
}

void init() {
    scanf("%d", &n);
    int T = n, u, v;
    while (--T) {
        scanf("%d %d", &u, &v);
        c[u].con.push_back(v);
        c[v].con.push_back(u);
    }
    c[1].pa = 0;

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &cons[i].a, &cons[i].b, &cons[i].na);
    }
}

int buildDown(int root) {
    for (int child: c[root].con) {
        if (child != c[root].pa) {
            c[child].pa = root;
            c[root].sz += buildDown(child);
        }
    }

    return c[root].sz;
}
