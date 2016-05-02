// water
#include <bits/stdc++.h>
using namespace std;
char dic[50]="AEHIJLMOSTUVWXYZ12358A3HILJMO2TUVWXY51SEZ8";
char in[1000];
bool ismirr(char a, char b) {
  if (strchr(dic, a)==NULL) return false;
  return dic[strchr(dic, a)-dic+21]==b;
}

int main() {
  int n;
  bool mir, pal;
  while (scanf("%s", &in)!=EOF) {
    n=strlen(in);
    mir=pal=true;
    for (int i=0;i<(n+1)/2;++i) {
      if (in[i]!=in[n-i-1]) pal=false;
      if (!ismirr(in[i], in[n-i-1])) mir=false;
    }
    printf("%s -- is ", in);
    if (mir&&pal) printf("a mirrored palindrome.\n");
    else if (mir&&!pal) printf("a mirrored string.\n");
    else if (!mir&&pal) printf("a regular palindrome.\n");
    else printf("not a palindrome.\n");
    printf("\n");
  }
  return 0;
}