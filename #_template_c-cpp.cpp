#include <iostream>

#define ll long long

//fast integer read & write
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

void disable() { //C++ disables the io synchronization
    std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
}

//fast long readL & writeL
ll readL() {
    ll s = 0, f = 1;
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

void writeL(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        writeL(x / 10);
        putchar(x % 10 + '0');
    } else putchar(x + '0');
    return;
}
