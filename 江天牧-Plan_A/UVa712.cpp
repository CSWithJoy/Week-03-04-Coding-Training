//给出二叉树的路径求叶子的值，按线段树写就可以啦
#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int yezhi[100];
char tree[100];
int n;
void solve(char* a)
{
    int u = 1;
    for(int i = 0;i < n;i++)
    {
        if(a[yezhi[i]] == '0')
        {
            u *=2;
        }
        else
        {
            u = u*2 + 1;
        }
    }
    printf("%c",tree[u-(1<<n)]);
}
int main()
{
    int TIME = 1;
    char temp_c[3];
    while(~scanf("%d",&n) && n)
    {
        for(int i = 0; i < n;i++)
        {
            scanf("%s",temp_c);
            yezhi[i] = temp_c[1]-'1';
        }
        int m;
        cout << "S-Tree #" << TIME++ << ":\n";
        scanf("%s",tree);
        cin >> m;

        while(m--)
        {
            char asd[100];
            scanf("%s",asd);
            solve(asd);
        }
        printf("\n\n");
    }
    return 0;
}
