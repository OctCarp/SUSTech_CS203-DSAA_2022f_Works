#include <stdio.h>
#include <math.h>

const double esp = 1e-8;

void zp(int x);

int main() {
    int T;
    scanf("%d", &T);

    int x;
    while (T--) {
        scanf("%d", &x);
        zp(x);
    }

    return 0;
}

void zp(int b) {
    double l = 0;
    double r = 258;
    double m;
    double calcM;

    while (r - l > esp) {
        m = (l + r) / 2;
        calcM = m * exp(m / 20) - b;
        if (calcM < 0) {
            l = m;
        } else {
            r = m;
        }
    }

    printf("%.10f\n", m);
}
