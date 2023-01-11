#include <stdio.h>
#include <string.h>

#define MAX_LEN 200005

int T;

int find_last_next(const char s[], int len);

int find_once();

int main() {
    scanf("%d", &T);

    while (T--) {
        find_once();
    }

    return 0;
}

int find_once() {
    char s[MAX_LEN];
    scanf("%s", &s);
    int len = strlen(s);

    int suf_len = find_last_next(s, len);
    int nomatch_len = len - suf_len;

    if (len % nomatch_len == 0 && suf_len != 0) {
        printf("0\n");
    } else {
        printf("%d\n", nomatch_len - len % nomatch_len);
    }
}

int find_last_next(const char s[], int len) {
    int next[len];
    next[0] = 0;

    int p = 0;
    for (int i = 1; i < len; ++i) {
        while (p > 0 && s[p] != s[i]) {
            p = next[p - 1];
        }

        if (s[p] == s[i]) {
            ++p;
        }

        next[i] = p;
    }

    return next[len - 1];
}