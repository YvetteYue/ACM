#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[2005],F[2005];
/**
С��5�����һ��Ҫ��ס������
����5��ʱ��������󻰷ѵ��Ǽ۸����ģ�����ǰ��ֻҪ��01�������㼴��
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
        if(V<5)printf("%d\n",V);//Ҫ����С��5�������������
        else printf("%d\n",V-k-a[n]);
    }
return 0;
}
