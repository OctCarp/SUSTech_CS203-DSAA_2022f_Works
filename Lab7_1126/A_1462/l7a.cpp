#include <cstdio>
#include <algorithm>
#include <vector>

#define ll long long
#define MAX_SIZE 500005

using namespace std;

int a[MAX_SIZE], b[MAX_SIZE];

struct node {
    int ai;
    int bi;
    ll val;

    node() {}

    node(int ia, int ib) {
        ai = ia;
        bi = ib;
        val = (ll) a[ia] * b[ib];
    }
} heap[MAX_SIZE * 2];

int sz = 0;

int n, m, k;

vector<ll> ans;

void init();

void ins(int ia, int ib);

ll pop();

int main() {
    init();

    for (int i = 0; i < n; ++i) {
        ins(i, 0);
    }

    int ia, ib;
    while (k--) {
        ia = heap[1].ai;
        ib = heap[1].bi;
        ans.push_back(pop());

        if (++ib < m) {
            ins(ia, ib);
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        printf("%lld ", ans[i]);
    }

    return 0;
}

void init() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }

    sort(a, a + n);
    sort(b, b + m);
}

void ins(int ia, int ib) {
    heap[++sz] = node(ia, ib);
    int p = sz;

    while (p > 1) {
        if (heap[p].val < heap[p >> 1].val) {
            swap(heap[p], heap[p >> 1]);
            p = p >> 1;
        } else break;
    }
}

ll pop() {
    ll min_val = heap[1].val;

    heap[1] = heap[sz--];
    int s = 2, t = 1;
    while (s <= sz) {
        if (s <= sz - 1 && heap[s + 1].val < heap[s].val) {
            ++s;
        }
        if (heap[s].val < heap[t].val) {
            swap(heap[s], heap[t]);
            t = s;
            s = s << 1;
        } else break;
    }

    return min_val;
}
