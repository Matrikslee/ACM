#include <cstdio>
#define max(a,b) ((a)>(b)?(a):(b))

const int tp = 23, te = 28, ti = 33, MAX = tp*te*ti;

int main(int argc, char const *argv[])
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	int p, e, i, d, cnt = 0;

	while(scanf("%d%d%d%d", &p, &e, &i, &d) && p!=-1 && e!=-1 && i!=-1){
		int des = d;
		while(p != e || e != i) {
			if(des<p || des<e || des<i)
				des = max(max(p, e), i);
			while(p<des && (p+=tp));
			while(e<des && (e+=te));
			while(i<des && (i+=ti));
		}
		printf("Case %d: the next triple peak occurs in %d days.\n", ++cnt, (p-d+MAX-1)%MAX+1);
	}
	return 0;
} 