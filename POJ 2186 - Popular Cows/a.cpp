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
const int N=10010,M=50010;
int n,m,fir[N],nxt[M],son[M],tot,fir2[N],nxt2[M],son2[M],tot2,vis[N],d[N],t,s[N],g[N],Ans,Ansp;
struct Edge{int x,y;}a[M];
I void add(int x,int y){nxt[++tot]=fir[x],fir[x]=tot,son[tot]=y;}
I void add2(int x,int y){nxt2[++tot2]=fir2[x],fir2[x]=tot2,son2[tot2]=y;}
void dfs_1(int x){
    vis[x]=1;for(int i=fir[x];i;i=nxt[i])
        if(vis[son[i]]==0) dfs_1(son[i]);
    d[++t]=x;
}
void dfs_2(int x){
    vis[x]=t;s[t]++;for(int i=fir2[x];i;i=nxt2[i])
        if(vis[son2[i]]==0) dfs_2(son2[i]);
}
void Kosaraju(){
    t=0;memset(vis,0,sizeof(vis));for(int i=1;i<=n;i++) if(vis[i]==0) dfs_1(i);
    memset(vis,0,sizeof(vis));t=0;for(int i=n;i>=1;i--) if(vis[d[i]]==0) t++,dfs_2(d[i]);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),add(a[i].x,a[i].y),add2(a[i].y,a[i].x);
	Kosaraju();for(int i=1;i<=m;i++)
		if(vis[a[i].x]^vis[a[i].y]) g[vis[a[i].x]]++;
	for(int i=1;i<=t;i++)
		if(!g[i]) Ans=s[i],Ansp++;
	if(Ansp>1) return puts("0"),0;
	return write(Ans),pc('\n'),0;
}
