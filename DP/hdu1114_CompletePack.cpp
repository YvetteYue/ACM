#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int INF= 100000000;
/**
    ��ȫ������һλд��
    ��סҪ��ʼ������Ϊ���������ǻ�ü�ֵ��С��������Ҫ�������ʼ��ΪINF
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
