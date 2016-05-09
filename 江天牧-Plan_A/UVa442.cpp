//用双端队列模拟矩阵运算中的运算步数，先遇到）运算一次，之后从前往后算
#include <iostream>
#include<cstdio>
#include<list>
struct MATRI
{
    int l,r;
    MATRI(){}
    MATRI(const int x,const int y): l(x),r(y){}
}a_ma[26];

using namespace std;

list<struct MATRI> matri;

int main()
{
    int n;
    cin >> n;
    char c;
    c = getchar();
    while(n--)
    {
        int l,r;
        scanf(" %c%d%d",&c,&l,&r);
        a_ma[c-'A'] = MATRI(l,r);
    }
    char asd[80];
    while(scanf("%s",asd)!= EOF)
    {
        matri.clear();
        int sum = 0;
        int flag = 1;
        for(int i = 0; asd[i] != '\0';i ++)
        {
            if(asd[i]<='Z' && asd[i]>='A')
            {
                matri.push_back(a_ma[asd[i]-'A']);
            }
            if(asd[i] == ')')
            {
                int l1,l2,r1,r2;
                l1 = matri.back().l;
                r1 = matri.back().r;
                matri.pop_back();
                l2 = matri.back().l;
                r2 = matri.back().r;
                matri.pop_back();
                matri.push_back(MATRI(l2,r1));

                if(l1 != r2)
                {
                    flag = 0;
                    break;
                }
                sum += l1*l2*r1;
                /*
                */
            }
            //cout <<i<<endl;

        }
        while(!matri.empty())
        {
            int l1,l2,r1,r2;
            l1 = matri.front().l;
            r1 = matri.front().r;
            matri.pop_front();
            if(matri.empty())
                break;
            l2  = matri.front().l;
            r2 = matri.front().r;
            matri.pop_front();
            sum += l1*l2*r2;
            if(l2!=r1)
            {
                flag = 0;
                break;
            }
            matri.push_front(MATRI(l1,r2));
        }
        if(flag)
        {
            printf("%d\n",sum);
        }
        else
        {
            printf("error\n");
        }
    }
    return 0;
}
