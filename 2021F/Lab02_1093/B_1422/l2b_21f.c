#include <stdio.h>

#define ll long long

void calc(int n);

int main() {
    int T;
    scanf("%d", &T);

    int x;
    while (T--) {
        scanf("%d", &x);
        calc(x);
    }

    return 0;
}

void calc(int n) {
    ll sum = (ll) n * (n + 1) * (n + 2) / 6;

    printf("%lld\n", sum);
}
