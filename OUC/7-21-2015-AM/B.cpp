#include <cstdio>
#include <cmath>

const int INF=1<<30;

int ans = INF;

// cd还需要做的层数,cr当前层半径,ch当前层高度
// cv还需要做的体积,s已经做好的面积
void dfs(int cv, int cd, int cr, int ch, int s){
	if(cd==0 && cv==0){
		s<ans?ans=s:0;
	}
	if( cd>0 && cv>0 && s<ans){
		for(int r=cr-1; r>=cd; --r){
			for(int h=ch-1; h>=cd; --h){
				dfs(cv-r*r*h,cd-1,r,h,s+2*r*h);
			}
		}
	}
	// printf("goback!!\n");
}

int main(int argc, char const *argv[]){
	int n,m;
	scanf("%d%d",&n, &m);
	dfs(n,m,sqrt(n)+1,n+1,0);
	printf("%d\n", ans==INF?0:ans);
	return 0;
}
