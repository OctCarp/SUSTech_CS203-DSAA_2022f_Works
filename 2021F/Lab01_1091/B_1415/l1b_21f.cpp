#include <cstdio>
#include <set>

int n, t;

using namespace std;

int main() {
    set<int> a;
    int in;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in);
        a.insert(in);
    }

    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d", &in);
        if (a.find(in) == a.end()) {
            printf("%s\n", "no");
        } else {
            printf("%s\n", "yes");
        }
    }

    return 0;
}
