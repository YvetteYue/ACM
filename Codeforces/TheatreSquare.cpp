#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
/**
ˮ�⣺�����������ö��ٸ������θ���
**/
int main(){
    LL x,y,n,m,a;
    while(scanf("%lld%lld%lld",&n,&m,&a)!=EOF){
        if(n%a==0){
            x=n/a;
        }else x=n/a+1;
        if(m%a==0)y=m/a;
        else y=m/a+1;
        printf("%lld\n",x*y);
    }

return 0;
}
