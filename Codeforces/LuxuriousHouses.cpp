#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> que;
int a[100005],b[100005],n;
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1)b[n-1]=0;
            else if(que.top()>=a[i]){
                b[i]=que.top()-a[i]+1;
            }
            que.push(a[i]);
        }
        for(int i=0;i<n;i++){
            printf("%d",b[i]);
            if(i<n-1)putchar(' ');
            else putchar('\n');
        }
    }


return 0;
}
