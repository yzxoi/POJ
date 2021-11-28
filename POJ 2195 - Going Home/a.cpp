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
int n,m,cnta,cntb,fir[N<<1],nxt[N*N<<4],son[N*N<<4],w[N*N<<4],cost[N*N<<4],tot,inf,vis[N<<1],dis[N<<1];
struct node{int x,y;}a[N*N],b[N*N];
struct Edge{int id,son;}pre[N<<1]; 
char s[N][N];
I int dist(int i,int j){return abs(a[i].x-b[j].x)+abs(a[i].y-b[j].y);}
I void add(int x,int y,int z,int c){nxt[++tot]=fir[x],fir[x]=tot,son[tot]=y,w[tot]=z,cost[tot]=c;}
queue<int> q;
#define to son[i]
I int bfs(){
	W(!q.empty()) q.pop();memset(vis,0,sizeof(vis)),memset(dis,63,sizeof(dis)),inf=dis[0],vis[0]=1,dis[0]=0,q.push(0);W(!q.empty()){
		int u=q.front();q.pop();
		for(int i=fir[u];i;i=nxt[i])
			if(w[i]>0&&dis[to]>dis[u]+cost[i]) dis[to]=dis[u]+cost[i],pre[to]=(Edge){i,u},!vis[to]&&(q.push(to),vis[to]=1);
		vis[u]=0;
	}
	return dis[cnta+cntb+1]^inf;
}
I int EK(){
	int Ans=0;W(bfs()){
		int Min=inf;for(int i=cnta+cntb+1;i;i=pre[i].son) Min=min(Min,w[pre[i].id]);
		for(int i=cnta+cntb+1;i;i=pre[i].son) w[pre[i].id]-=Min,w[pre[i].id^1]+=Min;
		Ans+=Min*dis[cnta+cntb+1];
	}return Ans;
}
I char Read_Char(){char c=gc();W(c!='m'&&c!='.'&&c!='H') c=gc();return c;}
int main(){
	W(n=read(),m=read()){
		cnta=cntb=0;for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) s[i][j]=Read_Char(),s[i][j]=='m'&&(a[++cnta]=(node){i,j},0),s[i][j]=='H'&&(b[++cntb]=(node){i,j},0);
		memset(fir,0,sizeof(fir)),tot=1;for(int i=1;i<=cnta;i++)
			for(int j=1;j<=cntb;j++) add(i,j+cnta,1,dist(i,j)),add(j+cnta,i,0,-dist(i,j));
		for(int i=1;i<=cnta;i++) add(0,i,1,0),add(i,0,0,0);
		for(int i=1;i<=cntb;i++) add(i+cnta,cnta+cntb+1,1,0),add(cnta+cntb+1,i+cnta,0,0);
		write(EK()),pc('\n'); 
	}return 0;
}
