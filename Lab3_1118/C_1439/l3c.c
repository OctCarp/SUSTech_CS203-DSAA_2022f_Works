#include <stdio.h>
#include <string.h>
#include <math.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define MAX_NUM  2000000

struct Node {
    int val;
    int prev;
    int next;
} ns[MAX_NUM + 5];

void mergeByIndex(const struct Node nodes[], int aI[], int l, int m, int r);

void mergeSortByIndex(const struct Node nodes[], int aI[], int l, int r);

int main() {
    int n = 0;
    scanf("%d", &n);
    int index[n];

    int value = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        ns[i].val = value;
        index[i] = i;
    }
    mergeSortByIndex(ns, index, 0, n - 1);

    ns[index[0]].prev = -1;
    for (int i = 1; i < n; ++i) {
        ns[index[i]].prev = index[i - 1];
        ns[index[i - 1]].next = index[i];
    }
    ns[index[n - 1]].next = -1;

    int iPrev, iNext, ans;
    for (int i = 0; i < n; ++i) {
        if (i != 0) printf(" ");

        iPrev = ns[i].prev;
        iNext = ns[i].next;
        if (iPrev != -1 && iNext != -1) {
            ans = min(abs(ns[i].val - ns[iPrev].val), abs(ns[i].val - ns[iNext].val));
        } else {
            if (iPrev != -1) {
                ans = abs(ns[i].val - ns[iPrev].val);
            } else if (iNext != -1) {
                ans = abs(ns[i].val - ns[iNext].val);
            } else break;
        }
        printf("%d", ans);

        ns[iNext].prev = iPrev;
        ns[iPrev].next = iNext;
    }

    return 0;
}

void mergeSortByIndex(const struct Node pNs[], int aI[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortByIndex(pNs, aI, l, m);
        mergeSortByIndex(pNs, aI, m + 1, r);
        mergeByIndex(pNs, aI, l, m, r);
    }
}

void mergeByIndex(const struct Node pNs[], int aI[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int lI[n1], rI[n2];

    memcpy(&lI[0], &aI[l], n1 * sizeof(int));
    memcpy(&rI[0], &aI[m + 1], n2 * sizeof(int));

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (pNs[lI[i]].val <= pNs[rI[j]].val) {
            aI[k++] = lI[i++];
        } else {
            aI[k++] = rI[j++];
        }
    }

    while (i < n1) {
        aI[k++] = lI[i++];
    }
    while (j < n2) {
        aI[k++] = rI[j++];
    }
}
