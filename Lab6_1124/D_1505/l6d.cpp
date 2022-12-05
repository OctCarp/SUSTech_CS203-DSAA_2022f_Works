#include <cstdio>
#include <vector>

#define ll long long
#define MAX_SIZE 200005

using namespace std;

bool is_v[MAX_SIZE] = {false};
int n, top, first = 0, second = 0;
ll ans = 0;

struct node {
    int p;
    int pa;
    int max_ch;
    int max_val;
    bool inner;
    vector<int> con;
} t[MAX_SIZE] = {0};

int init();

void buildDown(int root);

void assignDown(int root, bool is_top_max_ch);

int main() {
    top = init();
    buildDown(top);

    if (t[top].con.size() == 1) {
        assignDown(top, true);
        ans += first;
    } else {
        is_v[top] = true;
        t[t[top].max_ch].max_val = first;

        assignDown(t[top].max_ch, true);

        for (int child: t[top].con) {
            if (!is_v[child]) {
                assignDown(child, false);
            }
        }

        ans += (first - second);
    }

    printf("%lld", ans);

    return 0;
}

void assignDown(int root, bool is_top_max_ch) {
    is_v[root] = true;

    int cur = root;
    while (t[cur].inner) {
        is_v[t[cur].max_ch] = true;

        for (int child: t[cur].con) {
            if (!is_v[child]) {
                assignDown(child, is_top_max_ch);
            }
        }

        cur = t[cur].max_ch;
    }

    if (!is_top_max_ch) {
        second = max(second, t[root].max_val);
    }

    ans += t[root].max_val;
}

int init() {
    int first_id = 0;

    scanf("%d", &n);
    int T = n, u, v;
    while (--T) {
        scanf("%d %d", &u, &v);
        t[u].con.push_back(v);
        t[v].con.push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i].p);

        if (t[i].p > first) {
            first = t[i].p;
            first_id = i;
        }
    }

    return first_id;
}

void buildDown(int root) {
    t[root].max_val = t[root].p;

    for (int child: t[root].con) {
        if (child != t[root].pa) {
            t[root].inner = true;
            t[child].pa = root;

            buildDown(child);

            if (t[child].max_val > t[t[root].max_ch].max_val) {
                t[root].max_val = t[child].max_val;
                t[root].max_ch = child;
            }
        }
    }

    t[root].max_val = max(t[root].max_val, t[root].p);
}
