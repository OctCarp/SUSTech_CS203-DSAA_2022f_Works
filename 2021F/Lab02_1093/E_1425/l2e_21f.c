#include <stdio.h>

#define min(a, b) ((a) < (b)) ? (a) : (b)
#define MAX_SIZE 1000005

int a[MAX_SIZE], b[MAX_SIZE];
int n, T;

void init();

void check(int li, int ri);

int main() {
    init();

    int left, right;
    while (T--) {
        scanf("%d %d", &left, &right);
        check(left, right);
    }

    return 0;
}

void init() {
    scanf("%d %d", &n, &T);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i + 1]);
    }
}

void check(int li, int ri) {
    int l = li, r = ri;
    int len = (r - l + 1);
    int drift = len / 2;
    int num = 0;

    int p1 = l, p2 = l;
    while (drift) {
        if (a[p1 + drift - 1] > b[p2 + drift - 1]) {
            p2 += drift;
        } else {
            p1 += drift;
        }
        num += drift;
        drift = (len - num) / 2;
    }

    printf("%d\n", min(a[p1], b[p2]));
}
