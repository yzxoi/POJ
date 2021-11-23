# POJ 1191 - 棋盘分割

将一个 $8\times8$ 的棋盘进行如下分割：将原棋盘割下一块矩形棋盘并使剩下部分也是矩形，再将剩下的部分继续如此分割，这样割了 $(n-1)$ 次后，连同最后剩下的矩形棋盘共有 $n$ 块矩形棋盘。(每次切割都只能沿着棋盘格子的边进行)

![1191_1](https://gitee.com/yzx1798106406/picgoimage/raw/master/pic/1191_1.jpg)

原棋盘上每一格有一个分值，一块矩形棋盘的总分为其所含各格分值之和。现在需要把棋盘按上述规则分割成n块矩形棋盘，并使各矩形棋盘总分的均方差最小。
均方差 $\sigma = \sqrt \frac{\sum_{i=1}^n(x_i-\bar x)^2}n$，其中 $\bar x=\frac{\sum_{i=1}^n x_i}n$ 平均值，$x_i$ 为第 $i$ 块矩形棋盘的总分。

请编程对给出的棋盘及 $n$，求出 $\sigma$ 的最小值。

### Sol

设 $f[k][x1][y1][x2][y2]$ 表示当前划分成 $k$ 个区域，现目前正在做的是以 $(x1,y1)$ 为左上角，$(x2,y2)$ 为右下角的矩形 的最小值。

显然可以通过一次操作转移：
$$
\begin{align}
f[k][x1][y1][x2][y2]\rightarrow f[k+1][x1][y1][i][y2]\\
\rightarrow f[k+1][i][y1][x2][y2]\\
\rightarrow f[k+1][x1][i][x2][y2]\\
\rightarrow f[k+1][x1][y1][x2][i]\\
\end{align}
$$
时间复杂度 $O(8^4n)$。

```c++
#include<bits/stdc++.h>
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
namespace Debug{
	Tp I void _debug(Cn char* f,Ty t){cerr<<f<<'='<<t<<endl;}
	Ts I void _debug(Cn char* f,Ty x,Ar... y){W(*f!=',') cerr<<*f++;cerr<<'='<<x<<",";_debug(f+1,y...);}
	Tp ostream& operator<<(ostream& os,Cn vector<Ty>& V){os<<"[";for(Cn auto& vv:V) os<<vv<<",";os<<"]";return os;}
	#define gdb(...) _debug(#__VA_ARGS__,__VA_ARGS__)
}using namespace Debug;
namespace FastIO{
	Tp I void read(Ty& x){char c;int f=1;x=0;W(!D) f=c^'-'?1:-1;W(x=(x<<3)+(x<<1)+(c&15),D);x*=f;}
	Ts I void read(Ty& x,Ar&... y){read(x),read(y...);}
	Tp I void write(Ty x){x<0&&(pc('-'),x=-x,0),x<10?(pc(x+'0'),0):(write(x/10),pc(x%10+'0'),0);}
	Tp I void writeln(Cn Ty& x){write(x),pc('\n');}
}using namespace FastIO;
Cn int N=10,M=16;
int n,a[N][N],s[N][N];
double f[M][N][N][N][N],X,inf=2e9;
I double Sqr(double x){return x*x;}
#define S(x1,y1,x2,y2) (s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1])
I double Get(CI x1,CI y1,CI x2,CI y2){return Sqr(S(x1,y1,x2,y2)-X);} 
I double dp(CI k,CI x1,CI y1,CI x2,CI y2){
	if(k==n) return Get(x1,y1,x2,y2);
	if(-inf!=f[k][x1][y1][x2][y2]) return f[k][x1][y1][x2][y2];
	RI i;for(f[k][x1][y1][x2][y2]=inf,i=x1;i<x2;i++) f[k][x1][y1][x2][y2]=min(f[k][x1][y1][x2][y2],Get(x1,y1,i,y2)+dp(k+1,i+1,y1,x2,y2));
	for(i=x1;i<x2;i++) f[k][x1][y1][x2][y2]=min(f[k][x1][y1][x2][y2],dp(k+1,x1,y1,i,y2)+Get(i+1,y1,x2,y2));
	for(i=y1;i<y2;i++) f[k][x1][y1][x2][y2]=min(f[k][x1][y1][x2][y2],Get(x1,y1,x2,i)+dp(k+1,x1,i+1,x2,y2));
	for(i=y1;i<y2;i++) f[k][x1][y1][x2][y2]=min(f[k][x1][y1][x2][y2],dp(k+1,x1,y1,x2,i)+Get(x1,i+1,x2,y2));
	return f[k][x1][y1][x2][y2];
}
int main(){
	RI i,j,k,l,t;for(read(n),i=1;i<=8;i++) for(j=1;j<=8;j++) read(a[i][j]),s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j],X+=a[i][j];
	for(t=1;t<=n;t++) for(i=1;i<=8;i++) for(j=1;j<=8;j++) for(k=1;k<=8;k++) for(l=1;l<=8;l++) f[t][i][j][k][l]=-inf;
	return X/=n,printf("%.3lf\n",sqrt(dp(1,1,1,8,8)/n)),0;
}
```

