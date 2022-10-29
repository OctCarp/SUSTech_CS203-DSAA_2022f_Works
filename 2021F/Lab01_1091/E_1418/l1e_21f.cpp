#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define ll long long

using namespace std;

queue<string> q;
vector<ll> mags;
vector<ll> ans;

struct add {
    string le;
    string ri;
} ps[5];

void init();

void compare();

int main() {
    init();
    compare();

    for (int i = 0; i < ans.size(); i += 2) {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }

    return 0;
}

void compare() {
    ll l, r;
    int li, ri;

    while (cin >> l >> r) {
        li = 0, ri = mags.size() - 1;
        while (true) {
            if (mags.at(li) >= l) {
                ans.push_back(mags.at(li));
                break;
            }
            li++;
        }
        while (true) {
            if (mags.at(ri) <= r) {
                ans.push_back(mags.at(ri));
                break;
            }
            ri--;
        }
    }
}

void init() {
    ps[0].le = "0", ps[0].ri = "0";
    ps[1].le = "1", ps[1].ri = "1";
    ps[2].le = "6", ps[2].ri = "9";
    ps[3].le = "8", ps[3].ri = "8";
    ps[4].le = "9", ps[4].ri = "6";
    q.push("0"), q.push("1"), q.push("8"), q.push("00");
    q.push("11"), q.push("69"), q.push("88"), q.push("96");
    string s, t;

    while (!q.empty()) {
        s = q.front();
        if (s.at(0) != '0') {
            mags.push_back(atoll(s.c_str()));
        }
        for (int i = 0; i < 5 && strlen(s.c_str()) <= 10; ++i) {
            t = ps[i].le + s + ps[i].ri;
            q.push(t);
        }
        q.pop();
    }

    sort(mags.begin(), mags.end(), less<ll>());

    while (mags.back() > 999999666666ll) {
        mags.pop_back();
    }
}
