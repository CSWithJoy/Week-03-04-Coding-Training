// water 好久不写bfs了，写bfs姿势错误导致超时。基础不牢地动山摇
#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};
char mp[maxn][maxn];
struct P{
  int x, y;
  P() {}
  P(int x, int y):x(x), y(y) {}
};
queue<P> que;

void bfs(int x, int y) {
  P cur;
  que.push(P(x, y));
  while (!que.empty()) {
    cur=que.front();
    que.pop();
    mp[cur.y][cur.x]='#';
    for (int k=0;k<4;++k) {
      int nx=cur.x+dx[k], ny=cur.y+dy[k];
      if (ny<0||nx<0||mp[ny][nx]!=' ') continue;
      que.push(P(nx, ny));
    }
  }
}

void dfs(int x, int y) {
  if (mp[y][x]!=' ') return;
  mp[y][x]='#';
  for (int k=0;k<4;++k) {
    int nx=x+dx[k], ny=y+dy[k];
    if (ny<0||nx<0||mp[ny][nx]!=' ') continue;
    dfs(nx, ny);
  }
}

int main() {
  int T, sx, sy;
  scanf("%d%*c", &T);
  while (T--) {
    bool flag=true;
    int m=0;
    while (flag) {
      flag=false;
      char ch;
      int n=0;
      while (scanf("%c", &ch)&&ch!='\n') {
        if (ch!='_') flag=true;
        if (ch=='*') {
          sx=n;
          sy=m;
        }
        mp[m][n]=ch;
        ++n;
      }
      mp[m][n]=0;
      ++m;
    }
    mp[sy][sx]=' ';
    dfs(sx, sy);
    for (int i=0;i<m;++i) printf("%s\n", mp[i]);
  }
  return 0;
}
/*
2
XXXXXXXXX
X   X   X
X   *   X
X   X   X
XXXXXXXXX
X   X
X   X
X   X
XXXXX
_____
XXXXX
X   X
X * X
X   X
XXXXX
_____
*/