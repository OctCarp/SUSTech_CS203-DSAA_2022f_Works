#include <stdio.h>
#include <string.h>

#define MAX_SIZE (10000 + 5)
#define MAX_LEN (100 + 5)

int n;
int ans[MAX_SIZE];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        char s[MAX_LEN];
        scanf("%s", &s);
        ans[i] = 1;

        char *func = strtok(s, "+");
        while (func) {
            if (func[0] != '0') {
                ans[i] = -1;
                break;
            }
            func = strtok(NULL, "+");
        }
    }

    for (int i = 0; i < MAX_SIZE; ++i) {
        if (ans[i] == 1) {
            printf("%s\n", "yes");
        } else if (ans[i] == -1) {
            printf("%s\n", "no");
        } else break;
    }

    return 0;
}