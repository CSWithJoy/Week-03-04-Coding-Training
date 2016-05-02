// water
#include <bits/stdc++.h>
using namespace std;
int m, n;
char mp[60][60], wd[60];
int dx[8]={-1, 0, 1, 1, 1, 0, -1, -1}, dy[8]={-1, -1, -1, 0, 1, 1, 1, 0};

void lwr(char *s) {
  int l=strlen(s);
  for (int i=0;i<l;++i) {
    if (s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
  }
}

int main() {
  int T, k;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &m, &n);
    for (int i=0;i<m;++i) {
      scanf("%s", mp[i]);
      lwr(mp[i]);
    }
    scanf("%d%*c", &k);
    for (int u=0;u<k;++u) {
      gets(wd);
      lwr(wd);
      int len=strlen(wd);
      for (int i=0;i<m;++i) {
        for (int j=0;j<n;++j) {
          for (int v=0;v<8;++v) {
            bool f=true;
            int cx=j, cy=i;
            for (int w=0;w<len;++w) {
              if (cx<0||cx>=n||cy<0||cy>=m||mp[cy][cx]!=wd[w]) {
                f=false;
                break;
              }
              cx+=dx[v];
              cy+=dy[v];
            }
            if (f) {
              printf("%d %d\n", i+1, j+1);
              goto over;
            }
          }
        }
      }
      over:;
    }
    if (T>0) printf("\n");
  }
  return 0;
}
/*
1

8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcbqwikomk
strEBGadhrb
yUiqlxcnBjf
4
Waldorf
Bambi
Betty
Dagbert
*/