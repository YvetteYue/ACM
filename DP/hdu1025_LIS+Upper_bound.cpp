#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f;
/**
    ƶ��ĳ���Ҫ���Ӧ�ĸ��˵ĳ�����ͨ�������߲��ܽ��棬�����ǵ�����
    ���Կ������������˵Ķ�Ӧ���˵ĳ��������Ҹ����������м��ɡ�
    n^2�ᳬʱ������Ҫ�ĳ�nlogn�ĸ��Ӷȣ���Ҫ�õ����ֲ���
**/
int n,b[500005];
int S[500005];
struct point{
    int p,r;
};
point p[500005];
bool cmp(point a,point b){
    return a.p<b.p;
}
/*���Ĵ���*/
int dp()
{
	for(int i=1;i<=n;i++)S[i]=INF;
	memset(b,0,sizeof(b));
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int x = 1, y = i;
		int pos = upper_bound(S, S+i, p[i].r) - S; //upper_bound
		b[i] = pos;
		S[b[i]] = min(S[b[i]], p[i].r);
		ans = max(ans, b[i]);
	}
	return ans;
}
int main(){
    freopen("x.txt","r",stdin);
    int num=0;
    while(scanf("%d",&n)!=EOF){
            num++;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i].p,&p[i].r);
        }
        sort(p+1,p+n+1,cmp);
        //printf("sdffsdf");
        int k=dp();
        if(k>1) printf("Case %d:\nMy king, at most %d roads can be built.\n\n",num,k);
       else printf("Case %d:\nMy king, at most %d road can be built.\n\n",num,k);
    }
    return 0;
}
