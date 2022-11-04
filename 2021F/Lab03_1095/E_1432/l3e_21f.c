#include <stdio.h>
#include <string.h>

#define ll long long
#define MAX_SIZE (int) (1e5 + 5)

int n;
int a[MAX_SIZE];
ll ans;

void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r);

int main() {
    ans = 0ll;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n);

    printf("%lld", ans);

    return 0;
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
            ans += (ll) R[j] * (n1 - i);
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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
