#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
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
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
namespace FastIO{
	Tp I void read(Ty& x){char c;int f=1;x=0;W(!D) f=c^'-'?1:-1;W(x=(x<<3)+(x<<1)+(c&15),D);x*=f;}
	Tp I void write(Ty x){x<0&&(pc('-'),x=-x,0),x<10?(pc(x+'0'),0):(write(x/10),pc(x%10+'0'),0);}
	Tp I void writeln(Cn Ty& x){write(x),pc('\n');}
}using namespace FastIO;
Cn int N=55,M=2010,P=110;
#define eps 1e-8
int Tt,n,m,l,a[N][N],fir[P],nxt[M],son[M],tot=1,dis[P],cur[P],inf=1e2,cnt,S,T;double w[M];
I void Add(CI x,CI y,double z){nxt[++tot]=fir[x],fir[x]=tot,son[tot]=y,w[tot]=z;nxt[++tot]=fir[y],fir[y]=tot,son[tot]=x,w[tot]=0;}
queue<int> q;
#define to son[i]
I bool bfs(){
	W(!q.empty()) q.pop();memset(dis,-1,sizeof(dis)),dis[S]=0,q.push(S);W(!q.empty()){
		RI u=q.front(),i;q.pop();for(i=fir[u];i;i=nxt[i]) w[i]>eps&&dis[to]==-1&&(dis[to]=dis[u]+1,q.push(to),0);
	}return ~dis[T];
}
I double dfs(CI x,double flow){
	if(x==T) return flow;
	double now=flow,d;for(RI i=cur[x];i;i=nxt[i]) if(cur[x]=nxt[i],w[i]>eps&&dis[to]==dis[x]+1){
		d=dfs(to,min(now,w[i])),w[i]-=d,w[i^1]+=d,now-=d;if(now<eps) break ;
	}return flow-now;
}
I double Dinic(){
	double Ans=0.0;RI i;W(bfs()){
		for(i=S;i<=T;i++) cur[i]=fir[i];
		Ans+=dfs(S,inf);
	}return Ans;
}
int main(){
//	freopen("test","r",stdin),freopen("a.out","w",stdout);
	RI i,x,y;read(Tt);W(Tt--){
		double t;for(memset(fir,0,sizeof(fir)),tot=1,read(n),read(m),read(l),T=n+m+1,i=1;i<=n;i++) scanf("%lf",&t),Add(S,i,log(t));
		for(i=1;i<=m;i++) scanf("%lf",&t),Add(i+n,T,log(t));for(i=1;i<=l;i++) read(x),read(y),Add(x,y+n,inf);
		printf("%.4f\n",exp(Dinic()));
	}return 0;
}

