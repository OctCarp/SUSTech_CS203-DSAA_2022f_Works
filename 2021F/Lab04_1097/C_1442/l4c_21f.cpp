#include <iostream>

using namespace std;

typedef struct Node {
    int w;
    bool isHead;
    struct Node *next;
    struct Node *end;

    Node(int w) {
        this->w = w;
        isHead = true;
        end = this;
    }
} node;

int read();

void write(int x);

int n, p, q;

int main() {
    n = read();
    p = read();
    q = read();
    node *ns[n + 5];

    for (int i = 1; i <= n; ++i) {
        ns[i] = new node(read());
    }

    int h, t;
    while (p--) {
        h = read();
        t = read();
        ns[h]->end->next = ns[t];
        ns[h]->end = ns[t]->end;
        ns[t]->isHead = false;
    }

    node *po;
    bool have;
    for (int i = 1; i < n; ++i) {
        po = ns[i];
        if (po->isHead) {
            have = true;
            for (int j = 0; j < q - 1; ++j) {
                if (po->next == nullptr) {
                    have = false;
                    break;
                } else {
                    po = po->next;
                }
            }

            if (have) {
                write(po->w);
                putchar(' ');
            }
        }
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