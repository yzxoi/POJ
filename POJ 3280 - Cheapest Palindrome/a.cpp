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

