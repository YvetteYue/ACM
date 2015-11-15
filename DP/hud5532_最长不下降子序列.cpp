#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f3f
int n,b[500005],p[500005];
int S[100005];
int dp1()
{
	for(int i=1;i<=n;i++)S[i]=INF;
	memset(b,0,sizeof(b));
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int x = 1, y = i;
		int pos = upper_bound(S, S+i, p[i]) - S; //upper_bound
		b[i] = pos;
		S[b[i]] = min(S[b[i]], p[i]);
		ans = max(ans, b[i]);
	}
	return ans;
}
int main(){
   // freopen("x.txt","r",stdin);
    int num=0,m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
            scanf("%d",&n);
            num++;
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
        }
        //printf("sdffsdf");
        int k=dp1();
        reverse(p+1,p+n+1);
        int mm=max(k,dp1());
        if(mm+1>=n)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
