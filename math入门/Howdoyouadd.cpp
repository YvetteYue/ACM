#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
/**
���⣺��a�ֳ�n������ӣ��ܹ������м�����ʽ��
���������ѧ��֪ʶ��֪����ΪC(a+n-1,n-1);
�����ȼ���n����ͬ�������m����ͬ�ĺ����У��Һ��ӿ���Ϊ�ա�
��Ϊ���ݷ�Χ��С������ֱ�Ӵ��
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
