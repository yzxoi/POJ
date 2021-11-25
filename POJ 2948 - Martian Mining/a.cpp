#include<cstdio>
#include<iostream>
#include<cstring>
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
Cn int N=510;
int n,m,a[N][N],s1[N][N],s2[N][N],f[N][N];
I int dp(CI n,CI m){
	if(n<1||m<1) return 0;
	if(~f[n][m]) return f[n][m];
	return f[n][m]=max(dp(n-1,m)+s1[n][m],dp(n,m-1)+s2[n][m]);
}
int main(){
	RI i,j;W(1){
		read(n,m);if(!n&&!m) return 0;
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) read(a[i][j]),s1[i][j]=s1[i][j-1]+a[i][j];
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) read(a[i][j]),s2[i][j]=s2[i-1][j]+a[i][j];
		memset(f,-1,sizeof(f)),writeln(dp(n,m));
	}return 0;
}

