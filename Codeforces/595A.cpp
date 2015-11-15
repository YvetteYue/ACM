#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,sum,m,a,b;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
            sum=0;
            for(int j=0;j<n;j++)
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            if(a+b>0)sum++;
        }
        printf("%d\n",sum);
    }

return 0;
}
