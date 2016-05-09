//Water
#include<cstdio>
#include<cstring>
#include<cstdlib>

const int MAXD = 105;
char s1[MAXD], s2[MAXD];
char a1[MAXD], a2[MAXD], a3[MAXD], a4[MAXD];

int main()
{
    int t;
    scanf( "%d", &t);
    getchar();
    while( t --)
    {
        memset( s1, 0, sizeof s1);
        memset( s2, 0, sizeof s2);
        memset( a1, 0, sizeof a1);
        memset( a2, 0, sizeof a2);
        memset( a3, 0, sizeof a3);
        memset( a4, 0, sizeof a4);

        gets(s1);
        int len = strlen(s1);
        for( int i = 0; i < len; i ++)
        {
            if( s1[i] == '<' || s1[i] == '>')
                continue;
            else
                printf( "%c", s1[i]);
        }
        printf( "\n");
        gets(s2);
        int j = 0, pos[5];
        for( int i = 0; s1[i]; i ++)
        {
            if( s1[i] == '<' || s1[i] == '>')
            {
                pos[++j] = i;
            }
        }

        j = 0;
        for( int i = pos[1] + 1; i < pos[2]; i ++)
        {
            a1[j++] = s1[i];
        }

        j = 0;
        for( int i = pos[2] + 1; i < pos[3]; i ++)
        {
            a2[j++] = s1[i];
        }

        j = 0;
        for( int i = pos[3] + 1; i < pos[4]; i ++)
        {
            a3[j++] = s1[i];
        }

        j = 0;
        for( int i = pos[4] + 1; i < len; i ++)
        {
            a4[j++] = s1[i];
        }

        for( int i = 0; s2[i]; i ++)
        {
            if( s2[i] != '.')
                printf( "%c", s2[i]);
        }
        printf( "%s%s%s%s\n", a3, a2, a1, a4);
    }
    return 0;
}