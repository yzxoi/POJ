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
const int N=110<<1;
int n,w,h,a[N][N],sum[N][N],s,t,Ans;
int main(){
	W(n=read()){
		w=read(),h=read();memset(a,0,sizeof(a));memset(sum,0,sizeof(sum));
		for(int x,y,i=1;i<=n;i++) a[x=read()][y=read()]=1;
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		s=read(),t=read();Ans=0;
		for(int i=0;i<=100&&i+s<=100;i++)
			for(int j=0;j<=100&&j+t<=100;j++) Ans=max(Ans,sum[i+s][j+t]-sum[i][j+t]-sum[i+s][j]+sum[i][j]);
		write(Ans),pc('\n');
	}return 0;
}
