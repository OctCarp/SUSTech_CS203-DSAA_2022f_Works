#include <stdio.h>
#include <string.h>

#define BLK_SIZE 1450
#define BLK_NUM 1450

struct Block {
    int l, r, cnt;
    char c[2 * BLK_SIZE + 5];
} b[BLK_NUM + 5];

int cntB;

void init();

void split(int id);

void insert(char ch, int p);

void find(int p);

inline void trans(int blk, int i);

void transform(int l, int r);

void choose();

int main() {
    init();
    int n;
    scanf("%d", &n);

    while (n--) {
        choose();
    }

    return 0;
}

void init() {
    char s[2000005];
    scanf("%s", &s);
    int len = strlen(s);

    int id;
    for (int i = 0; i < len; ++i) {
        id = i / BLK_SIZE + 1;
        b[id].c[++b[id].cnt] = s[i];
    }

    id = (len - 1) / BLK_SIZE + 1;
    for (int i = 1; i <= id; ++i) {
        if (i > 1) {
            b[i].l = i - 1;
        }
        if (i < id) {
            b[i].r = i + 1;
        }
    }
    cntB = id;
}

void choose() {
    int opn;
    scanf("%d", &opn);

    switch (opn) {
        case 1: {
            char ch[2];
            int p;
            scanf("%s %d", &ch, &p);
            insert(ch[0], p);
            break;
        }
        case 2: {
            int p;
            scanf("%d", &p);
            find(p);
            break;
        }
        case 3: {
            int l, r;
            scanf("%d %d", &l, &r);
            transform(l, r);
            break;
        }
        default:
            break;
    }
}

void insert(char ch, int p) {
    int id = 1;
    while (b[id].cnt < p) {
        if (b[id].r != 0) {
            p -= b[id].cnt;
            id = b[id].r;
        } else break;
    }

    for (int i = b[id].cnt; i >= p; --i) {
        b[id].c[i + 1] = b[id].c[i];
    }
    b[id].c[p] = ch;
    ++b[id].cnt;

    if (b[id].cnt > BLK_SIZE * 2) split(id);
}

void split(int id) {
    int old = id;
    int spl = ++cntB;

    b[old].r = spl;
    b[spl].l = old;

    b[spl].cnt = b[old].cnt / 2;
    b[old].cnt -= b[spl].cnt;
    for (int i = 1; i <= b[spl].cnt; ++i) {
        b[spl].c[i] = b[old].c[b[old].cnt + i];
    }
}

void find(int p) {
    int id = 1;
    while (b[id].cnt < p) {
        if (b[id].r != 0) {
            p -= b[id].cnt;
            id = b[id].r;
        } else break;
    }
    char ch = b[id].c[p];

    putchar(ch);
    putchar('\n');
}

void transform(int l, int r) {
    int li, ri, p = 1;
    while (b[p].cnt < l) {
        l -= b[p].cnt;
        p = b[p].r;
    }
    li = p;

    p = 1;
    while (b[p].cnt < r) {
        r -= b[p].cnt;
        p = b[p].r;
    }
    ri = p;

    if (li = ri) {
        for (int i = l; i <= r; ++i) {
            trans(li, i);
        }
    } else {
        for (int i = l; i <= b[li].cnt; ++i) {
            trans(li, i);
        }

        int poi = b[li].r;
        while (poi != ri) {
            for (int j = 1; j < b[poi].cnt; ++j) {
                trans(poi, j);
            }
            poi = b[poi].r;
        }

        for (int i = 1; i <= r; ++i) {
            trans(ri, i);
        }
    }
}

void trans(int blk, int i) {
    b[blk].c[i] = (char) ('a' + 'z' - b[blk].c[i]);
}
