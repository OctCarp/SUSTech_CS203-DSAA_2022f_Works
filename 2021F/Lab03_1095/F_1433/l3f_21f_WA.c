#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define ll long long
#define MAX_SIZE (int) (2e5 + 5)

int n, p, q;

struct pl {
    int h;
    int s;
    int diff;
} pls[MAX_SIZE];

ll pow2(int index);

void mergeByDiff(int l, int m, int r);

void mergeSortByDiff(int l, int r);

int main() {
    ll ans = 0ll;
    scanf("%d %d %d", &n, &p, &q);

    int H, S;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &H, &S);
        pls[i].h = H;
        pls[i].s = S;
        pls[i].diff = H - S;
    }

    if (q == 0) {
        for (int i = 0; i < n; ++i) {
            ans += pls[i].s;
        }

        printf("%lld", ans);

        return 0;
    }

    mergeSortByDiff(0, n - 1);

    ll maxDiff = 0ll;

    int id = -1;
    if (p > 0) {
        ll pow = pow2(p);
        ll ph, ps;
        for (int i = 0; i < n; ++i) {
            ph = (ll) pls[i].h * pow;
            ps = pls[i].s;
            if (ph - ps > maxDiff) {
                maxDiff = ph - ps;
                id = i;
            }
        }
    }
    int flg;
    if (id >= q - 1) {
        flg = 1;
    } else {
        flg = 0;
    }

    if (flg) {
        for (int i = 0; i < q - 1; ++i) {
            ans += max(pls[i].h, pls[i].s);
        }
        for (int i = q - 1; i < n; ++i) {
            if (i == id) {
                ans += pls[id].s + maxDiff;
            } else {
                ans += pls[i].s;
            }
        }
    } else {
        for (int i = 0; i < q; ++i) {
            if (i == id) {
                ans += pls[id].s + maxDiff;
            } else {
                ans += max(pls[i].h, pls[i].s);
            }
        }
        for (int i = q; i < n; ++i) {
            ans += pls[i].s;
        }
    }

    printf("%lld\n", ans);

    return 0;
}

ll pow2(int index) {
    ll x = 1ll;
    for (int i = 0; i < index; ++i) {
        x *= 2;
    }
    return x;
}

void mergeByDiff(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    struct pl L[n1], R[n2];

    memcpy(&L[0], &pls[l], n1 * sizeof(struct pl));
    memcpy(&R[0], &pls[m + 1], n2 * sizeof(struct pl));

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].diff >= R[j].diff) {
            pls[k++] = L[i++];
        } else {
            pls[k++] = R[j++];
        }
    }

    while (i < n1) {
        pls[k++] = L[i++];
    }
    while (j < n2) {
        pls[k++] = R[j++];
    }
}

void mergeSortByDiff(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortByDiff(l, m);
        mergeSortByDiff(m + 1, r);
        mergeByDiff(l, m, r);
    }
}