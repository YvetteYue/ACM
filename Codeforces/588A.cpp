#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[100005],p[100005];
/**
    �������⣬Ҫ������ÿ������ļ۸����Ҫ���⣬Ҫ��ȹ�n������ٻ��ѡ�
    ����취�����۸���͵�ʱ�������򣬼۸�ߵ�ʱ�����û��ʣ����⣬ֻҪ������Ҫ���������ɡ�
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
