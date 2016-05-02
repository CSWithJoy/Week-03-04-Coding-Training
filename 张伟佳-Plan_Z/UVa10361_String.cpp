// water
#include <bits/stdc++.h>
using namespace std;
char s1[105], s2[105], s3[105], s4[105], s5[105], s6[105];

int main() {
  int T;
  scanf("%d%*c", &T);
  while (T--) {
    int p=0;
    char ch;
    while (scanf("%c", &ch)&&ch!='<') s1[p++]=ch;
    s1[p++]='\0';
    p=0;
    while (scanf("%c", &ch)&&ch!='>') s2[p++]=ch;
    s2[p++]='\0';
    p=0;
    while (scanf("%c", &ch)&&ch!='<') s3[p++]=ch;
    s3[p++]='\0';
    p=0;
    while (scanf("%c", &ch)&&ch!='>') s4[p++]=ch;
    s4[p++]='\0';
    p=0;
    while (scanf("%c", &ch)&&ch!='\n') s5[p++]=ch;
    s5[p++]='\0';
    p=0;
    while (scanf("%c", &ch)&&ch!='.') s6[p++]=ch;
    s6[p++]='\0';
    while (scanf("%c", &ch)&&ch!='\n');
    printf("%s%s%s%s%s\n", s1, s2, s3, s4, s5);
    printf("%s%s%s%s%s\n", s6, s4, s3, s2, s5);
  }
  return 0;
}