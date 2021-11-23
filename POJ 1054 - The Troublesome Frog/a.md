# POJ 1054 - The Troublesome Frog

直接暴力枚举 $n^2$ 对点，每两个点直接 check 即可。

注意直接这样做可能会 T，所以可以加一点小剪枝就过了。

```c++
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
const int N=5010;
int n,m,q,x[N],y[N],p[N][N],Ans;
I void check(int i,int j){
	int dx=x[j]-x[i],dy=y[j]-y[i];if(x[i]-dx>=1&&x[i]-dx<=n&&y[i]-dy>=1&&y[i]-dy<=m) return ;
	if(!(x[i]+dx*Ans>=1&&x[i]+dx*Ans<=n&&y[i]+dy*Ans>=1&&y[i]+dy*Ans<=m&&p[x[i]+dx*Ans][y[i]+dy*Ans])) return ;
	int k=0;W(x[i]+dx*k>=1&&x[i]+dx*k<=n&&y[i]+dy*k>=1&&y[i]+dy*k<=m&&p[x[i]+dx*k][y[i]+dy*k]) k++;
	if(x[i]+dx*k>=1&&x[i]+dx*k<=n&&y[i]+dy*k>=1&&y[i]+dy*k<=m) return ;
	Ans=max(Ans,k);return ;
}
int main(){
	W(cin>>n){
		m=read(),q=read();Ans=0;memset(p,0,sizeof(p));
		for(int i=1;i<=q;i++) p[x[i]=read()][y[i]=read()]++;
		for(int i=1;i<=q;i++) for(int j=1;j<=q;j++) if(i^j) check(i,j);
		write(Ans>=3?Ans:0),pc('\n');
	}return 0;
}
```

