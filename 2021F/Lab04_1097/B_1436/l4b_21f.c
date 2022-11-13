#include <stdio.h>

#define MAX_SIZE 2000005

struct stu {
    int id;
    int next;
} ss[MAX_SIZE];

int n, m;

inline int read();

inline void write(int x);

void init();

int main() {
    n = read();
    m = read();

    init();

    int cnt = 0;
    int p = 0;
    int out = 1;
    while (cnt < n - 1) {
        write(ss[out].id);
        putchar(' ');
        ss[p].next = ss[out].next;
        ++cnt;

        for (int i = 0; i < m - 1; ++i) {
            if (ss[p].next != -1) {
                p = ss[p].next;
            } else {
                p = 0;
                break;
            }
        }
        if (ss[p].next == -1) {
            p = 0;
        }
        out = ss[p].next;
    }
    write(ss[out].id);

    return 0;
}

void init() {
    for (int i = 1; i <= n; ++i) {
        ss[i].id = i;
        ss[i - 1].next = i;
    }
    ss[n].next = -1;
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