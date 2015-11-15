#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
    int len;
    char s[105];
    while(scanf("%s",s)!=EOF){
        len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'
               &&s[i]!='U'&&s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='Y'&&s[i]!='y'){
                printf(".%c",tolower(s[i]));
            }
        }
        cout<<endl;
    }


return 0;
}
