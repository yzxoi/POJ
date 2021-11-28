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
Cn int N=30,TT=5;
int n,d,m,f[N*N][N][N],g[N*N][N][N],Ans;
I int gcd(CI a,CI b){return !b?a:gcd(b,a%b);}
I int Get(CI t,CI x1,CI y1,CI x2,CI y2){
	RI X=0,ix,iy,tx=abs(x2-x1),ty=abs(y2-y1),gg=abs(gcd(tx,ty));gg&&(tx/=gg,ty/=gg),!tx?(ty=1):!ty&&(tx=1);
	x1>x2&&(tx=-tx),y1>y2&&(ty=-ty);
	for(ix=x1,iy=y1;ix!=x2||iy!=y2;ix+=tx,iy+=ty) X+=g[t][ix][iy];
	return X+g[t][x2][y2];
}
I int dp(CI t,CI x,CI y){
	#define Dis(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
	RI i,j,X;for(X=0,i=max(0,x-d);i<min(n+TT*2,x+d+1);i++) for(j=max(0,y-d);j<max(n+TT*2,y+d+1);j++) Dis(i,j,x,y)<=d*d&&(X=max(X,f[t-1][i][j]+Get(t,i,j,x,y)));return X;
}
int main(){
//	freopen("a.in","r",stdin),freopen("a.out","w",stdout);
	RI i,j,x,y,t;W(1){
		if(read(n,d,m),!n&&!d&&!m) return 0;
		for(memset(g,0,sizeof(g)),i=1;i<=m;i++) read(x,y,t),x+=TT,y+=TT,g[t][x][y]=1;
		for(memset(f,0,sizeof(f)),Ans=0,t=1;t<=10;t++) for(i=0;i<n+TT*2;i++) for(j=0;j<n+TT*2;j++) Ans=max(Ans,(f[t][i][j]=dp(t,i,j)));
		writeln(Ans);
	}return 0;
}

