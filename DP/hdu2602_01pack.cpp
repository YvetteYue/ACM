#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int v[1005],w[1005],F[1005];
//F[i,v]=max{F[i-1,v],F[i-1,v-Ci]+Wi}
//版本1最裸的o(n^2)
/**
重点需要考虑的是如果背包容量为0的情况！
**/
/**int pack01(int N,int V){
    memset(F[0],0,sizeof(F[0]));
    for(int i=1;i<=N;i++){
        for(int j=0;j<=V;j++){
                if(v[i]<=j)
            F[i][j]=max(F[i-1][j],F[i-1][j-v[i]]+w[i]);
        else F[i][j]=F[i-1][j];
        }
    }
    return F[N][V];
}**/
int pack01(int N,int V){
    memset(F,0,sizeof(F));
    for(int i=1;i<=N;i++){
        for(int j=V;j>=v[i];j--){
            F[j]=max(F[j],F[j-v[i]]+w[i]);
        }
    }
    return F[V];
}

int main(){
    int t,m,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d%d",&m,&n);
        for(int j=1;j<=m;j++){
            scanf("%d",&w[j]);
        }
        for(int j=1;j<=m;j++){
            scanf("%d",&v[j]);
        }
        int k=pack01(m,n);
        printf("%d\n",k);
    }

return 0;
}



