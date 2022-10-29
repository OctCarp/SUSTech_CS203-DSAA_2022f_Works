#include <stdio.h>
#include <malloc.h>

int n;

void write203(int digits[], int pow);

int main() {
    scanf("%d", &n);

    int *ns[n], ps[n];
    int in, pow, minus;
    for (int i = 0; i < n; ++i) {
        pow = 1, minus = 3;
        scanf("%d", &in);

        while (in > minus) {
            in -= minus;
            minus *= 3;
            pow++;
        }
        in--;

        int p = pow - 1;
        int *d = (int *) malloc(sizeof(int) * 20);
        d[0] = 0;

        while (in > 2) {
            d[p] = in % 3;
            in /= 3;
            p--;
        }
        d[p] = in;

        ns[i] = d, ps[i] = pow;
    }

    for (int i = 0; i < n; ++i) {
        write203(ns[i], ps[i]);
        printf("\n");
    }

    return 0;
}

void write203(int digits[], int pow) {
    int m;
    for (int i = 0; i < pow; ++i) {
        m = digits[i];
        if (m == 1) {
            putchar('3');
        } else if (m == 2) {
            putchar('6');
        } else {
            putchar('2');
        }
    }
    return;
}
