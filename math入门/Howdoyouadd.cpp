#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
/**
题意：数a分成n个数相加，总共可以有几种算式？
利用组合数学的知识可知：答案为C(a+n-1,n-1);
这道题等价于n个相同的球放入m个不同的盒子中，且盒子可以为空。
因为数据范围很小，所以直接打表
**/
int arr[205][205];
void init(){
    for(int i=0;i<205;i++){
        for(int j=0;j<205;j++){
            arr[i][j]=0;
        }
    }
     arr[0][0]=1;
    arr[1][0]=1;
    arr[1][1]=1;
    for(int i=2;i<205;i++){
            for(int j=0;j<i+1;j++)
        arr[i][j]=(arr[i-1][j]+arr[i-1][j-1])%1000000;
    }
 /**   for(int i=0;i<105;i++){
        for(int j=0;j<i+1;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }**/
}
int n,a;
int main(){
    init();
    while(scanf("%d%d",&a,&n)!=EOF&&a!=0&&n!=0){
        printf("%d\n",arr[a+n-1][n-1]);
    }

return 0;
}
