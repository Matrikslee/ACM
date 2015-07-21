#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LINT;

#define MAXN 555555
#define lowbit(o) ({int _=o; _&(~_+1);})

struct node {
	int value;
	int id;
};

bool cmp(node a, node b){return a.value>b.value;}
void add(LINT *bint, int pos, int lmt);
LINT sum(LINT *bint, int pos, int lmt);

int main(int argc, char const *argv[])
{
	for(int n; ~scanf("%d", &n) && n!=0; ){
		static node hash[MAXN];
		for(node *p=hash; p-hash<n; ++p){
			p->id = p-hash+1;
			scanf("%d", &p->value);
		}
		LINT ans = 0;
		static LINT bint[MAXN];
		std :: sort(hash, hash+n, cmp);
		memset(bint, 0x0, sizeof(bint));
		for(node *p=hash; p-hash<n; ++p){
			ans += sum(bint, p->id-1, n+1);
			add(bint, p->id, n+1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

LINT sum(LINT *bint, int pos, int lmt){
	LINT ans = 0;
	while(pos>0 && pos<lmt){
		ans += bint[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

void add(LINT *bint, int pos, int lmt){
	while(pos>0 && pos<lmt){
		++bint[pos];
		pos+=lowbit(pos);
	}
}