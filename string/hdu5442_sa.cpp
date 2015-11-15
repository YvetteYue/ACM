#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
/**
���⣺��һ��ѭ�����ַ�����˳������������ҵ�һ���ֵ��������ַ�����
˼·��ʹ�ú�׺���飬˳��������ַ�����ͬ�ĺ�����������ַ���ƴ�Ӷ���һ�飬��������ַ�����Ȼ��Ƚ������ַ����Ĵ�С���ɡ�
ע��:ʹ�ú�׺������õ��ַ������Ȳ�һ����������ַ������ȣ����ܱ�����Ҳ���ܱ���С����������Ҫ�ҵ��ַ������ȱ�����������ַ������ȡ�
���Կ��������ַ����Ĵ�С��һ�����������ǵ�LCP���ڵ���������ַ������ȡ�������Ҫ�ҵ�λ����С���ַ�����Ȼ��Ƚ��������������ֵ���ɡ�
**/
const int N = 40005;
char str[N];
int sa[N];
char r1[40005],r2[40005],s[40005];
int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
// ���ڱȽϵ�һ�ؼ�����ڶ��ؼ���,
// �Ƚ�����ĵط���,Ԥ�����ʱ��,r[n]=0(С��ǰ����ֹ����ַ�)
int wa[N],wb[N],wss[N],wv[N];

int rankk[N],height[N];
void write(int s[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",s[i]);
    }
    printf("\n");
}
//r�����ַ���sa��׺���飬x�񾯴�����
void da(char *r,int *sa,int n,int m){ //�˴�N�������NҪ��1��Ϊ�˹���ӵ�һ���ַ������ڱ���CMPʱԽ��
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wss[i]=0;
    for(i=0;i<n;i++) wss[x[i]=r[i]]++;
  //  write(wss,m);
    for(i=1;i<m;i++) wss[i]+=wss[i-1];
   //  write(wss,m);
    for(i=n-1;i>=0;i--) sa[--wss[x[i]]]=i; //Ԥ������Ϊ1
   // write(sa,n);
    for(j=1,p=1;p<n;j*=2,m=p) //ͨ���Ѿ�����ĳ���J��SA������2*J��SA
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i; // ���⴦��û�еڶ��ؼ��ֵ�
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j; //���ó���J�ģ����ڶ��ؼ�������
       // write(y,n);
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wss[i]=0;
        for(i=0;i<n;i++) wss[wv[i]]++;
        for(i=1;i<m;i++) wss[i]+=wss[i-1];
        for(i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i];  //�������򲿷�
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;  //������������x[],ע���ж���ͬ��
    }
}

void calheight(char *r,int *sa,int n){ // �˴�NΪʵ�ʳ���
    int i,j,k=0;        // height[]�ĺϷ���ΧΪ 1-N, ����0�ǽ�β������ַ�
    for(i=1;i<=n;i++) rankk[sa[i]]=i;  // ����SA��RANK
    for(i=0;i<n; height[rankk[i++]] = k ) // ���壺h[i] = height[ rank[i] ]
    for(k?k--:0,j=sa[rankk[i]-1]; r[i+k]==r[j+k]; k++); //���� h[i] >= h[i-1]-1 ���Ż�����height����
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
        da(r1,sa,len+1,128);  //ע�����ִ˴�Ϊn+1,��Ϊ�����һ����β�ַ���������Ƚ�
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
        cmp(st,st2,m);//�Ƚ�˳���������������ַ����Ĵ�С
   }
}
