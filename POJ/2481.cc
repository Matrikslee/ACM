#include <cstdio>
#include <cstring>
#include <algorithm>

#define max(a,b) ({int _=(a), __=(b); _>__?_:__;})
#define lowbit(o) ({int _=o; _&(~_+1);})
#define MAXN 111111
typedef long long LINT;

class simple{
private:
	int  limit;
	LINT C[MAXN];
public:
	simple(){simple(0);}
	simple(int lmt):limit(lmt+1){ memset(C, 0x0, sizeof(C)); }
	~simple(){}
	void add(int pos, int value){
		while(pos>0 && pos<limit){
			C[pos] += value;
			pos += lowbit(pos);
		}
	}
	LINT sum(int pos){
		LINT ans=0;
		while(pos>0 && pos<limit){
			ans += C[pos];
			pos -= lowbit(pos);
		}
		return ans;
	}
};

struct cow {
	int s;
	int e;
	int id;
};

int cmp_e(cow a, cow b){ return a.e>b.e||a.e==b.e&&a.s<b.s; }
int cmp_id(cow a, cow b){ return a.id<b.id; }

int main(int argc, char const *argv[])
{
	for(int n;~scanf("%d", &n) && n!=0; ){
		int maxlen = 0;
		static cow N[MAXN];
		for(cow *p=N; (p->id=p-N)<n; ++p){
			scanf("%d%d", &p->s, &p->e);
			++p->s, ++p->e;
			maxlen = max(maxlen, p->e);
		}
		simple s(maxlen);
		static int ans[MAXN];
		std :: sort(N, N+n, cmp_e);
		for(int i=0; i<n; ++i){
			if(i>0&&N[i].s==N[i-1].s&&N[i].e==N[i-1].e){
				ans[N[i].id] = ans[N[i-1].id];
			} else {
				ans[N[i].id] = s.sum(N[i].s);
			}
			s.add(N[i].s, 1);
		}
		for(int i=0; i<n; ++i){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}