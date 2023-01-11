#include <stdio.h>
#include <string.h>

#define MAX_SIZE (150005)

struct node {
    int pa;
    int l;
    int r;
} t[MAX_SIZE];

int T;

int read();

int ck_once();

int main() {
    T = read();
    while (T--) {
        printf("%s\n", ck_once() ? "Yes" : "No");
    }

    return 0;
}

int ck_once() {
    memset(t, 0, sizeof t);
    int n = read();

    for (int i = 1; i <= n; ++i) {
        t[i].l = read();
        t[i].r = read();
        t[t[i].l].pa = i;
        t[t[i].r].pa = i;
    }

    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (!t[i].pa) {
            root = i;
            break;
        }
    }

    int que[MAX_SIZE * 2];
    int front = 0, rear = 0;

    que[front++] = root;

    int p;
    while (front != rear) {
        p = que[rear++];

        if (p) {
            que[front++] = t[p].l;
            que[front++] = t[p].r;
        } else break;
    }

    while (front != rear) {
        p = que[rear++];

        if (p) return 0;
    }
    return 1;
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
