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
const int N=50010;
int n,a[N],b[N],c[N],Mn=2e9,Mx=0,fir[N],nxt[N*3],son[N*3],w[N*3],tot,vis[N],dis[N];
I void add(int x,int y,int z){nxt[++tot]=fir[x],fir[x]=tot,son[tot]=y,w[tot]=z;}
queue<int> q;
#define to son[i]
I void spfa(int x){
	W(!q.empty()) q.pop();
	q.push(x);memset(vis,0,sizeof(vis));
	for(int i=Mn;i<=Mx;i++) dis[i]=-1e9;
	dis[x]=0;vis[x]=1;
	W(!q.empty()){
		int u=q.front();q.pop();
		for(int i=fir[u];i;i=nxt[i])
			if(dis[to]<dis[u]+w[i]) dis[to]=dis[u]+w[i],!vis[to]&&(q.push(to),vis[to]=1);
		vis[u]=0;
	}
}
int main(){
	n=read();for(int i=1;i<=n;i++) a[i]=read(),b[i]=read(),c[i]=read(),Mn=min(Mn,a[i]-1),Mx=max(Mx,b[i]),add(a[i]-1,b[i],c[i]);
	for(int i=Mn;i<=Mx;i++) add(i,i-1,-1),add(i-1,i,0);
	return spfa(Mn),write(dis[Mx]),0;
}
