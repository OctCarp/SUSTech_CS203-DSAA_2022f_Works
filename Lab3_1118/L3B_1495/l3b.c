#include <stdio.h>

#define MAX_NUM 200000
#define pn s[p].next

int nums = 0;
long long m = 0, allPri = 0, cnt = 0;

struct Store {
    int pri;
    int next;
} s[MAX_NUM + 5];

void buyAll();

void buy();

int main() {
    int n = 0;
    scanf("%d", &n);
    scanf("%lld", &m);
    nums = n;

    int price = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &price);
        allPri += price;
        s[i].pri = price;
        s[i].next = i + 1;
    }
    s[n - 1].next = 0;

    buy();
    printf("%lld", cnt);
}

void buy() {
    int p = nums - 1;
    int price = s[pn].pri;
    buyAll();

    while (nums > 1) {
        if (m > price) {
            m -= price;
            ++cnt;
            p = pn;
            price = s[pn].pri;
        } else if (m < price) {
            allPri -= price;
            --nums;
            buyAll();
            pn = s[pn].next;
            price = s[pn].pri;
        } else {
            m -= price;
            ++cnt;
            break;
        }
    }
    cnt += m / s[p].pri;
}

inline void buyAll() {
    cnt += (m / allPri) * nums;
    m %= allPri;
}

