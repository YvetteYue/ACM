#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;
int main(){
    LL n;
while(scanf("%I64d",&n)!=EOF){
        int i=2;
        LL sum=1;
        LL num=n;
    while(n>1&&i*i<=num){
            if(n%i==0) sum*=i;
        while(n%i==0){
            n/=i;
        }
        i++;
    }
    printf("%I64d\n",sum);
}
return 0;
}


