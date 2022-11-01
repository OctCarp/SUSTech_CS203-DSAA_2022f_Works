#include <stdio.h>

#define MAX_SIZE 1000005
#define max(a, b) (((a) > (b)) ? (a) : (b))

int first[MAX_SIZE];
int last[MAX_SIZE];
int n;

void init();

int segment();

int main() {
    init();

    printf("%d", segment());

    return 0;
}

void init() {
    scanf("%d", &n);

    int in;
    first[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &in);
        first[i + 1] = first[i] + in;
    }

    last[n] = first[n];
    for (int i = n - 1; i >= 1; i--) {
        last[i] = max(last[i + 1], first[i]);
    }
}

int segment() {
    int ans = 0;
    int head = 0, tail = 1;

    while (head < n && tail < n) {
        while (first[head] >= last[tail]) {
            ++head;
        }
        while (first[head] < last[tail + 1]) {
            if (tail < n) {
                ++tail;
            } else break;
        }
        int len = tail - head;

        ans = max(ans, len);
        ++head;
    }

    return ans;
}
