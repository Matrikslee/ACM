#include <stdio.h>
#include <string.h>
#define MAXN 111111

template<class T>
class Tree{
	T c[2][MAXN];
	const int maxn;
	inline int lowbit(int x){ return x&-x; }
	T sum(T *b, int x){
		T ans; 
		for(ans=x?0:b[0]; x!=0; ans += b[x], x-=lowbit(x));
		return ans;
	}
	void change(T *b, int x, T value){
		for ( x==0?b[x++]+=value:0 ; x<=maxn; b[x] += value, x += lowbit(x));
	}
	T get_pre(int r){
		return r*sum(c[0],r)+sum(c[1],r);
	}
public:
	Tree(int n) : maxn(n+10) {
		memset(c, 0, sizeof c);
	}
	void add(int l, int r, T value){
		change(c[0], l, value);
		change(c[0], r + 1, -value);
		change(c[1], l, value * (-l + 1));
		change(c[1], r + 1, value * r);
	}
	T get(int l, int r){
		return get_pre(r) - get_pre(l - 1);
	}
};

int main(int argc, char const *argv[]){
	int n,q; scanf("%d%d", &n, &q);
	static long long sum[MAXN];
	for(int i=1; i<=n; ++i){
		scanf("%lld", sum+i);
		sum[i] += sum[i-1];
	}
	char c;
	static Tree<long long> S(n);
	for(int i=0; i<q; ++i){
		for( c=getchar();c!='Q' && c!='C'; c=getchar());
		if( c=='Q' ) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", sum[r]-sum[l-1]+S.get(l,r));
		}
		if( c=='C' ) {
			int l, r, c;
			scanf("%d%d%d",&l, &r, &c);
			S.add(l,r,c);
		}
	}
	return 0;
}