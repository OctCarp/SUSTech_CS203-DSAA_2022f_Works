//This is just a try for C++ syntax, in Java style

#include <cstdio>
#include <iostream>

#define pn p->next

int read();

void write(int x);

struct ListNode {
    int c;
    int e;
    ListNode *next;

    ListNode(int c, int e) {
        this->c = c;
        this->e = e;
        next = nullptr;
    }
};

int main() {
    int n = read();
    int m = read();
    int len = 0;
    ListNode *p;
    ListNode *head = new ListNode((int) -1e9 - 1, (int) -1e9 - 1);

    p = head;
    for (int i = 0; i < n; i++) {
        pn = new ListNode(read(), read());
        p = pn;
    }
    ListNode *tail = new ListNode((int) 1e9 + 1, (int) 1e9 + 1);
    pn = tail;

    p = head;
    for (int i = 0; i < m; i++) {
        ListNode *x = new ListNode(read(), read());
        while (true) {
            if (x->e < pn->e) break;
            p = pn;
        }
        if (x->e == p->e) {
            p->c += x->c;
        } else {
            x->next = pn;
            pn = x;
        }
    }
    ListNode *realH = head->next;

    p = realH;
    while (p != tail) {
        if (p->c != 0) {
            len++;
        }
        p = pn;
    }
    write(len);
    printf("\n");

    p = realH;
    while (p != tail) {
        if (p->c != 0) {
            write(p->c);
            printf(" ");
            write(p->e);
            printf("\n");
        }
        p = pn;
    }
}

int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (!std::isdigit(ch)) {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (std::isdigit(ch)) {
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
