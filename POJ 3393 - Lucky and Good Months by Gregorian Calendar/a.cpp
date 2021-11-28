#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<iostream>
#include<queue>
#define W while
#define I inline
#define gc getchar
#define D isdigit(c=gc())
#define Cn const
#define pc(c) putchar((c))
#define LL long long
using namespace std;
I int read(){int x=0,f=1;char c;W(!D) f=c^'-'?1:-1;W(x=(x<<3)+(x<<1)+(c&15),D);return x*f;}
I void write(int x){x<0&&(pc('-'),x=-x),x<10?(pc(x+'0'),0):(write(x/10),pc(x%10+'0'),0);}
const int N=100010;
const int Pm[]={0,31,28,31,30,31,30,31,31,30,31,30,31},
          Qm[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int T,sy,sm,ty,tm,Ans1,Ans2,YY[N];
I int check_leap(int x){
	if(x==1700) return 1;
	if(0<x&&x<1582) return x%4==0;
	if(x%4==0&&x%100) return 1;
	if(x%400==0) return 1;
	return 0;
}
I int count_day(int Y,int M){
	int s=5;s+=YY[Y-1];s%=7;
	for(int i=1;i<=M;i++) s+=check_leap(Y)?Qm[i]:Pm[i],s%=7;
	if(Y>1752) s-=11;
	else if(Y==1752&&M>=9) s-=11;
	s+=14;s%=7;
	return s;
}
int main(){
	for(int i=1;i<=10000;i++) YY[i]=YY[i-1]+365+check_leap(i),YY[i]%=7;
	T=read();W(T--){
		sy=read(),sm=read(),ty=read(),tm=read();
		Ans1=Ans2=0;for(int i=sy;i<=ty;i++)
			for(int j=(i==sy?sm:1);j<=(i==ty?tm:12);j++){
				register int ct=count_day(i,j);
				if((i!=ty||(i==ty&&j!=tm))&&(ct==5||ct==6||ct==0)) Ans2++;
				if(ct==6||ct==0||ct==5) Ans1++;
			}
		register int ct=count_day(sy,sm-1);
		Ans2+=(ct==5||ct==6||ct==0);
		write(Ans1),pc(' '),write(Ans2),pc('\n');
	}return 0;
}
