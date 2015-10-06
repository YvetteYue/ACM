#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
/**
智商捉急啊！！
这道题求得是已知GCD和LCM 求最小的a情况下的a和b
很明显，最小的a就是GCD

**/
int n,a,b;
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            if(b%a!=0)printf("-1\n");
            else printf("%d %d\n",a,b);
        }
    }

return 0;
}
