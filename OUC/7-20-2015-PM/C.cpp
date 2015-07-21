#include <cstdio>
#include <queue>
#define MAXN 222

struct S{
	int level, step;
	S():level(0),step(0){}
	S(int l, int s):level(l),step(s){}
};

int main(int argc, char const *argv[]){
	for(int n, a, b;~scanf("%d",&n)&&n!=0;){
		scanf("%d%d",&a,&b);
		int d[MAXN] = {0};
		for(int i=0; i<n; ++i){
			scanf("%d", d+i+1);
		}
		int ans = -1;
		bool v[MAXN] = {false};
		std::queue<S> q;
		for(;!q.empty();q.pop());
		q.push(S(a,0)); v[a] = true;
		while(!q.empty()){
			S cf = q.front(); q.pop();
			int l = cf.level, s = cf.step;
			if(l == b){
				ans = s;
				break;
			}
			if(l+d[l]>0 && l+d[l]<=n && !v[l+d[l]]){
				q.push(S(l+d[l],s+1));
				v[l+d[l]] = true;
			}
			if(l-d[l]>0 && l-d[l]<=n && !v[l-d[l]]){
				q.push(S(l-d[l],s+1));
				v[l-d[l]] = true;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}