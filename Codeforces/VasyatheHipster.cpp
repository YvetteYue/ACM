#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int m,n;
int main(){
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m<n){int t=m;m=n;n=t;}
        int k=(m-n)/2;
        printf("%d %d\n",n,k);
    }
return 0;
}
