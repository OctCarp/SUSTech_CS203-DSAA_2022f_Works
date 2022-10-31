#include <stdio.h>

#define MAX_LEN 100005

int a[MAX_LEN];
int n;

void myBinarySearch(int tar);

int main() {
    int T;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &T);
    int x;
    while (T--) {
        scanf("%d", &x);
        myBinarySearch(x);
    }

    return 0;
}

void myBinarySearch(int tar) {
    int l = 0;
    int r = n - 1;
    int mid;

    int i = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] > tar) {
            r = mid - 1;
        } else if (a[mid] < tar) {
            l = mid + 1;
        } else {
            i = mid + 1;
            break;
        }
    }

    if (i) {
        printf("%s\n", "YES");
    } else {
        printf("%s\n", "NO");
    }
}
