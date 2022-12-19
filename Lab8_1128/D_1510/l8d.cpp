#include <cstdio>
#include <algorithm>
#include <functional>

#define ll long long
#define MAX_SIZE 1000005

using namespace std;

int a[MAX_SIZE];
ll suf_sum[MAX_SIZE];

int n;

int read();

void init();

inline bool ck_gra();

bool ck_simple();

inline bool ck_tree();

int main() {
    init();

    bool is_gra = ck_gra();
    bool is_simple = is_gra && ck_simple();
    bool is_tree = is_simple && ck_tree();

    printf(is_gra ? "YES\n" : "NO\n");
    printf(is_simple ? "YES\n" : "NO\n");
    printf(is_tree ? "YES" : "NO");

    return 0;
}

void init() {
    n = read();

    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    sort(a + 1, a + 1 + n, greater<int>());

    suf_sum[n + 1] = 0ll;
    for (int i = n; i >= 1; --i) {
        suf_sum[i] = suf_sum[i + 1] + a[i];
    }
}

bool ck_gra() {
    return !(suf_sum[1] & 1);
}

bool ck_simple() {
    ll pre_sum = 0ll;

    ll one_to_i;
    int i_to_k;
    for (int i = 1, k = n; i <= n; ++i, ++k) {
        while (k > i && a[k] < i) --k;

        one_to_i = (ll) i * (i - 1);
        i_to_k = i * (k - i);

        pre_sum += a[i];
        if (pre_sum > one_to_i + i_to_k + suf_sum[k + 1]) return false;
    }

    return true;
}

bool ck_tree() {
    return n == 1 || (a[n] && suf_sum[1] == (ll) (n - 1) << 1);
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
