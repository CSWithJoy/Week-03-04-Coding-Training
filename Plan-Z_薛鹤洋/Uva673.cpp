/*
水题
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=1000;

using namespace std;

int n;

char a[maxn+10];

int judge(char a,char b){
     if((a=='('&&b==')')||(a=='['&&b==']')) return 1;
     return 0;
}

int main()
{
        scanf("%d",&n);
        getchar();
        for(int h=1;h<=n;h++){
        int flag=0;
        gets(a);
        if(strcmp(a,"\n")==0){
        cout<<"Yes"<<endl;
        continue;
        }
        stack<char> s;
        for(int i=0;i<strlen(a);i++){
                if(a[i]=='('||a[i]=='[') s.push(a[i]);
                else {
                        if(s.empty()){printf("No\n");flag=1;break;}
                        if(judge(s.top(),a[i]))
                        s.pop();
                        else {printf("No\n");flag=1;break;}
                }
        }
        if(s.empty()&&!flag) printf("Yes\n");
        else if(!s.empty()&&!flag)printf("No\n");
        }
    return 0;
}
