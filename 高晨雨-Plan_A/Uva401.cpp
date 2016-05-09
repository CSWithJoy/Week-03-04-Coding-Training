//判断字符串是否回文及镜像
#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
char rev[40]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char r(char ch)
{
	if(isalpha(ch)) return rev[ch-'A'];//判断是否是字母
	return rev[ch-'0'+25];
}
int main()
{
	char S[30];
	while(scanf("%s",S)==1)
	{
		int len=strlen(S);
		int p=1,m=1;
		for(int i=0;i<(len+1)/2;i++)
		{
			if(S[i]!=S[len-1-i]) p=0;
			if(r(S[i])!=S[len-1-i]) m=0;
		}
		if(m==0&&p==0) printf("%s -- is not a palindrome.\n\n",S);
		if(m==0&&p==1) printf("%s -- is a regular palindrome.\n\n",S);
		if(m==1&&p==0) printf("%s -- is a mirrored string.\n\n",S);
		if(m==1&&p==1) printf("%s -- is a mirrored palindrome.\n\n",S);
	}
	return 0;
}
