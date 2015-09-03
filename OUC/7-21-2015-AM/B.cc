#include <cstdio>
#include <cmath>

const int INF=1<<30;

int n, m, ans = INF;

inline int min(int a, int b){return a<b?a:b;}

// d还需要做的层数,maxR当前层最大半径,maxH当前层最大高度
// v还需要做的体积,s已经做好的面积,
void dfs(int v, int d, int maxR, int maxH, int s){
	// printf("S==%d v==%d d==%d maxR==%d maxH==%d ans==%d\n", s, v,d,maxR,maxH,ans);
	//最后一层特判
	if(d==1&&v>0&&v<=maxR*maxR*maxH){
		for(int r=maxR; r>0; --r){
			if(v%(r*r)==0&&v/(r*r)<=maxH){
				ans=min(s+2*v/r,ans);				
			}
		}
	}
	// s+2*v/maxR<ans 最优性剪枝,如果不考虑可行性的最优的状态都比当前已获得的可行解大,也没必要往下搜索了
	if(d>1 && v>0 && s+2*v/maxR<ans){
		for(int r=maxR; r>=d; --r){
			// 求当前层当前r可以达到的最大高度, 其实剪掉了很多无用的状态
			int tmpH = min(v/(r*r)+1,maxH);
			// 可行性剪枝----如果当前的r和最大的h都没法凑够所需要的体积, 就不用往下搜索了
			if(r*r*tmpH*d<v){
				break;
			}
			for (int h = tmpH; h >= d; --h){
				// 依然是可行性剪枝,考虑下一层最大的r和最大的h都没法凑够所需要的体积v,也要剪掉
				if(r*r*h+(r-1)*(r-1)*(h-1)*(d-1)<v){
					break;
				}
				dfs(v-r*r*h,d-1,r-1,h-1,s+2*r*h);
			}
		}
	}
}

int main(int argc, char const *argv[]){
	scanf("%d%d",&n, &m);
	for(int r=(int)sqrt(1.*n/m)+1; r>=m; --r){
		for(int h=n/m+1; h>=m; --h){
			if(m>1 && r*r*h<n){
				dfs(n-r*r*h,m-1,r-1,h-1,r*r+2*r*h);
			}
			// 特殊情况 m==1 蛋糕只有一层, 就不用进dfs了..
			if(m==1 && r*r*h==n){
				ans = min(ans,2*r*h+r*r);
			}
		}
	}
	printf("%d\n", ans==INF?0:ans);
	return 0;
}
