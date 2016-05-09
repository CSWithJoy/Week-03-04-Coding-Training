//输入时的技巧
#include<bits/stdc++.h>
using namespace std;

char s1[105];
char second[105];
char s2[105];
char s3[105];
char s4[105];
char s5[105];

void input(char s[])
{
	for(int i=0;i<105;i++)
	{
		s[i] = getchar();
		if(s[i]== '<' || s[i] == '>' || s[i] == '\n')
		{
			s[i]='\0';
			break;
		}
	}
}

int main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
        input(s1);
		input(s2);
		input(s3);
		input(s4);
		input(s5);
		gets(second);
		second[strlen(second) - 3] = '\0';
		printf("%s%s%s%s%s\n",s1,s2,s3,s4,s5);
		printf("%s%s%s%s%s\n",second,s4,s3,s2,s5);
	}
	return 0;
}
