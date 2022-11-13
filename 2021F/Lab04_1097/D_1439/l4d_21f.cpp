#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_NUM  2000005

using namespace std;

struct Node {
    int val;
    int prev;
    int next;
} ns[MAX_NUM];

int read();

void write(int x);

bool cmp(const int &i1, const int &i2);

int main() {
    int n = read();
    int index[n];

    int value = 0;
    for (int i = 0; i < n; ++i) {
        value = read();
        ns[i].val = value;
        index[i] = i;
    }
    sort(index, index + n, cmp);

    ns[index[0]].prev = -1;
    for (int i = 1; i < n; ++i) {
        ns[index[i]].prev = index[i - 1];
        ns[index[i - 1]].next = index[i];
    }
    ns[index[n - 1]].next = -1;

    int iPrev, iNext, ans;
    for (int i = 0; i < n; ++i) {
        iPrev = ns[i].prev;
        iNext = ns[i].next;
        if (iPrev != -1 && iNext != -1) {
            ans = min(abs(ns[i].val - ns[iPrev].val), abs(ns[i].val - ns[iNext].val));
        } else {
            if (iPrev != -1) {
                ans = abs(ns[i].val - ns[iPrev].val);
            } else if (iNext != -1) {
                ans = abs(ns[i].val - ns[iNext].val);
            } else break;
        }
        write(ans);
        putchar(' ');

        ns[iNext].prev = iPrev;
        ns[iPrev].next = iNext;
    }

    return 0;
}

bool cmp(const int &i1, const int &i2) {
    return ns[i1].val < ns[i2].val;
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
