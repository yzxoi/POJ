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
char s[1010];
int n,word,sentence,syllable;
I int isalpha(char c){
	if('A'<=c&&c<='Z') return 1;
	if('a'<=c&&c<='z') return 1;
	return 0;
}
I int isvowel(char c){
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y') return 1;
	if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y') return 1;
	return 0;
}
I int isword(char c){return c==',';};
I int issentence(char c){return c=='.'||c=='?'||c==':'||c==';'||c=='!';}
int main(){
	word=sentence=syllable=0;
	W(cin>>s){
		int len=0,syl=0,flg=0;
		for(int i=0;s[i];i++){
			if(isalpha(s[i])){
				len++;
				if(len<=3&&!isalpha(s[i+1])){syllable++,syllable-=syl,syl=0;continue ;} 
				if(isvowel(s[i])){
					if(s[i]=='e'){
						if(!isalpha(s[i+1])&&s[i-1]=='l'){syllable++,syl++;continue ;}
						else if(!isalpha(s[i+1])) continue ;
						else if((s[i+1]=='d'||s[i+1]=='s')&&!isalpha(s[i+2])) continue ;
					}
					if(!flg){flg=1,syllable++,syl++;continue ;}else continue ;
				}
				flg=0;
			}else if(isword(s[i])) flg=0,len=0,syl=0,word++;
			else if(issentence(s[i])) flg=0,len=0,word++,syl=0,sentence++;
		}
		if(isalpha(s[strlen(s)-1])) word++;
	}
	return printf("%.2f\n",206.835-1.015*(double)word/(double)sentence-84.6*(double)syllable/(double)word),0;
}
