#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
/**
����׽��������
������������֪GCD��LCM ����С��a����µ�a��b
�����ԣ���С��a����GCD

**/
int n,a,b;
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            if(b%a!=0)printf("-1\n");
            else printf("%d %d\n",a,b);
        }
    }

return 0;
}
