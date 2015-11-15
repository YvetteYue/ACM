#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
/**
HDU1160
    转移方程b[k]=max(max(b[j]|a[j]<a[k],j<k)+1,1);
    最长上升子序列策略是：用dp动态记录最长长度
    这道题容易错的地方有：num和val都要是升序和降序。
    还有一个就是当所有数字相等的时候最长上升序列可以为一个
**/
struct point {
    int num,val,nn;
};
point p[1005];
int b[1005];
int dp[1005];
int sum[1005];
bool cmp(point a,point b){
    if(a.val==b.val) return a.num<b.num;
    return a.val>b.val;
}
int main(){
    int i=0;
    freopen("x.txt","r",stdin);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    while(scanf("%d%d",&p[i].num,&p[i].val)!=EOF){
        p[i].nn=i+1;
        i++;
    }
    sort(p,p+i,cmp);
 /**   for(int k=0;k<i;k++){
        printf("%d %d %d\n",p[k].num,p[k].val,p[k].nn);
    }**/
    for(int j=1;j<i;j++){
            int max=j;
        for(int k=0;k<j;k++){
            if(p[k].num<p[j].num&&dp[max]<dp[k]&&p[k].val!=p[j].val){
                max=k;
            }
        }
        if(max==j){dp[j]=1;}
        else dp[j]=dp[max]+1;
        b[j]=max;
      //  printf("%d %d\n",dp[j],max);
    }
    int mm=0;
    for(int k=0;k<i;k++){
        if(dp[mm]<=dp[k]) mm=k;
    }
    printf("%d\n",dp[mm]);
    //printf("%d ",p[mm].nn);
   // int m=0;
    int ss=dp[mm];
    for(int k=0;k<ss;k++){
        sum[ss-k]=p[mm].nn;
       //printf("%d ",sum[ss-k]);
        mm=b[mm];
    }
    for(int k=1;k<=ss;k++){
        printf("%d\n",sum[k]);
    }
    return 0;
}
