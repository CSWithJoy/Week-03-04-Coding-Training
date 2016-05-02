// water
#include <bits/stdc++.h>
using namespace std;
list<string> l1, l2;
list<string>::iterator it1, it2;
map<string, bool> mp;

int main() {
  int T, n;
  char str[90];
  string tmp;
  scanf("%d", &T);
  while (T--) {
    mp.clear();
    scanf("%d%*c", &n);
    for (int i=0;i<n;++i) {
      tmp.clear();
      gets(str);
      tmp.assign(str);
      l1.push_front(tmp);
    }
    for (int i=0;i<n;++i) {
      tmp.clear();
      gets(str);
      tmp.assign(str);
      l2.push_front(tmp);
    }
    it1=l1.begin();
    it2=l2.begin();
    while (it1!=l1.end()) {
      if (*it1==*it2) {
        ++it1;
        ++it2;
      }else {
        mp[*it1]=true;
        ++it1;
      }
    }
    for (auto it:l2) {
      if (mp[it])
        printf("%s\n", it.c_str());
    }
    l1.clear();
    l2.clear();
    printf("\n");
  }
  return 0;
}