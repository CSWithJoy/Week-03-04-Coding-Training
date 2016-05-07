//以前做的时候看别人的题解学的判断镜面的方法
#include<bits/stdc++.h>

char s[25];

int palin(char* s)
{
    int len = strlen(s);
    for(int i = 0; i < len/2; i ++)
        if(s[i] != s[len-1-i])
			return 0;
        return 1;
}

int mirr(char* s)
{
    char s1[40]="ABCDEHIJKLMNOPQRSTUVWXYZ123456789";
    char s2[40]="A   3HIL JM O   2TUVWXY51SE4Z  8 ";

    int len = strlen(s);

    if((len==1)&&(s[0] != s2[strchr(s1,s[0])-s1]))
		return 0;

    for(int i = 0; i <= len/2; i ++)
    {
        if(!strchr(s1,s[i]))
			return 0;
        else
        {
            int p = strchr(s1,s[i]) - s1;
            if(s[len-i-1] != s2[p])
				return 0;
        }
    }
    return 1;
}

int main()
{
    while(scanf("%s",s) == 1)
    {
        if(palin(s) && mirr(s))
            printf("%s -- is a mirrored palindrome.\n",s);
        if(palin(s) && !mirr(s))
            printf("%s -- is a regular palindrome.\n",s);
        if(!palin(s) && mirr(s))
            printf("%s -- is a mirrored string.\n",s);
        if(!palin(s) && !mirr(s))
            printf("%s -- is not a palindrome.\n",s);
		printf("\n");
    }
    return 0;
}
