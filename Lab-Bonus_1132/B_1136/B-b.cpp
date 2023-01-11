#include <cstdio>
#include <algorithm>

using namespace std;

int L, n, m;

int read();

void write(int x);

int ck_people(const int d[], int avg);

void run_once();

int main() {
    while (scanf("%d %d %d", &L, &n, &m) != EOF) {
        run_once();
    }

    return 0;
}

void run_once() {
    int d[n + 2];

    d[0] = 0;
    for (int i = 1; i <= n; ++i) {
        d[i] = read();
    }
    d[n + 1] = L;

    sort(d, d + n + 2);

    int l = 0, r = L;
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (ck_people(d, mid) > m) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    while (ck_people(d, mid) > m) {
        ++mid;
    }

    write(mid);
    putchar('\n');
}

int ck_people(const int d[], int avg) {
    int num = 0;

    int low = 0, up = 1;
    while (up <= n + 1) {
        if (d[up] - d[low] <= avg) {
            ++up;
        } else {
            if (up - low == 1) return m + 1;

            low = up - 1;
            ++num;
        }
    }

    return ++num;
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
