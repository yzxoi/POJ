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
const int N=110;
int n,m,K,a[N][N],b[N][N],fir[N<<1],nxt[N*N<<4],son[N*N<<4],w[N*N<<4],cost[N*N<<4],pt[N*N<<4],tot,inf,vis[N<<1],dis[N<<1];
struct Edge{int id,son;}pre[N<<1];
I void add(int x,int y,int z,int c,int id){nxt[++tot]=fir[x],fir[x]=tot,son[tot]=y,w[tot]=z,cost[tot]=c,pt[tot]=id;}
queue<int> q;
#define to son[i]
I int bfs(int x){
	W(!q.empty()) q.pop();memset(vis,0,sizeof(vis)),memset(dis,63,sizeof(dis)),inf=dis[0];vis[0]=1,dis[0]=0,q.push(0);W(!q.empty()){
		int u=q.front();q.pop();
		for(int i=fir[u];i;i=nxt[i])
			if(pt[i]==x&&w[i]>0&&dis[to]>dis[u]+cost[i]) dis[to]=dis[u]+cost[i],pre[to]=(Edge){i,u},!vis[to]&&(q.push(to),vis[to]=1);
		vis[u]=0;
	}return dis[n+m+1]^inf;
}
I int EK(){
	int Ans=0;for(int i=1;i<=K;i++){
		for(int j=1;j<=n;j++) add(0,j,a[j][i],0,i),add(j,0,0,0,i);
		for(int j=1;j<=m;j++) add(n+j,n+m+1,b[j][i],0,i),add(n+m+1,n+j,0,0,i);
		W(bfs(i)){
			int Min=inf;for(int j=n+m+1;j;j=pre[j].son) Min=min(Min,w[pre[j].id]);
			for(int j=n+m+1;j;j=pre[j].son) w[pre[j].id]-=Min,w[pre[j].id^1]+=Min;
			Ans+=Min*dis[n+m+1];
		}
	}return Ans;
}
int main(){
	W(n=read(),m=read(),K=read()){
		if(!n&&!m&&!K) return 0;
		memset(a,0,sizeof(a)),memset(b,0,sizeof(b)),memset(fir,0,sizeof(fir));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=K;j++) a[0][j]+=a[i][j]=read();
		for(int i=1;i<=m;i++)
			for(int j=1;j<=K;j++) b[0][j]+=b[i][j]=read();
		tot=1;for(int i=1;i<=K;i++)
			for(int j=1;j<=n;j++)
				for(int z,k=1;k<=m;k++) z=read(),add(j,k+n,min(a[j][i],b[k][i]),z,i),add(k+n,j,0,-z,i);
		int flg=0;for(int i=1;i<=K;i++)
			if(b[0][i]<a[0][i]) flg=1;
		if(flg) puts("-1");
		else write(EK()),pc('\n');
	}return 0;
}
