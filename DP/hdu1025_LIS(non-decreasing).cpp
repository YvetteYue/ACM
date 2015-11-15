#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define INF 0xfffffff;
/**
    贫穷的城市要与对应的富人的城市联通，但是线不能交叉，城市是递增的
    所以可以先利用穷人的对应富人的城市排序，找个递增的序列即可。
    n^2会超时，所以要改成nlogn的复杂度，需要用到二分查找
**/
int n,b[500005],S[500005];

struct point{
    int p,r;
};
point p[500005];
bool cmp(point a,point b){
    return a.p<b.p;
}
int binarySearch(int x,int y,int v){
    while(x<=y){
        int mid=x+(y-x)/2;
        if(S[mid]<=v)  x=mid+1;//严格的上升去掉等号即可
        else y=mid-1;
    }
    return x;
}

int LIS(point p[],int n){
    int ans=1;
    for(int i=0;i<=n;i++)S[i]=INF;
    memset(b,0,sizeof(b));
    for(int k=1;k<=n;k++){
        int x=1,y=k;
        int pos=binarySearch(x,y,p[k].r);
        b[k]=pos;
        S[b[k]]=min(S[b[k]],p[k].r);
        ans=max(ans,b[k]);
    }
    return ans;
}
int main(){
    //freopen("x.txt","r",stdin);
    int num=0;
    while(scanf("%d",&n)!=EOF){
            num++;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i].p,&p[i].r);
        }
        sort(p+1,p+n+1,cmp);
        //printf("sdffsdf");
        int k=LIS(p,n);
        if(k>1)printf("Case %d:\nMy king, at most %d roads can be built.\n\n",num,k);
        else
        printf("Case %d:\nMy king, at most %d road can be built.\n\n",num,k);
    }
    return 0;
}
