#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
/**
LCM(a,b)=c��֪a��c����С��b
���ⷽ��:���c%a!=0��ôû��b
���򣺼���c/a��a������Լ����������a/gcdȻ����Լ����
ֱ��gcd=1ʱ˵���ҵ���a��b��gcdʹ���ϵ�ʽ������
**/
int n,a,b;
int gcd(int a,int b){
    if(b==0)return a;
       return  gcd(b,a%b);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            if(b%a==0){
                    b=b/a;
                int k=1;
                int g=gcd(a,b);
                while(g!=1){
                    k*=g;
                    a/=g;
                    g=gcd(a,b);
                }
                printf("%d\n",b*k);
            }
            else printf("NO SOLUTION\n");
        }
    }
    return 0;
}
