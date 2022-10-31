#include <iostream>
#include <map>

#define MAX_SIZE 100000

using namespace std;

int a[MAX_SIZE + 5];
int pow2[28];
int n;
long long ans;

void init();

void check();

int main() {
    init();
    check();

    cout << ans;

    return 0;
}

void init() {
    pow2[0] = 1;
    for (int i = 1; i <= 27; ++i) {
        pow2[i] = pow2[i - 1] * 2;
    }

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void check() {
    map<int, int> num;
    ans = 0;
    int x;
    int diff;

    for (int i = 0; i < n; ++i) {
        x = a[i];
        for (int j = 1; j <= 27; ++j) {
            diff = pow2[j] - x;
            if (diff > 0) {
                ans += num[diff];
            }
        }
        ++num[x];
    }
}
