#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[2005],F[2005];
/**
小于5的情况一定要记住！！！
大于5的时候，明显最后话费的是价格最大的，所以前面只要用01背包计算即可
**/
int pack01(int N,int Vx){
    memset(F,0,sizeof (F));
    for(int i=1;i<=N;i++){
        for(int j=Vx;j>=a[i];j--){
            F[j]=max(F[j],F[j-a[i]]+a[i]);
        }
    }
    return F[Vx];
}
int main(){
    int n,V;
    while(scanf("%d",&n)!=EOF&&n!=0){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        scanf("%d",&V);
        int k=pack01(n-1,V-5);
        if(V<5)printf("%d\n",V);//要考虑小于5的情况！！！！
        else printf("%d\n",V-k-a[n]);
    }
return 0;
}
