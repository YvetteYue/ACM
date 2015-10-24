#include<cstdio>
#include<cstring>
using namespace std;
int a[55];
int main(){
   int n,temp,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int w=k-1;
        while(a[w]==a[k-1]&&w<n&&a[w]>0){
            w++;
        }
        printf("%d\n",w);
    }
return 0;
}
