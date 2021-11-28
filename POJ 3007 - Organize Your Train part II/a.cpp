#pragma GCC optimize (2)
#pragma G++ optimize (2)
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string> 
#include<cstring>
#include<map>
#include<set>
#define W while
#define I inline
#define gc getchar
#define D isdigit(c=gc())
#define Cn const
#define pc(c) putchar((c))
#define ull unsigned long long
using namespace std;
I int read(){int x=0,f=1;char c;W(!D) f=c^'-'?1:-1;W(x=(x<<3)+(x<<1)+(c&15),D);return x*f;}
I void write(int x){x<0&&(pc('-'),x=-x),x<10?(pc(x+'0'),0):(write(x/10),pc(x%10+'0'),0);}
const int N=80,TT=1145140;
int T,sz,Ans,cnt;
//struct Pair{
//	ull a,b;
//	Pair(int a=0,int b=0):a(a),b(b){}
//	I Pair operator+(Pair o){return Pair(a+o.a,b+o.b);}
//	I void operator+=(Pair o){a+=o.a,b+=o.b;}
//	I Pair operator*(Pair o){return Pair(a*o.a,b*o.b);}
//	I void operator*=(Pair o){a*=o.a,b*=o.b;}
//	I void operator%=(Pair o){a%=o.a,b%=o.b;}
//	I bool operator==(const Pair& o)const{return a==o.a&&b==o.b;}
//	I bool operator<(const Pair& o)const{return a<o.a&&b<o.b;}
//	I void output(){pc('('),write(a),pc(','),write(b),pc(')');}
//};
//const Pair base=Pair(29,26),mod=Pair(19260817,23333333);
//Pair v[10000000];
//set<Pair> S;
char a[N],pre[N],nxt[N],R_pre[N],R_nxt[N];
class Trie{
	private:
		int tr[50010][27],vis[50010],t;
	public:
		inline void clean(){memset(tr,0,sizeof(tr));memset(vis,0,sizeof(vis));t=0;}
		inline void insert(char s1[],char s2[]){
			int p=0,c,sz1=strlen(s1),sz2=strlen(s2);
			for(int i=0;i<sz1;i++){
				c=s1[i]-'a';
				if(!tr[p][c]) tr[p][c]=++t;
				p=tr[p][c];
			}
			for(int i=0;i<sz2;i++){
				c=s2[i]-'a';
				if(!tr[p][c]) tr[p][c]=++t;
				p=tr[p][c];
			}
			if(!vis[p]) Ans++;
			vis[p]=1;
		}
}tr;
I void Add(char s1[],char s2[]){
	tr.insert(s1,s2);
//	register int sz1=strlen(s1),sz2=strlen(s2);
//	Pair s=Pair(0,0);
//	for(int i=0;i<sz1;i++) s=s*base+Pair(s1[i]-'a',s1[i]-'a'),s%=mod;
//	for(int i=0;i<sz2;i++) s=s*base+Pair(s2[i]-'a',s2[i]-'a'),s%=mod;
//	S.insert(s);
//	v[++cnt]=s;
//	if(!mp[s]) Ans++,mp[s]=1;
}
int main(){
	T=read();W(T--){
		cnt=Ans=0;cin>>a,sz=strlen(a);tr.clean();
//		S.clear();
		for(int i=1;i<sz;i++){
			memset(pre,0,sizeof(pre));
			memset(nxt,0,sizeof(nxt));
			memset(R_pre,0,sizeof(R_pre));
			memset(R_nxt,0,sizeof(R_nxt));
			for(int j=0;j<i;j++) R_pre[i-j-1]=pre[j]=a[j];
			for(int j=i;j<sz;j++) R_nxt[sz-j-1]=nxt[j-i]=a[j];
			Add(pre,nxt),Add(nxt,pre),Add(R_pre,nxt),Add(nxt,R_pre),Add(R_nxt,pre),Add(pre,R_nxt),Add(R_pre,R_nxt),Add(R_nxt,R_pre);
		}
		write(Ans),pc('\n');
//		sort(v+1,v+cnt+1);Ans=unique(v+1,v+cnt+1)-v-1;
//		write(S.size()),pc('\n');
	}return 0;
}
