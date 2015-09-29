#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
/**
这道题的意思是给你一堆数字，每个数字可以加上某个数字，
但是所有数字增加的数的和<=k，每个数字最大不超过100
求生成的每个数字数以10的上界整数和的最大是多少。
解题思路：先把数字按照%10的余数从大到小排序，余数相等时按照数字从小到大排序。
然后先把数字都增加到可以被10整除后再在一个数字上不停加1直到等于100。然后换个数字累加
**/
using namespace std;
bool cmp(int a,int b){
    int k=a%10;
    int t=b%10;
    if(k==t) return a<b;
    return k>t;
}
int main(){
    int n,k,s,a[100005];
    while(scanf("%d%d",&n,&k)!=EOF){
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cmp);
        int j=0,num=0;
       while(num<k){
            if((a[j]<100&&a[j]%10!=0)){
                a[j]++;
                 num++;
            }else {
              //  printf("%d\n",a[j]);
                j++;}

            if(j==n){
                break;
            }

        }
        //printf("num %d\n",num);
         j=0;
        while(num<k){

            if(a[j]<100){
                    num++;
                    a[j]++;
            }
            else j++;
            if(j==n)break;

        }
        for(int i=0;i<n;i++){
            //   printf("%d ",a[i]);
            sum+=a[i]/10;
        }
        printf("%d\n",sum);
    }
    return 0;
}
