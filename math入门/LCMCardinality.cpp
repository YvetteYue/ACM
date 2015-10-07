#include<cstdio>
#include<cstring>
#include<iostream>
//数论，因式分解
using namespace std;
int n;
int main(){
    while(scanf("%d",&n)!=EOF&&n!=0){
            int sum=n;
        int ans=1;
        int i=2;
        while(n!=1){
            int flag=0,k=0;
            while(n%i==0){
                flag=1;
                n/=i;
                k++;
            }
            if(flag) ans*=(2*k+1);
            i++;
        }
        ans=ans/2+1;
        printf("%d %d\n",sum,ans);
    }
return 0;
}
