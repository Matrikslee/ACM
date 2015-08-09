#include <stdio.h>
#include <string.h>

typedef long long LINT;

const int N = 1e6+100;

template<class T>
struct Tree{
	T c[2][N];
	int maxn;
	void init(int x){
		maxn = x+10; memset(c, 0, sizeof c);
	}
	inline int lowbit(int x){ return x&-x; }
	T sum(T *b, int x){
		T ans = 0;
		if (x == 0) ans = b[0];
		while (x) {
			ans += b[x];
			x -= lowbit(x);
		}
		return ans;
	}
	void change(T *b, int x, T value){
		if (x == 0)b[x] += value, x++;
		while (x <= maxn)b[x] += value, x += lowbit(x);
	}
	T get_pre(int r){
		return sum(c[0], r) * r + sum(c[1], r);
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
	for(int n,m,q; ~scanf("%d%d%d", &n, &m, &q); ){
		static LINT A[N];
		memset(A, 0x0, sizeof(A));
		for(int i=1; i<=n; ++i){
			scanf("%d", A+i);
			A[i] += A[i-1];
		}
		static Tree<LINT> s;
		s.init(n+1);
		for(int i=0; i<q; ++i){
			int x; scanf("%d", &x);
			int r = x+m-1, l = x;
			LINT ans = A[r]-A[l-1];
			ans += s.get(l,r);
			printf("%lld\n", ans);
			s.add(l,r,-1);
		}
	}
	return 0;
}