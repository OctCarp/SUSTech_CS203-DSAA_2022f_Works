#include <cstdio>
#include <algorithm>

#define MAX_SIZE 1000005

using namespace std;

typedef struct my_pair {
    int x;
    int y;
} m_p;

struct grid {
    int c;
    bool is_v = false;
};

int T;

int read();

void write(int x);

inline bool ck_group(grid *p, int color);

void ck_once();

int main() {
    T = read();
    while (T--) {
        ck_once();
    }

    return 0;
}

void ck_once() {
    int n = read();
    int m = read();

    grid mat[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mat[i][j].c = read();
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!mat[i][j].is_v) {
                m_p que[MAX_SIZE];
                int front = 0, rear = 0;

                que[front++] = {i, j};
                mat[i][j].is_v = true;
                int color = mat[i][j].c;

                while (front != rear) {
                    m_p p = que[rear++];

                    int ux = max(0, p.x - 1);
                    int dx = min(n - 1, p.x + 1);
                    int ly = p.y == 0 ? m - 1 : p.y - 1;
                    int ry = p.y == m - 1 ? 0 : p.y + 1;

                    if (ck_group(&mat[ux][p.y], color)) {
                        que[front++] = {ux, p.y};
                    }
                    if (ck_group(&mat[dx][p.y], color)) {
                        que[front++] = {dx, p.y};
                    }
                    if (ck_group(&mat[p.x][ly], color)) {
                        que[front++] = {p.x, ly};
                    }
                    if (ck_group(&mat[p.x][ry], color)) {
                        que[front++] = {p.x, ry};
                    }
                }

                ++cnt;
            }
        }
    }

    write(cnt);
    putchar('\n');
}

bool ck_group(grid *p, int color) {
    if (!p->is_v && p->c == color) {
        p->is_v = true;
        return true;
    } else {
        return false;
    }
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
