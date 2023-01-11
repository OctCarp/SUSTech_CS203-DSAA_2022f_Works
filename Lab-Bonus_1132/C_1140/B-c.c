#include <stdio.h>
#include <math.h>
#include <malloc.h>

#define pn p->next
#define MAX_C (10005)
#define MAX_E (1000000005)

typedef struct term {
    int c;
    int e;
    struct term *next;
} term;

int T;

inline int read();

inline void write(int x);

inline void write_first(int c, int e);

inline void write_term(int c, int e);

void combine_once();

int main() {
    T = read();
    while (T--) {
        combine_once();
    }

    return 0;
}

void combine_once() {
    term *head = (term *) malloc(sizeof(term));
    head->c = 0;
    head->e = -1;
    term *tail = (term *) malloc(sizeof(term));
    tail->c = MAX_C;
    tail->e = MAX_E;

    term *p;

    p = head;
    int n = read();
    while (n--) {
        pn = (term *) malloc(sizeof(term));
        pn->c = read();
        pn->e = read();
        p = pn;
    }
    pn = tail;

    p = head;
    int m = read();
    while (m--) {
        term *cur = (term *) malloc(sizeof(term));
        cur->c = read();
        cur->e = read();
        while (pn->e < cur->e) {
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

    term *del;

    p = head;
    while (p != tail) {
        if (!pn->c) {
            del = pn;
            pn = pn->next;
            free(del);
        } else {
            p = pn;
        }
    }

    if (head->next == tail) {
        write(0);
        putchar('\n');

        free(head);
        free(tail);
        return;
    }

    p = head->next;
    write_first(p->c, p->e);
    p = pn;
    free(head->next);

    while (p != tail) {
        if (p->c) {
            write_term(p->c, p->e);
        }
        del = p;
        p = pn;
        free(del);
    }
    putchar('\n');

    free(head);
    free(tail);
}

void write_first(int c, int e) {
    if (!e) {
        write(c);
        return;
    }
    if (abs(c) != 1) write(c);
    if (c == -1) putchar('-');
    putchar('x');
    if (e != 1) {
        putchar('^');
        write(e);
    }
}

void write_term(int c, int e) {
    if (c > 0)putchar('+');
    if (c == -1) putchar('-');
    if (abs(c) != 1) write(c);

    putchar('x');
    if (e != 1) {
        putchar('^');
        write(e);
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
