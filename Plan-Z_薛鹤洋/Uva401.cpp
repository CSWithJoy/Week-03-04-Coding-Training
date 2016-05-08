/*
又是紫薯上的题，直接保存结果到char数组里即可
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=1000;

using namespace std;

char a[maxn+10];

char rev[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char r(char x){
  if(isalpha(x)) return rev[x-'A'];
  return rev[x-'0'+25];
}

int main()
{
    while(scanf("%s",a)!=EOF){
        int len=strlen(a),f1=0,f2=0;
        for(int i=0;i<(len+1)/2;i++){
             if(a[i]!=a[len-i-1]) f1=1;
             if(r(a[i])!=a[len-i-1]) f2=1;
         }
         printf("%s -- ",a);
         if(f1&&f2) printf("is not a palindrome.\n");
         if(f1&&!f2) printf("is a mirrored string.\n");
         if(!f1&&f2) printf("is a regular palindrome.\n");
         if(!f1&&!f2) printf("is a mirrored palindrome.\n");
         printf("\n");
    }
    return 0;
}
