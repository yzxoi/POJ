# POJ 3280 - Cheapest Palindrome

给定一个长度为 $m$ 的字符串 $s$，其中 $s_i\in['a','a'+n-1]$。

再给定 $\forall i \in ['a','a'+n-1]$ 的添加、删除的权值。

问使 $s$ 变成回文串的最小代价。

$m\leq 2000,n\leq 26$。

### Sol

显然添加与删除操作是等价的，因此操作权值取较小值即可。

设 $f[l][r]$ 表示 $s$ 的子串 $[l,r]$ 变成回文串的最小代价，显然转移有：
$$
\begin{align}
f[l][r]& \leftarrow f[l+1][r]\\
& \leftarrow f[l][r-1]\\
& \leftarrow f[l+1][r-1]\\
\end{align}
$$

```c++
#include<cstdio>
#include<cmath>
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
	I void read(char& c){c=gc();W(!('a'<=c&&c<='z')) c=gc();}
	Tp I void read(Ty& x){char c;int f=1;x=0;W(!D) f=c^'-'?1:-1;W(x=(x<<3)+(x<<1)+(c&15),D);x*=f;}
	Ts I void read(Ty& x,Ar&... y){read(x),read(y...);}
	Tp I void write(Ty x){x<0&&(pc('-'),x=-x,0),x<10?(pc(x+'0'),0):(write(x/10),pc(x%10+'0'),0);}
	Tp I void writeln(Cn Ty& x){write(x),pc('\n');}
}using namespace FastIO;
Cn int N=2010,V=27;
int n,m,co[V],f[N][N];
char a[N];
int main(){
	RI i,j,k,x,y;char o;for(read(n,m),scanf("%s",a+1),i=1;i<=n;i++) read(o,x,y),co[o-'a']=min(x,y);
	for(k=1;k<=m;k++) for(i=1;(j=i+k-1)<=m;i++) f[i][j]=min(f[i+1][j]+co[a[i]-'a'],f[i][j-1]+co[a[j]-'a']),a[i]==a[j]&&(f[i][j]=min(f[i][j],f[i+1][j-1]));
	return writeln(f[1][m]),0;
}
```

