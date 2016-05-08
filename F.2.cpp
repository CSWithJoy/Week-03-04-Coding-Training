//û���뵽����ָ��Ľⷨ��ѧϰһ��������
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
const int TOTAL=1365; //�����1365�����±����1365
const int MAXN=1400;
int t1[MAXN],t2[MAXN];
 //������������ȫ�����,�����Ԫ�ش�1��1365������˼���Ǽ������н�㶼�Ǵ����ڣ�ֻ����ɫҪ����ȷ������
void dye(int R , int *t)  //Ⱦɫ����������ǰ�±�ΪR�Ľ��Ⱦ�ɺ�ɫ�����ݹ������ĸ�����Ⱦɫ
{
    if(R>TOTAL)  return ;
    t[R]=1;
    dye(4*R-2,t);
    dye(4*R-1,t);
    dye(4*R,t);
    dye(4*R+1,t);
}
void create_tree(int R ,int *t)
{
    char ch;
    if(R>TOTAL)  return ;
    scanf("%c",&ch);
    if(ch=='e')   return ;
    //��ǰ�������ǰ�ɫ����ô�����������н�㶼�ǰ�ɫ��������ͼ�ݹ��ҳ������е�������㣬�������Ƕ���Ϊ0,����Ϊһ��ʼ��0�ˣ�//���ø�����������
    else if(ch=='p')
    {
        create_tree(4*R-2,t);
        create_tree(4*R-1,t);
        create_tree(4*R,t);
        create_tree(4*R+1,t);
    }
    else dye(R,t);
}
int main()
{
    int T,i; int level,mark,R,sum;//R��ָ��ǰ����������е��±�
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        R=1;
        level=1;
        mark=0;
        create_tree(R,t1);
        getchar();
        R=1;
        level=1;
        mark=0;
        create_tree(R,t2);
        getchar();
        for(sum=0,i=342; i<=TOTAL; i++)
            if(t1[i]|t2[i])
                sum++;
        printf("There are %d black pixels.\n",sum);
    }
    return 0;
}
