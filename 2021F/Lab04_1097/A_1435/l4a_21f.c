#include <stdio.h>
#include <malloc.h>

#define pn p->next

typedef struct Node {
    int c;
    int e;
    struct Node *next;
} node;

inline int read();

inline void write(int x);

int main() {
    int n = read();
    int m = read();
    node *p;
    node *head = (node *) malloc(sizeof(node));

    p = head;
    while (n--) {
        pn = (node *) malloc(sizeof(node));
        pn->c = read();
        pn->e = read();
        p = pn;
    }
    node *tail = (node *) malloc(sizeof(node));
    tail->c = (int) -1e9 - 1;
    tail->e = (int) -1e9 - 1;
    pn = tail;

    p = head;
    while (m--) {
        node *cur = (node *) malloc(sizeof(node));
        cur->c = read();
        cur->e = read();
        while (pn->e > cur->e) {
            p = pn;
        }
        if (pn->e == cur->e) {
            pn->c += cur->c;
            free(cur);
        } else {
            cur->next = pn;
            pn = cur;
        }
        p = pn;
    }

    int cnt = 0;
    p = head->next;
    while (p != tail) {
        if (p->c != 0) {
            ++cnt;
        }
        p = pn;
    }
    write(cnt);
    putchar('\n');

    p = head->next;
    while (p != tail) {
        if (p->c != 0) {
            write(p->c);
            putchar(' ');
            write(p->e);
            putchar('\n');
        }
        p = pn;
    }

    return 0;
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