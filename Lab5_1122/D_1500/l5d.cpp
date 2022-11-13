#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;

bool findNext(string s);

int main() {
    string s1, s2, sum;

    cin >> n;
    cin >> s1 >> s2;

    for (int i = 0; i < n - 1; ++i) {
        switch (s1[i]) {
            case 'N':
                s1[i] = 'S';
                break;
            case 'S':
                s1[i] = 'N';
                break;
            case 'W':
                s1[i] = 'E';
                break;
            case 'E':
                s1[i] = 'W';
                break;
        }
    }
    reverse(s1.begin(), s1.end());

    sum = s1 + s2;

    if (findNext(sum)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

bool findNext(string s) {
    int len = 2 * (n - 1);
    int next[len];
    next[0] = 0;

    int p = 0;
    for (int i = 1; i < len; ++i) {
        while (p > 0 && s[p] != s[i]) {
            p = next[p - 1];
        }

        if (s[p] == s[i]) {
            ++p;
        }

        next[i] = p;
    }

    if (next[len - 1] > 0) {
        return false;
    } else {
        return true;
    }
}
