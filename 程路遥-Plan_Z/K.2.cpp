#include <cstdio>
#include <cstdlib>
#include <cstring>
char mp[31][81];

void dfs(int x, int y) {
    mp[x][y] = '#';
    if (mp[x - 1][y] == ' ')
        dfs(x - 1, y);
    if (mp[x][y - 1] == ' ')
        dfs(x, y - 1);
    if (mp[x + 1][y] == ' ')
        dfs(x + 1, y);
    if (mp[x][y + 1] == ' ')
        dfs(x, y + 1);
}
int main() {
    int n;
    scanf("%d", &n);
    gets(mp[0]);
    while (n--) {
        int i = 0;
        while (gets(mp[i]) && mp[i][0] != '_') {
            i++;
        }
        bool flag = true;
        for (int k = 0; k < i; k++)
            for (int j = 0; flag && j < strlen(mp[k]); j++)
                if (mp[k][j] == '*') {
                    mp[k][j] = '#';
                    dfs(k, j);
                    flag = false;
                }
        for (int k = 0; k <= i; k++)
            puts(mp[k]);
    }
}
