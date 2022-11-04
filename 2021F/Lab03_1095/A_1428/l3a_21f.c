#include <stdio.h>

#define ll long long

int read();

void write(int x);

void writeL(ll x);

void readMerge();

int main() {
    int T = read();

    while (T--) {
        readMerge();
    }

    return 0;
}

void readMerge() {
    int al = read();
    int bl = read();

    int a[al], b[bl], c[al + bl];
    for (int i = 0; i < al; ++i) {
        a[i] = read();
    }
    for (int i = 0; i < bl; ++i) {
        b[i] = read();
    }

    int pa = 0, pb = 0, pc = 0;
    ll rev = 0ll;
    while (pa < al && pb < bl) {
        if (a[pa] > b[pb]) {
            rev += al - pa;
            c[pc++] = b[pb++];
        } else {
            c[pc++] = a[pa++];
        }
    }
    while (pa < al) {
        c[pc++] = a[pa++];
    }
    while (pb < bl) {
        c[pc++] = b[pb++];
    }

    writeL(rev);
    putchar('\n');
    for (int i = 0; i < al + bl - 1; ++i) {
        write(c[i]);
        putchar(' ');
    }
    write(c[al + bl - 1]);
    putchar('\n');
}

int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
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

void writeL(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        writeL((ll) x / 10);
        putchar(x % 10 + '0');
    } else putchar(x + '0');
    return;
}
