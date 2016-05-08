#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int res[40];
//1-26-A-Z 30-39-0-9
void ini(){
    memset(res,0,sizeof(res));
    res[0]=0;
    res[1]=1;//A
    res[2]=0;//B
    res[3]=0;//C
    res[4]=0;//D
    res[5]=33;//E
    res[6]=0;//F
    res[7]=0;//G
    res[8]=8;//H
    res[9]=9;//I
    res[10]=12;//J
    res[11]=0;//K
    res[12]=10;//L
    res[13]=13;//M
    res[14]=0;//N
    res[15]=15;//O
    res[16]=0;//P
    res[17]=0;//Q
    res[18]=0;//R
    res[19]=32;//S
    res[20]=20;//T
    res[21]=21;//U
    res[22]=22;//V
    res[23]=23;//W
    res[24]=24;//X
    res[25]=25;//Y
    res[26]=35;//Z
    res[27]=0;//
    res[28]=0;
    res[29]=0;
    res[30]=0;
    res[31]=31;//1
    res[32]=19;//2
    res[33]=5;//3
    res[34]=0;//4
    res[35]=26;//5
    res[36]=0;//6
    res[37]=0;//7
    res[38]=38;//8
    res[39]=0;//9
}
string str;
int main(){
    ini();
	while(cin>>str){
        int flag1=1;
        int flag2=1;
        int i,j;
        cout<<str;
        int len=str.length();
        for(i=0,j=len-1;i<=j;i++,j--){
            int d1,d2;
            //cout<<endl;
            if(str[i]>='0'&&str[i]<='9') d1=30+str[i]-'0';
            if(str[i]>='A'&&str[i]<='Z') d1=str[i]-'A'+1;
            if(str[j]>='0'&&str[j]<='9') d2=30+str[j]-'0';
            if(str[j]>='A'&&str[j]<='Z') d2=str[j]-'A'+1;
            //cout<<str[i]<<":"<<d1<<" "<<str[j]<<":"<<d2<<endl;
            if(flag1&&str[i]==str[j]) flag1=1;
            else flag1=0;
            //cout<<d2<<" "<<res[d1]<<" "<<d1<<res[d2]<<endl;
            if(flag2&&res[d1]==d2&&res[d2]==d1) flag2=1;
            else flag2=0;
            //cout<<flag1<<" "<<flag2<<endl;
            if(flag1==0&&flag2==0) break;
        }
        if(flag1&&flag2)cout<<" -- is a mirrored palindrome."<<endl;
        else if(flag1&&flag2==0)cout<<" -- is a regular palindrome."<<endl;
        else if(flag1==0&&flag2)cout<<" -- is a mirrored string."<<endl;
        else cout<<" -- is not a palindrome."<<endl;
        cout<<endl;
	}
	return 0;
}
