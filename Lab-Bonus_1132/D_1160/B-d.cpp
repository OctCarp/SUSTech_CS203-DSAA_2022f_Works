#include <cstdio>
#include <stack>

using namespace std;

int T;

bool match_once();

int main() {
    scanf("%d", &T);
    while (T--) {
        printf(match_once() ? "YES\n" : "NO\n");
    }

    return 0;
}

bool match_once() {
    int len;
    scanf("%d", &len);
    char bs[len];
    scanf("%s", &bs);

    if (len & 1) return false;

    stack<char> s;
    for (char b: bs) {
        switch (b) {
            case '(':
                s.push(')');
                break;
            case '[':
                s.push(']');
                break;
            case '{':
                s.push('}');
                break;
            default:
                if (!s.empty() && b == s.top()) {
                    s.pop();
                } else return false;
        }
    }

    return s.empty();
}
