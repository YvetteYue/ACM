#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
/**
��ʼ״̬��f[0]=a[0];
״̬ת�ƣ�f[i]=max{f[i-1]+a[i,a[i]};
**/
/**
������������к�
��������dpѰ��������һ�κ����
**/
struct point{
int sum,b;
};
point f[10005];
int n;
int a[10005];
int main(){
   // freopen("x.txt","r",stdin);
while(scanf("%d",&n)!=EOF&&n!=0){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    f[0].sum=a[0];
    f[0].b=0;
    int ma=0;
    for(int i=1;i<n;i++){
        f[i].sum=max(f[i-1].sum+a[i],a[i]);
        if(f[i-1].sum>0)f[i].b=f[i-1].b;
        else f[i].b=i;
        if(f[ma].sum<f[i].sum)ma=i;
    }
    if(f[ma].sum<0)printf("0 %d %d\n",a[0],a[n-1]);
   else printf("%d %d %d\n",f[ma].sum,a[f[ma].b],a[ma]);
}

return 0;
}
