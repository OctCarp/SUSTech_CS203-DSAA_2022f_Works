#include <stdio.h>

#define ll long long

const ll MIN_VAL = -1e10;
const ll MAX_VAL = 1e10;

inline ll calc(int i, int j);

ll byCol(int n, ll flg);

void find();

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        find();
    }

    return 0;
}

void find() {
    int N;
    ll M;
    scanf("%d %lld", &N, &M);

    ll l = MIN_VAL;
    ll r = MAX_VAL;

    while (l <= r) {
        ll mid = (l + r) / 2;
        ll count = byCol(N, mid);

        if (count >= M) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%lld\n", l - 1);
}

ll byCol(int n, ll flg) {
    ll cnt = 0ll;

    for (int j = 1; j <= n; ++j) {
        int u = 1, d = n;
        int mid;

        while (u <= d) {
            mid = (u + d) / 2;
            if (flg > calc(mid, j)) {
                u = mid + 1;
            } else {
                d = mid - 1;
            }
        }

        cnt += u - 1;
    }

    return cnt;
}

ll calc(int i, int j) {
    return (ll) i * i + (ll) j * j + (ll) (i - j) * 12345 + (ll) i * j;
}
