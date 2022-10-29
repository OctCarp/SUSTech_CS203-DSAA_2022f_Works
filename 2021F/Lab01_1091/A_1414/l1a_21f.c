//It's a simple problem, so I use Brute Force

#include <stdio.h>

int n, t;

int main() {
    int in;

    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in);
        a[i] = in;
    }

    scanf("%d", &t);
    int find;
    for (int i = 0; i < t; ++i) {
        scanf("%d", &in);
        find = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] == in) {
                find = 1;
            }
        }

        if (find == 0) {
            printf("%s\n", "no");
        } else {
            printf("%s\n", "yes");
        }
    }

    return 0;
}
