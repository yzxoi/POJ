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
const int N=100010;
int n,m,from[N<<1],to[N<<1],w[N<<1],tot,dis[N];
I int Read_Char(){char c=gc();W(c!='P'&&c!='V') c=gc();return c=='V';}
I void add(int x,int y,int z){from[++tot]=x,to[tot]=y,w[tot]=z;}
int main(){
	W(cin>>n>>m){
		tot=0;for(int op,x,y,z,i=1;i<=m;i++) op=Read_Char(),op==0?(x=read(),y=read(),z=read(),add(x,y,z),add(y,x,-z),0):(x=read(),y=read(),add(x,y,1),0);
		bool flg=0;memset(dis,0,sizeof(dis));for(int i=1;i<=n;i++){
			flg=0;for(int j=1;j<=tot;j++)
				if(dis[to[j]]>dis[from[j]]-w[j]) dis[to[j]]=dis[from[j]]-w[j],flg=1;
			if(!flg) break ;
		}puts(flg?"Unreliable":"Reliable");
	}return 0;
}
