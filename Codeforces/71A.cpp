#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
char s[105];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        int sum=strlen(s);
        if(sum>10)cout<<s[0]<<sum-2<<s[sum-1]<<endl;
        else cout<<s<<endl;
    }

return 0;
}
