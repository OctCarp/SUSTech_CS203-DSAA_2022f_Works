#include <cstdio>
#include <queue>

#define ll long long
#define pii pair<int, int>
#define MAX_SIZE 100005
#define MAX_LEN ((ll)10e14 + 5)

using namespace std;

struct city {
    bool is_v = false;
    ll rd = MAX_LEN;
    vector<pii > chs_co;
} c[MAX_SIZE];

struct cmp {
    bool operator()(const int &id_1, const int &id_2);
};

int n, m;

void init();

void bfs(int root);

int main() {
    init();

    bfs(1);

    printf("%lld", c[n].rd == MAX_LEN ? -1 : c[n].rd);

    return 0;
}

void init() {
    scanf("%d %d", &n, &m);

    int u, v, w;
    while (m--) {
        scanf("%d %d %d", &u, &v, &w);
        c[u].chs_co.emplace_back(v, w);
    }
}

void bfs(int root) {
    priority_queue<int, vector<int>, cmp> min_ids;

    c[root].rd = 0;
    min_ids.push(root);

    int p;
    while (!min_ids.empty()) {
        p = min_ids.top();

        if (!c[p].is_v) {
            c[p].is_v = true;

            for (pair<int, int> ch_co: c[p].chs_co) {
                if (!c[ch_co.first].is_v) {
                    c[ch_co.first].rd = min(c[ch_co.first].rd, ch_co.second + c[p].rd);

                    min_ids.push(ch_co.first);
                }
            }
        }

        min_ids.pop();
    }
}

bool cmp::operator()(const int &id_1, const int &id_2) {
    return c[id_1].rd > c[id_2].rd;
}
