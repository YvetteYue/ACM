#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define min(a,b) (a<b)?a:b
#define PI 3.141592657589793
double r;
struct point{
	double x,y;
};
//���⣺�����㾭��һ��Բ���ٵ�һ�����ε���̾���
//�����������Բ�ĽǶȣ�����ö�ٽǶȣ�����Բ�ϵĵ㵽��ʼ��ľ��롣
//ͬʱ���Բ�ϵ㵽���ε���̾��룬ͨ����x��y��ֵ�������̾��롣
//�������������͵���Сֵ���ɡ�
point recA,recB,Circle,start,P;
double PtoRec(point P,point recA,point recB){
	double x=0,y=0;
	if(P.x<recA.x)x=recA.x-P.x;
	else if(P.x>recB.x) x=P.x-recB.x;
	if(P.y<recA.y) y=recA.y-P.y;
	else if(P.y>recB.y) y=P.y-recB.y;
	return sqrt(x*x+y*y);
}
double dist(point P){
	return sqrt((start.x-P.x)*(start.x-P.x)+(start.y-P.y)*(start.y-P.y));
}
int main(){
	while(scanf("%lf%lf",&start.x,&start.y)!=EOF&&!(start.x==0&&start.y==0)){
		scanf("%lf%lf%lf",&Circle.x,&Circle.y,&r);
		scanf("%lf%lf",&recA.x,&recA.y);
		scanf("%lf%lf",&recB.x,&recB.y);
		double ans=0x7fffffff;
		if(recA.x>recB.x)swap(recA.x,recB.x);
		if(recA.y>recB.y)swap(recA.y,recB.y);
		for(double i=0;i<=360;i+=0.01){
			P.x=Circle.x+cos(i/180*PI)*r;
			P.y=Circle.y+sin(i/180*PI)*r;
			ans=min(ans,PtoRec(P,recA,recB)+dist(P));
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
