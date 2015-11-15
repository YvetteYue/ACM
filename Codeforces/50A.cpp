#include<cstdio>
#include<iostream>
using namespace std;
/**
用2*1的方块铺是特殊的，最后最多只能剩余一个
**/
int n,m;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        cout<<n*m/2<<endl;
    }

}
