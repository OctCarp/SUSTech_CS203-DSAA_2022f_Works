#include <stdio.h>
#include <string.h>

#define MAX_SIZE (int) (1e6 + 5)

int n;
int a[MAX_SIZE];

int read();

void write(int x);

void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r);

int main() {
    n = read();
    for (int i = 0; i < n; ++i) {
        a[i] = read();
    }
    mergeSort(a, 0, n - 1);

    int temp;
    for (int i = 1; i < n - 1; i += 2) {
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }

    for (int i = 0; i < n - 1; ++i) {
        write(a[i]);
        putchar(' ');
    }
    write(a[n - 1]);

    return 0;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    memcpy(&L[0], &arr[l], n1 * sizeof(int));
    memcpy(&R[0], &arr[m + 1], n2 * sizeof(int));

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
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
