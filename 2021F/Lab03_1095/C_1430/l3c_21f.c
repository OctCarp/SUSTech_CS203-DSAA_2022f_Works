#include <stdio.h>
#include <string.h>

int cs;
int ci;

void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r);

void selectSort(int arr[], int n);

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        cs = 0;
        ci = 0;
        int n;
        scanf("%d", &n);
        int ins[n], sel[n];

        int in;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &in);
            ins[i] = in;
            sel[i] = in;
        }

        ci += n - 2;
        mergeSort(ins, 0, n - 1);
        cs += n * (n - 1) / 2;
        selectSort(sel, n);

        for (int i = 0; i < n - 1; ++i) {
            printf("%d ", ins[i]);
        }
        printf("%d\n", ins[n - 1]);
        if (cs > ci) {
            printf("%s\n", "Insertion Sort wins!");
        } else {
            printf("%s\n", "Selection Sort wins!");
        }
    }

    return 0;
}

void selectSort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int id = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[id]) {
                id = j;
            }
        }
        if (id != i) {
            ++cs;
            int temp = arr[i];
            arr[i] = arr[id];
            arr[id] = temp;
        }
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
            ci += (n1 - i) * 2;
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
