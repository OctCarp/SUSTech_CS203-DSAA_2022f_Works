#include <iostream>
#include <stack>

#define MOD 514329

using namespace std;

int playroom(string s);

int main() {
    string par;
    cin >> par;
    cout << playroom(par);

    return 0;
}

int playroom(string par) {
    stack<int> s;
    s.push(0);

    int add = 0;
    for (int i = 0; i < par.length(); i++) {
        if (par.at(i) == '(') {
            s.push(0);
        } else {
            if (s.top() == 0) {
                add = (s.top() + 1) % MOD;
            } else {
                add = (s.top() << 1) % MOD;
            }
            s.pop();
            s.top() += add;
        }
    }

    return s.top();
}
