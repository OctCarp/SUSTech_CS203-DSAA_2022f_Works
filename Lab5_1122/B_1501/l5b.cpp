#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

#define ull unsigned long long
#define MAX_SIZE 300005
#define base 2333ull

using namespace std;

ull p[MAX_SIZE];

struct hashMap {
    int len;
    vector<ull> hash;

    void init(char *sin) {
        len = strlen(sin);

        hash.push_back(0ull);
        for (int i = 0; i < len; ++i) {
            hash.push_back(hash.back() * base + (sin[i] - 'a'));
        }
        hash.push_back(0ull);
    }

    ull checkHash(int l, int r) {
        return hash[r] - hash[l - 1] * p[r - l + 1];
    }

} ha1, ha2, re1;

void init();

bool checkByLen(int k);

int main() {
    init();
    int s = min(ha1.len, ha2.len);

    int olen = ceil((double) s / 2), elen = s / 2 + 1;
    int odd[olen], even[elen];
    for (int i = 0; i < olen; ++i) {
        odd[i] = i * 2 + 1;
    }
    for (int i = 0; i < elen; ++i) {
        even[i] = i * 2;
    }

    int ans = 0;

    int l, r, m;
    l = 0, r = olen - 1;
    while (l <= r) {
        m = (l + r) / 2;
        if (checkByLen(odd[m])) {
            ans = max(ans, odd[m]);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    l = 0, r = elen - 1;
    while (l <= r) {
        m = (l + r) / 2;
        if (checkByLen(even[m])) {
            ans = max(ans, even[m]);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    if (ans == 0) {
        printf("%d", -1);
    } else {
        printf("%d", ans);
    }

    return 0;
}

bool checkByLen(int k) {
    set<ull> pals;

    int l, r;
    ull ha, re;
    for (int i = 1; i <= ha1.len - (k - 1); ++i) {
        l = i;
        r = i + (k - 1);
        ha = ha1.checkHash(l, r);
        re = re1.checkHash(ha1.len - r + 1, ha1.len - l + 1);
        if (ha == re) {
            pals.insert(ha);
        }
    }

    for (int i = 1; i <= ha2.len - (k - 1); ++i) {
        l = i;
        r = i + (k - 1);
        if (pals.find(ha2.checkHash(l, r)) != pals.end()) {
            return true;
        }
    }
    return false;
}

void init() {
    p[0] = 1;
    for (int i = 1; i < MAX_SIZE; ++i) {
        p[i] = p[i - 1] * base;
    }

    char s1[MAX_SIZE], s2[MAX_SIZE];
    scanf("%s%s", s1, s2);

    ha1.init(s1);
    ha2.init(s2);

    char sre1[ha1.len];
    for (int i = 0; i < ha1.len; ++i) {
        sre1[i] = s1[ha1.len - 1 - i];
    }
    re1.init(sre1);
}
