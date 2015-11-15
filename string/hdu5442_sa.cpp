#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
/**
题意：求一个循环的字符串，顺序或者逆序，能找到一个字典序最大的字符串。
思路：使用后缀数组，顺序的两个字符串相同的和逆序的两个字符串拼接都求一遍，求出最大的字符串，然后比较两个字符串的大小即可。
注意:使用后缀数组求得的字符串长度不一定是输入的字符串长度，可能比他大也可能比他小。但是我们要找的字符串长度必须是输入的字符串长度。
所以可能两个字符串的大小不一样，但是他们的LCP大于等于输入的字符串长度。所以需要找到位置最小的字符串。然后比较他们两个的最大值即可。
**/
const int N = 40005;
char str[N];
int sa[N];
char r1[40005],r2[40005],s[40005];
int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
// 用于比较第一关键字与第二关键字,
// 比较特殊的地方是,预处理的时候,r[n]=0(小于前面出现过的字符)
int wa[N],wb[N],wss[N],wv[N];

int rankk[N],height[N];
void write(int s[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",s[i]);
    }
    printf("\n");
}
//r输入字符，sa后缀数组，x民警次数组
void da(char *r,int *sa,int n,int m){ //此处N比输入的N要多1，为人工添加的一个字符，用于避免CMP时越界
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wss[i]=0;
    for(i=0;i<n;i++) wss[x[i]=r[i]]++;
  //  write(wss,m);
    for(i=1;i<m;i++) wss[i]+=wss[i-1];
   //  write(wss,m);
    for(i=n-1;i>=0;i--) sa[--wss[x[i]]]=i; //预处理长度为1
   // write(sa,n);
    for(j=1,p=1;p<n;j*=2,m=p) //通过已经求出的长度J的SA，来求2*J的SA
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i; // 特殊处理没有第二关键字的
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j; //利用长度J的，按第二关键字排序
       // write(y,n);
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wss[i]=0;
        for(i=0;i<n;i++) wss[wv[i]]++;
        for(i=1;i<m;i++) wss[i]+=wss[i-1];
        for(i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i];  //基数排序部分
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;  //更新名次数组x[],注意判定相同的
    }
}

void calheight(char *r,int *sa,int n){ // 此处N为实际长度
    int i,j,k=0;        // height[]的合法范围为 1-N, 其中0是结尾加入的字符
    for(i=1;i<=n;i++) rankk[sa[i]]=i;  // 根据SA求RANK
    for(i=0;i<n; height[rankk[i++]] = k ) // 定义：h[i] = height[ rank[i] ]
    for(k?k--:0,j=sa[rankk[i]-1]; r[i+k]==r[j+k]; k++); //根据 h[i] >= h[i-1]-1 来优化计算height过程
}
void cmp(int s1,int s2,int n){
    //printf("%d %d \n",s1,s2);
    int flag = 0;
    for(int i = 0 ; i < n ; i ++){
        if(r1[(s1 + i)] == r2[(s2 + i) ]) continue;
        if(r1[(s1 + i)] > r2[(s2 + i )]) flag = 1;
            else flag = -1;
        if(flag != 0) break;
    }
    if(flag == 0){
        if(s1+1 <= n-s2) printf("%d 0\n",s1+1);
            else printf("%d 1\n",n-s2);
    }
    else if(flag > 0) printf("%d 0\n",s1+1);
    else printf("%d 1\n",n-s2);
}
int main(){
   int k,size,m;
   scanf("%d",&size);
   while(size--){
        scanf("%d",&m);
        scanf("%s",s);
        for(int i=0;i<m;i++){
            r1[i]=r1[i+m]=s[i];
            r2[m-i-1]=r2[2*m-i-1]=s[i];
        }
        int len=m*2-1;
        r1[len]=r2[len]=0;
        da(r1,sa,len+1,128);  //注意区分此处为n+1,因为添加了一个结尾字符用于区别比较
        calheight(r1,sa,len);
        int st=sa[len];
        for(int i=len;i>0;i--){//
            if(height[i]>=m&&sa[i-1]<m)st=min(st,sa[i-1]);
            if(height[i]<m)break;
        }
        da(r2,sa,len+1,128);
        calheight(r2,sa,len);
        int st2=sa[len];
        for(int i=len;i>0;i--){
            if(height[i]>=m&&sa[i-1]<m)st2=max(st2,sa[i-1]);
            if(height[i]<m)break;
        }
        cmp(st,st2,m);//比较顺序或者逆序的两个字符串的大小
   }
}
