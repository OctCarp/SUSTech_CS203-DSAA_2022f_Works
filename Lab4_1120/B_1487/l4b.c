#include <stdio.h>

#define MAX_N 100000

int s[MAX_N + 5];
int n = 0, p = 0, h = 0;

void push(int in);

int main() {
    scanf("%d", &n);

    char o = '0';
    int num = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s%d", &o, &num);
        if (o == 'E') {
            push(num);
        } else {
            h += num;
            printf("%d\n", s[h]);
        }
    }

    return 0;
}

void push(int in) {
    s[p] = in;
    p++;
}
