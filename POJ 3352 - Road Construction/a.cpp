#include<cstdio>
#include<iostream>
#include<vector>
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
Cn int N=1010;
int n,m,dfn[N],low[N],cnt,stk[N],top,col[N],cc,Ans,sum,vis[N];
vector<int> G[N],v[N];
#define pb push_back
I void Tarjan(CI x,CI fa){
	stk[++top]=x,dfn[x]=low[x]=++cnt;for(RI i,j=0;j<G[x].size();j++) i=G[x][j],i^fa&&(!dfn[i]?Tarjan(i,x),low[x]=min(low[x],low[i]):!col[i]&&(low[x]=min(low[x],dfn[i])));
	if(dfn[x]==low[x]){col[x]=++cc;W(stk[top]^x) col[stk[top--]]=cc;top--;}
}
I void dfs(CI x,CI fa){
	if(v[x].size()==1) ++sum;
	vis[x]=1;RI flg=0;for(RI i,j=0;j<v[x].size();j++) i=v[x][j],i^fa&&(flg=1,dfs(i,x),0);
}
int main(){
	RI i,x,y;for(read(n,m),i=1;i<=m;i++) read(x,y),G[x].pb(y),G[y].pb(x);
	for(i=1;i<=n;i++) !dfn[i]&&(Tarjan(i,0),0);
	for(i=1;i<=n;i++) for(RI j,t=0;t<G[i].size();t++) j=G[i][t],col[i]^col[j]&&(v[col[i]].pb(col[j]),0);
	for(i=1;i<=cc;i++) !vis[i]&&(sum=0,dfs(i,0),Ans+=(sum+1)/2);
	return writeln(Ans),0;
}

