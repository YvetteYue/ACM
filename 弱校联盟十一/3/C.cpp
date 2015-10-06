#include<cstdio>
#include<iostream>
using namespace std;
int a[10005];
int main(){
    double sum;
    int n;
while(scanf("%d",&n)!=EOF){
    sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
     sum=sum/n;
     int num=0;
    for(int i=0;i<n;i++){
        if(sum<(double)a[i]){
            num++;
        }
    }
    printf("%d\n",num);
}
return 0;
}
