#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define W while
#define I inline
#define RI register int
#define int long long
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
Cn int N=5010,M=1e6+10;
int Tt,n,f[M],Ans;
#define PA pair<int,int>
#define MP make_pair
#define fi first
#define se second
PA a[N];
signed main(){
	#define GT(i,j) (sqrt(0.0+a[j].se*a[j].se-(a[i].se-a[j].se)*(a[i].se-a[j].se)))
	RI i,j,t,r;read(Tt);W(Tt--){
		for(memset(f,63,sizeof(f)),read(n),i=1;i<=n;i++) read(a[i].fi,a[i].se);
		for(f[a[1].fi]=0,Ans=2e9,i=2;i<=n;i++) for(r=GT(1,i),j=max(a[i].fi-r,a[1].fi);j<a[i].fi;j++) if((t=2*a[i].fi-j)<a[n].fi) f[t]=min(f[t],f[j]+1);else Ans=min(Ans,f[j]+1);
		writeln(Ans>n?-1:Ans);
	}return 0;
}

