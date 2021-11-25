#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<iostream>
#include<queue>
#include<stack>
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
const int N=1010,M=1000010;
int n,m,a[N][N],dfn[M],low[M],pt[M],color[M],in[M],ans[M],cnt=0,fir[N],nxt[N*N<<1],son[N*N<<1],tot;
I void add(int x,int y){nxt[++tot]=fir[x],fir[x]=tot,son[tot]=y;}
#define to son[i]
I bool check(int x,int c){
	color[x]=c;for(int i=fir[x];i;i=nxt[i]) if(in[to]){
		if(!color[to]&&!check(to,c^1)) return 0;
		else if(color[to]==color[x]) return 0;
	}return 1;
}
stack<int> s;
I void tarjan(int x,int fa){
	dfn[x]=low[x]=++cnt;s.push(x);for(int i=fir[x];i;i=nxt[i]) if(to^fa){
		if(!dfn[to]){
			tarjan(to,x);
			low[x]=min(low[x],low[to]);
			if(low[to]>=dfn[x]){
				memset(in,0,sizeof(in));
				memset(color,0,sizeof(color));
				int u,cnt=0;
				do{
					u=s.top();s.pop();
					in[u]=1,pt[++cnt]=u;
				}while(u!=to);
				if(cnt<=1) continue ;
				in[x]=1,pt[++cnt]=x;
				if(!check(x,1))
					for(int j=1;j<=cnt;j++) ans[pt[j]]=1;
			}
		}
		low[x]=min(low[x],dfn[to]);
	}
}
int main(){
	W(n=read(),m=read()){
		if(!n&&!m) return 0;
		memset(dfn,0,sizeof(dfn)),memset(ans,0,sizeof(ans)),memset(low,0,sizeof(low)),memset(a,0,sizeof(a));
		for(int x,y,i=1;i<=m;i++) x=read(),y=read(),a[x][y]=a[y][x]=1;
		tot=1;memset(fir,0,sizeof(fir));for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i^j&&!a[i][j]) add(i,j);
		for(int i=1;i<=n;i++)
			if(!dfn[i]) tarjan(i,0);
		int Ans=0;for(int i=1;i<=n;i++)
			if(!ans[i]) Ans++;
		write(Ans),pc('\n');
	}return 0;
}
