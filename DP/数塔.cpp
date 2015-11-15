#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
//a[i]+=max{left,right};
int a[100][100],n,m,num;
int main(){
    freopen("x.txt","r",stdin);
while(scanf("%d",&n)!=EOF){
    for(int i=0;i<n;i++){
            memset(a,0,sizeof(a));
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            for(int k=0;k<=j;k++){
                scanf("%d",&a[j][k]);
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
            }
        }
        printf("%d\n",a[0][0]);
    }
}
return 0;
}
