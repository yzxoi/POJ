#include<cstdio>
#include<iostream>
#include<cmath>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define W while
#define I inline
#define RI register int
#define LL long long
#define Cn const
#define CI Cn int&
#define gc getchar
#define D isdigit(c=gc())
#define pc(c) putchar((c))
using namespace std;
namespace FastIO{
	Tp I void read(Ty& x){char c;int f=1;x=0;W(!D) f=c^'-'?1:-1;W(x=(x<<3)+(x<<1)+(c&15),D);x*=f;}
	Ts I void read(Ty& x,Ar&... y){read(x),read(y...);}
	Tp I void write(Ty x){x<0&&(pc('-'),x=-x,0),x<10?(pc(x+'0'),0):(write(x/10),pc(x%10+'0'),0);}
	Tp I void writeln(Cn Ty& x){write(x),pc('\n');}
}using namespace FastIO;
Cn int N=10,M=16;
int n,a[N][N],s[N][N];
double f[M][N][N][N][N],X,inf=2e9;
I double Sqr(double x){return x*x;}
#define S(x1,y1,x2,y2) (s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1])
I double Get(CI x1,CI y1,CI x2,CI y2){return Sqr(S(x1,y1,x2,y2)-X);} 
I double dp(CI k,CI x1,CI y1,CI x2,CI y2){
	if(k==n) return Get(x1,y1,x2,y2);
	if(-inf!=f[k][x1][y1][x2][y2]) return f[k][x1][y1][x2][y2];
	RI i;for(f[k][x1][y1][x2][y2]=inf,i=x1;i<x2;i++) f[k][x1][y1][x2][y2]=min(f[k][x1][y1][x2][y2],Get(x1,y1,i,y2)+dp(k+1,i+1,y1,x2,y2));
	for(i=x1;i<x2;i++) f[k][x1][y1][x2][y2]=min(f[k][x1][y1][x2][y2],dp(k+1,x1,y1,i,y2)+Get(i+1,y1,x2,y2));
	for(i=y1;i<y2;i++) f[k][x1][y1][x2][y2]=min(f[k][x1][y1][x2][y2],Get(x1,y1,x2,i)+dp(k+1,x1,i+1,x2,y2));
	for(i=y1;i<y2;i++) f[k][x1][y1][x2][y2]=min(f[k][x1][y1][x2][y2],dp(k+1,x1,y1,x2,i)+Get(x1,i+1,x2,y2));
	return f[k][x1][y1][x2][y2];
}
int main(){
	RI i,j,k,l,t;for(read(n),i=1;i<=8;i++) for(j=1;j<=8;j++) read(a[i][j]),s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j],X+=a[i][j];
	for(t=1;t<=n;t++) for(i=1;i<=8;i++) for(j=1;j<=8;j++) for(k=1;k<=8;k++) for(l=1;l<=8;l++) f[t][i][j][k][l]=-inf;
	return X/=n,printf("%.3f\n",sqrt(dp(1,1,1,8,8)/n)),0;
}

