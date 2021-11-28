#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<iostream>
#include<map>
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
const int N=85;
string a;
map<pair<char,char>,int> mp;
int main(){
	register int len,i,j,flg;
	W(cin>>a,a!="*"){
		cout<<a<<" is ";flg=0;
		len=a.length();for(i=1;!flg&&i<len;i++) 
		for(mp.clear(),j=0;j+i<len;j++) if(mp[make_pair(a[j],a[j+i])]){flg=1;break ;}else mp[make_pair(a[j],a[j+i])]=1;
		if(flg) printf("NOT ");
		puts("surprising.");
	}return 0;
}