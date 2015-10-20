#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[100005],p[100005];
/**
    买肉问题，要求输入每天买肉的价格和需要的肉，要求度过n天的最少花费。
    解决办法：当价格最低的时候尽量多买，价格高的时候，如果没有剩余的肉，只要买当天需要的肉量即可。
**/
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i],&p[i]);
        }
        int min=105;
        int w=0;
        for(int i=0;i<n;i++){
            if(p[i]>min){
                w+=min*a[i];
            }else {min=p[i];
                w+=min*a[i];
            }
        }
        printf("%d\n",w);
    }

return 0;
}
