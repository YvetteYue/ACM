#include<cstdio>
#include<cstring>
using namespace std;
/**
求一个数字是否可以分成两个偶数
条件：该数字不仅为偶数而且要大于2
**/
int main(){
   int n;
    while(scanf("%d",&n)!=EOF){
        if(n%2==0&&n>2){
            printf("YES\n");
        }else printf("NO\n");

    }

return 0;
}
