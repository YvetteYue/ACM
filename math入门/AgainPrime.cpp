#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
/**
���⣺��n!%m^k=0ʱ����k
���ⷽ������m��ʽ�ֽ⣬Ȼ����n!���ж��ٸ�k...
����n/i+n/(i*i)+n/(i*i*i)+....֪������������0λ�á�
**/
int n,M,N;
int main() {
    scanf("%d",&n);
        for(int i=0;i<n;i++){
                int ans=0x3f3f3f3f;
            scanf("%d%d",&M,&N);
            int j=2;
            while(M!=1){
                int k=0;
                while(M%j==0){
                    M=M/j;
                    k++;
                }
                if(k!=0){
                        int num=N;
                int tmp=0;
                    while(num!=0){
                        tmp+=num/j;
                        num/=j;
                    }
                    ans=min(ans,tmp/k);
                }
                j++;
            }
            printf("Case %d:\n",i+1);
            if(ans)printf("%d\n",ans);
            else printf("Impossible to divide\n");
        }
    return 0;
}
