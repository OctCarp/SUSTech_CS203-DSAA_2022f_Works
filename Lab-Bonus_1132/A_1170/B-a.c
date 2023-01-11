#include <stdio.h>

#define max(a, b) ((a)>(b)?(a):(b))
#define MIN_DIFF (-100005)

int T;

int read();

void write(int x);

void find_once();

int main() {
    T = read();
    while (T--) {
        find_once();
    }

    return 0;
}

void find_once() {
    int n = read();
    int a[n];

    for (int i = 0; i < n; ++i) {
        a[i] = read();
    }

    int l = 0, diff = MIN_DIFF;
    for (int i = 0; i < n; ++i) {
        diff = max(diff, l - a[i]);
        l = max(l, a[i]);
    }

    write(diff);
    putchar(' ');
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

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        write(x / 10);
        putchar(x % 10 + '0');
    } else putchar(x + '0');
    return;
}
