#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
/**
��������˼�Ǹ���һ�����֣�ÿ�����ֿ��Լ���ĳ�����֣�
���������������ӵ����ĺ�<=k��ÿ��������󲻳���100
�����ɵ�ÿ����������10���Ͻ������͵�����Ƕ��١�
����˼·���Ȱ����ְ���%10�������Ӵ�С�����������ʱ�������ִ�С��������
Ȼ���Ȱ����ֶ����ӵ����Ա�10����������һ�������ϲ�ͣ��1ֱ������100��Ȼ�󻻸������ۼ�
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
