#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int INF= 100000000;
/**
    完全背包：一位写法
    记住要初始化，因为这道题求得是获得价值最小，所以需要将数组初始化为INF
**/
int F[10005],n,m,W,a,b,v[10005],w[10005];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       scanf("%d%d",&a,&b);
        W=b-a;
       // printf("%d ",W);
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            scanf("%d%d",&v[j],&w[j]);
        }
        for(int k=0;k<=W;k++)F[k]=INF;
        F[0]=0;
        for(int j=0;j<m;j++){
            for(int k=w[j];k<=W;k++){
                F[k]=min(F[k],F[k-w[j]]+v[j]);
                //printf("%d ",F[k]);
            }
        }
        if(F[W]==INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",F[W]);
    }
return 0;
}
