#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

#define MAX_SIZE 50005
#define pii pair<int, int>

using namespace std;

struct vertex {
    int scc = 0;
    vector<int> adj;
    vector<int> r_adj;
} vtx[MAX_SIZE];

int n, m, S;
int scc_cnt = 0;

bool is_v[MAX_SIZE];

vector<pii > edges;
vector<int> out;

void init();

void dfs_rev(int start);

void dfs(int start);

void find_scc();

int ck_in_deg();

int main() {
    init();

    find_scc();

    printf("%d", ck_in_deg());

    return 0;
}

void init() {
    scanf("%d %d %d", &n, &m, &S);

    int u, v;
    while (m--) {
        scanf("%d %d", &u, &v);

        edges.emplace_back(u, v);

        vtx[u].adj.push_back(v);
        vtx[v].r_adj.push_back(u);
    }
}

void find_scc() {
    memset(is_v, false, sizeof is_v);
    for (int i = 1; i <= n; ++i) {
        if (!is_v[i]) {
            dfs_rev(i);
        }
    }

    reverse(out.begin(), out.end());

    memset(is_v, false, sizeof is_v);
    for (int h: out) {
        if (!is_v[h]) {
            ++scc_cnt;
            dfs(h);
        }
    }
}

int ck_in_deg() {
    bool deg_in[MAX_SIZE] = {false};

    for (pii e: edges) {
        if (vtx[e.first].scc != vtx[e.second].scc) {
            deg_in[vtx[e.second].scc] = true;
        }
    }

    int ans = 0;
    for (int i = 1; i <= scc_cnt; ++i) {
        if (!deg_in[i]) ++ans;
    }

    if (!deg_in[vtx[S].scc]) --ans;

    return ans;
}

void dfs_rev(int start) {
    is_v[start] = true;

    for (int r_a: vtx[start].r_adj) {
        if (!is_v[r_a]) {
            dfs_rev(r_a);
        }
    }

    out.push_back(start);
}

void dfs(int start) {
    is_v[start] = true;
    vtx[start].scc = scc_cnt;

    for (int a: vtx[start].adj) {
        if (!is_v[a]) {
            dfs(a);
        }
    }
}
