//没有想到不用指针的解法，学习一个。。。
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
const int TOTAL=1365; //最多结点1365，即下标最大1365
const int MAXN=1400;
int t1[MAXN],t2[MAXN];
 //保存两棵树的全部结点,数组的元素从1到1365，这种思想是假设所有结点都是存在在，只是颜色要怎样确定而已
void dye(int R , int *t)  //染色函数，将当前下标为R的结点染成黑色，并递归它的四个孩子染色
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
    //当前这个结点是白色，那么其下属的所有结点都是白色，我们试图递归找出其所有的下属结点，并将它们都赋为0,但因为一开始清0了，//不用赋，所以跳过
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
    int T,i; int level,mark,R,sum;//R是指当前结点在数组中的下标
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
