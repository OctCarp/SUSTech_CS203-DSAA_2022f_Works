#include <cstdio>
#include <deque>

using namespace std;

int read();

void write(int x);

int *findMax(const int arr[], int n, int k);

int main() {
    int n = 0, k = 0, q = 0;
    n = read();
    k = read();
    q = read();

    int nums[n];
    for (int i = 0; i < n; i++) {
        nums[i] = read();
    }

    int *maxNum = findMax(nums, n, k);

    int qi = 0;
    for (int i = 0; i < q; i++) {
        qi = read();
        write(maxNum[qi - 1]);
        printf("\n");
    }

    return 0;
}

int *findMax(const int *arr, int n, int k) {
    int *maxNum = new int[n - k + 1];
    deque<int> imax;

    for (int i = 0; i < k; i++) {
        while (!imax.empty() && arr[imax.back()] < arr[i]) {
            imax.pop_back();
        }
        imax.push_back(i);
    }
    maxNum[0] = arr[imax.front()];

    for (int i = k; i < n; i++) {
        if (imax.front() + k <= i) {
            imax.pop_front();
        }
        while (!imax.empty() && arr[imax.back()] < arr[i]) {
            imax.pop_back();
        }
        imax.push_back(i);
        maxNum[i - k + 1] = arr[imax.front()];
    }

    return maxNum;
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
