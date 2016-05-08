//UVa113这题是在一个头尾相接成环的队列中数个数出队，同时有正反两个方向；用双端队列模拟，一开始写遇到了一个问题就是
//因为一次可能会删除两个，如果这两相邻，确定下一个数数的开始点就不能是简单的取下一个点（因为已经被删除了）
#include <iostream>
#include <cstdio>

using namespace std;
struct NODE
{
    NODE *before;
    NODE *next;
    int num;
};
NODE *head;
NODE *tail;
void MAKE_LIST(int n)
{
    tail= new NODE;
    tail->before = NULL;
    tail->num = 1;
    head = tail;
    for(int i = 2; i<=n; i++)
    {
        NODE *new_p = new NODE;
        new_p->before = tail;
        tail->next = new_p;
        new_p->num = i;
        tail = new_p;
    }
    tail->next = head;
    head->before = tail;
}
int N,k,m;

void f_1(int num)
{
    while(num--)
    {
        head = head->next;
    }
}
void f_2(int num)
{
    while(num--)
    {
        tail = tail->before;
    }
}
int main()
{
    while(scanf("%d%d%d",&N,&k,&m))
    {
        if(N == 0)
            break;
        MAKE_LIST(N);
        int flag = 0;
        while(N)
        {
            if(flag)
            {
                printf(",");
            }
            f_1(k-1);
            f_2(m-1);
            if(head->num == tail->num)
            {
                //cout <<endl;
                printf("%3d",head->num);
                NODE *p = head;
                head = head->next;
                tail = tail->before;
                head->before = tail;
                tail->next = head;
                delete p;
                N--;

            }
            else
            {
                printf("%3d%3d",head->num,tail->num);
                head->before->next = head->next;
                head->next->before = head->before;
                NODE * p =head;

                tail->before->next = tail->next;
                tail->next->before = tail->before;

                head = head->before->next;
                delete p;
                p = tail;
                tail = tail->next->before;

                delete p;
                N--;
                N--;
            }
            flag++;
        }
        printf("\n");
    }
    return 0;
}
