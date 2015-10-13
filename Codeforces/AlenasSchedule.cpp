#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[10000];
int main(){
    int begin,end;
    while(scanf("%d",&n)!=EOF){
            int flag=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]==1)flag=1;
        }
        if(flag==0)printf("0\n");
        else{
        for(int i=0;i<n;i++){
            if(a[i]==1){
                begin=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(a[i]==1){
                end=i;
                break;
            }
        }
        int k=0;
        int j=begin;
        while(j<=end&&j>=begin){
            if(a[j]==1){k++;j++;}
            int num=0;
            while(a[j]==0){
                num++;
                j++;
            }
            if(num==1)k++;
        }

        printf("%d\n",k);
        }
    }


return 0;
}
