#include <stdio.h>

int n, h;
long long sum1 = 0, sum2 = 0, diff = 0;

int main() {
    scanf("%d", &n);
    scanf("%d", &h);
    int max1 = 1, max2 = 1, min1 = h, min2 = h;

    int in;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &in);
        sum1 += in;
        if (in > max1) {
            max1 = in;
        }
        if (in < min1) {
            min1 = in;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &in);
        sum2 += in;
        if (in > max2) {
            max2 = in;
        }
        if (in < min2) {
            min2 = in;
        }
    }
    diff = (sum1 - max1 - min1) - (sum2 - max2 - min2);

    if (diff + max1 - min2 <= 0) {
        printf("IMPOSSIBLE");
    } else {
        if (diff + min1 - max2 > 0) {
            printf("%d", 1 - h);
        } else {
            int p = diff - max2;

            if (p + max1 > 0) {
                printf("%d", p + 1 - h);
            } else {
                p = diff - min2;

                if (p + min1 > 0) {
                    printf("%d", min1 + 1 - min2);
                } else {
                    printf("%d", 1 - diff);
                }
            }
        }
    }

    return 0;
}