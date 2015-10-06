#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int m,n,a,b;
int sum;
//สýังฬโ
int cal(){
    int k=m/a;
    int y=n/b;
    int sum1=k*y;
    int w=m-k*a;
    int t=n-b*y;
     //printf("1 ");
    if(w==0&&t==0){
            return sum1;
    }
    int sum2;
    if(t!=0){
        int d=b/t;
    if(d==0) d=1;
     sum2=(k%d==0)?(k/d):(k/d+1);
    //printf("2 ");
    }
    if(w==0){
            return sum1+sum2;
    }
    int sum3;
    if(w!=0){
        int c=a/w;
    if(c==0) c=1;
     sum3=(y%c==0)?(y/c):(y/c+1);
    }
      // printf("3 ");
    if(t==0){
        return sum1+sum3;
    }
    //printf("4 ");
    int xx=(k%(b/t)==0)?(k/(b/t)):(k/(b/t)+1);
    int yy=(y%(a/w)==0)?(y/(a/w)):(y/(a/w)+1);
    int sum4=(y%(a/w)==0&&k%(b/t)==0)?(xx+yy+1):(xx+yy);
    return sum1+sum4;
}
int main(){
    //freopen("x.txt","r",stdin);
    while(scanf("%d%d",&m,&n)!=EOF){
        scanf("%d%d",&a,&b);
        printf("%d\n",cal());
    }

return 0;
}
