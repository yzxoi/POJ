#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
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
Cn int N=50,TT=10;
int n,d,m,f[N*N][N][N],g[N*N][N][N],Ans;
I int gcd(CI a,CI b){return !b?a:gcd(b,a%b);}
I int Get(CI t,CI x1,CI y1,CI x2,CI y2){
	RI X=0,ix,iy,tx=x2-x1,ty=y2-y1,gg=abs(gcd(tx,ty));gg?(tx/=gg,ty/=gg):(tx=ty=1);
	for(ix=x1,iy=y1;ix<x2||iy<y2;ix+=tx,iy+=ty) X+=g[t][ix][iy];return X+g[t][x2][y2];
}
I int dp(CI t,CI x,CI y){
	#define Dis(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
	RI i,j,X;for(X=0,i=max(0,x-d);i<min(n+TT,x+d+1);i++) for(j=max(0,y-d);j<max(n+TT,y+d+1);j++) Dis(i,j,x,y)<=d*d&&(X=max(X,f[t-1][i][j]+Get(t,i,j,x,y)));return X;
}
int main(){
	RI i,j,x,y,t;W(1){
		if(read(n,d,m),!n&&!d&&!m) return 0;
		for(memset(g,0,sizeof(g)),i=1;i<=m;i++) read(x,y,t),x+=TT,y+=TT,g[t][x][y]++;
		for(memset(f,-1,sizeof(f)),Ans=0,t=0;t<=10;t++) for(i=0;i<n+TT;i++) for(j=0;j<n+TT;j++) Ans=max(Ans,(f[t][i][j]=dp(t,i,j)));
		writeln(Ans);
	}return 0;
}

