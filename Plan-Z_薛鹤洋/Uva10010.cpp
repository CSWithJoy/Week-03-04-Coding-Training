/*
纯暴力搞
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,m,k;

char ch,a[maxn+10][maxn+10],tar[maxn+10];

void found(char *tar,int len){
    int upmost=inf,leftmost=inf;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        int flag=0;
        if(a[i][j]==tar[0]){
                //printf("yes\n");
               if(j>=len) {
                for(int h=0;h<len;h++){
                        if(a[i][j-h]!=tar[h]) {
                        flag=1;
                        break;
                        }
                }
                if(!flag) {
                        if(i<upmost) {
                                upmost=i;
                                leftmost=j;
                        } else if(i==upmost) {
                              if(j<leftmost) {
                                upmost=i;
                                leftmost=j;
                              }
                        }
                break;
                }
               }
               flag=0;
               if(j+len-1<=m){
                for(int h=0;h<len;h++){
                        if(a[i][j+h]!=tar[h]) {
                        flag=1;
                        break;
                        }
                }
                if(!flag) {
                        if(i<upmost) {
                                upmost=i;
                                leftmost=j;
                        } else if(i==upmost) {
                              if(j<leftmost) {
                                upmost=i;
                                leftmost=j;
                              }
                        }
                        break;
                }
               }
               flag=0;
               if(i>=len){
                for(int h=0;h<len;h++){
                        if(a[i-h][j]!=tar[h]) {
                        flag=1;
                        break;
                        }
                }
                if(!flag) {
                        if(i<upmost) {
                                upmost=i;
                                leftmost=j;
                        } else if(i==upmost) {
                              if(j<leftmost) {
                                upmost=i;
                                leftmost=j;
                              }
                        }
                        break;
                }
               }
               flag=0;
               if(i+len-1<=n){
                 for(int h=0;h<len;h++){
                        if(a[i+h][j]!=tar[h]) {
                        flag=1;
                        break;
                        }
                }
                if(!flag) {
                        if(i<upmost) {
                                upmost=i;
                                leftmost=j;
                        } else if(i==upmost) {
                              if(j<leftmost) {
                                upmost=i;
                                leftmost=j;
                              }
                        }
                        break;
                }
               }
               flag=0;
               if(i+len-1<=n&&j+len-1<=m){
                       //printf("yes\n");
                for(int h=0;h<len;h++){
                        if(a[i+h][j+h]!=tar[h]) {
                        flag=1;
                        //printf("%c %c\n",a[i+h][j+h],tar[h]);
                        break;
                        }
                }
                if(!flag) {
                        //printf("yes\n");
                        if(i<upmost) {
                                upmost=i;
                                leftmost=j;
                        } else if(i==upmost) {
                              if(j<leftmost) {
                                upmost=i;
                                leftmost=j;
                              }
                        }
                break;
                }
               }

               flag=0;
               if(i+len-1<=n&&j>=len){
                for(int h=0;h<len;h++){
                        if(a[i+h][j-h]!=tar[h]) {
                        flag=1;
                        break;
                        }
                }
                if(!flag) {
                        if(i<upmost) {
                                upmost=i;
                                leftmost=j;
                        } else if(i==upmost) {
                              if(j<leftmost) {
                                upmost=i;
                                leftmost=j;
                              }
                        }
                break;
                }
               }
               flag=0;
               if(i>=len&&j+len-1<=m){
                for(int h=0;h<len;h++){
                        if(a[i-h][j+h]!=tar[h]) {
                        flag=1;
                        break;
                        }
                }
                if(!flag) {
                        if(i<upmost) {
                                upmost=i;
                                leftmost=j;
                        } else if(i==upmost) {
                              if(j<leftmost) {
                                upmost=i;
                                leftmost=j;
                              }
                        }
                        break;
                }
               }
               flag=0;
               if(i>=len&&j>=len){
                for(int h=0;h<len;h++){
                        if(a[i-h][j-h]!=tar[h]) {
                        flag=1;
                        break;
                        }
                }
                if(!flag) {
                        if(i<upmost) {
                                upmost=i;
                                leftmost=j;
                        } else if(i==upmost) {
                              if(j<leftmost) {
                                upmost=i;
                                leftmost=j;
                              }
                        }
                        break;
                }
               }
        }
    }
    printf("%d %d\n",upmost,leftmost);
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                scanf(" %c",&ch);
                a[i][j]=toupper(ch);
            }
        scanf("%d",&k);
        while(k--){
                scanf("%s",tar);
                for(size_t h=0;h<strlen(tar);h++) tar[h]=toupper(tar[h]);
                found(tar,strlen(tar));
        }
        if(t)
        printf("\n");
    }
    return 0;
}
