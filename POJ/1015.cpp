#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 222

int main(int argc, char const *argv[])
{
	int m, n, cnt=0, p[MAX_N], d[MAX_N];
	int ans[MAX_N][MAX_N*4], path[MAX_N][MAX_N*4];
	while(scanf("%d%d", &n, &m) && n && m){
		//preprocessing and get input
		memset(ans,-1,sizeof(ans));
		memset(path,-1,sizeof(path));
		int zero=m*20; ans[0][zero]=0;
		for(int i=0; i<n; ++i){ scanf("%d%d", p+i, d+i); }

		// dynamic programming
		for(int i=1; i<=m; ++i){
			for(int j=0; j<=zero*2; ++j){
				if(ans[i-1][j]==-1) { continue; }
				for(int k=0; k<n; ++k){
					int nums=i-1, value=j, flag=false;
					while(nums>0){ 
						int prev=path[nums][value];
						--nums && (value-=p[prev]-d[prev]);
						if(prev==k) { flag=true; break; }
					}
					if(flag) { continue; }
					if(ans[i-1][j]+d[k]+p[k]>ans[i][j+p[k]-d[k]]){
						ans[i][j+p[k]-d[k]]=ans[i-1][j]+d[k]+p[k];
						path[i][j+p[k]-d[k]]=k;
					}
				}
			}
		}

		//output the answer
		int i=zero, j=0, k=zero, err, answer[MAX_N];
		while(ans[m][i+j]<0 && ans[m][i-j]<0 && ++j);
		err=(k=ans[m][i+j]>ans[m][i-j]?i+j:i-j)-zero;
		printf("Jury #%d\n",++cnt);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",(err+ans[m][k])/2,(ans[m][k]-err)/2);
		for(int i=0; i<m; ++i){
			answer[i]=path[m-i][k];
			k-=p[answer[i]]-d[answer[i]];
		}
		std::sort(answer,answer+m);
		for(int i=0; i<m; printf(" %d", answer[i++]+1));
		printf("\n\n");
	}
	return 0;
}