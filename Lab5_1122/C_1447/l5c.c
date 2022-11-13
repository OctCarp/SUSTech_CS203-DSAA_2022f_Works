#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

char alps[MAX_LEN + 5];
int len;

struct state {
    int alpha[26];
} s[MAX_LEN + 5];

inline void write(int x);

void init();

void makeFunc();

int main() {
    scanf("%s", alps);
    len = strlen(alps);

    init();
    makeFunc();

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 25; ++j) {
            write(s[i].alpha[j]);
            putchar(' ');
        }
        write(s[i].alpha[25]);
        putchar('\n');
    }

    return 0;
}

void init() {
    for (int j = 0; j < 26; ++j) {
        if (j + 'a' == alps[0]) {
            s[0].alpha[j] = 1;
            break;
        }
    }
}

void makeFunc() {
    int x = 0;
    int *cur;
    char p;

    for (int i = 1; i < len; ++i) {
        p = alps[i];
        cur = s[i].alpha;

        for (int j = 0; j < 26; ++j) {
            if (j + 'a' == p) {
                cur[j] = i + 1;
            } else {
                cur[j] = s[x].alpha[j];
            }
        }
        x = s[x].alpha[alps[i] - 'a'];
    }
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
