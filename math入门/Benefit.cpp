#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
/**
LCM(a,b)=c已知a和c求最小的b
解题方法:如果c%a!=0那么没有b
否则：计算c/a与a的做大公约数，不断让a/gcd然后求公约数，
直到gcd=1时说明找到了a和b的gcd使得上等式成立。
**/
int n,a,b;
int gcd(int a,int b){
    if(b==0)return a;
       return  gcd(b,a%b);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            if(b%a==0){
                    b=b/a;
                int k=1;
                int g=gcd(a,b);
                while(g!=1){
                    k*=g;
                    a/=g;
                    g=gcd(a,b);
                }
                printf("%d\n",b*k);
            }
            else printf("NO SOLUTION\n");
        }
    }
    return 0;
}
