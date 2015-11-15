#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int pow[]={16,7,8,1,1,2,3};
int sum1,sum2,t,m,n,flag1,flag2;
char k[5];
int main(){
    //freopen("x.txt","r",stdin);
    scanf("%d",&t);
    for(int i=0;i<t;i++){
            sum1=0;sum2=0;
            flag1=0;flag2=0;
        scanf("%d",&m);

        for(int j=0;j<m;j++){
            scanf("%s",&k);
            sum1+=pow[k[0]-'A'];
           if(k[0]=='B')flag1=1;
			if(k[0]=='C')flag2=1;
        }
        if(sum1>1&&(flag1==0||flag2==0)) sum1-=1;
        scanf("%d",&n);
        flag1=0;flag2=0;
        for(int l=0;l<n;l++){
            scanf("%s",&k);
            sum2+=pow[k[0]-'A'];
            if(k[0]=='B')flag1=1;
			if(k[0]=='C')flag2=1;
        }
        if(sum2>1&&(flag1==0||flag2==0)) sum2-=1;
        //printf("%d %d\n",sum1,sum2);
        if(sum1>sum2)printf("red\n");
    else if(sum1==sum2)printf("tie\n");
    else printf("black\n");
    }

    return 0;
}
