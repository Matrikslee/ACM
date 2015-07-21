#include <cstdio>
#include <algorithm>

using namespace std;

bool flag, flag_tie;
int  value[26], solve[6], bestsolve[6];

void dfs(int need, int stampsnum, int type, int head, int tail);

int main(int argc, char const *argv[])
{
	while(1) {
		int x, num = 0, type[26] = {0};
		while(scanf("%d", &x) != EOF && x != 0){
			if(type[x] < 5) {
				value[num++] = x;
				type[x]++;
			}
		}
		if (num == 0) { break; }
		sort(value, value+num);
		while(scanf("%d", &x) != EOF && x != 0){
			flag_tie = flag = false;
			for(int i = 0; i < 6; ++i) { bestsolve[i]=0; }
			dfs(x, 0, 0, 0, num);
			printf("%d", x);
			if (bestsolve[0] == 0) { printf(" ---- none\n"); } 
			else {
				printf(" (%d):", bestsolve[0]);
				if(flag_tie) { printf(" tie\n"); }
				else {
					for (int i = 2; i < 2+bestsolve[1]; ++i){
						printf(" %d", bestsolve[i]);
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}

inline int max(int* arr, int l, int r)
{
	int x = arr[l];
	for(int i = l; i < r; ++i){
		if(arr[i] > x) x = arr[i];
	}
	return x;
}

inline void update(int typesnum, int stampsnum)
{
	bestsolve[0] = typesnum;
	bestsolve[1] = stampsnum;
	for(int i = 2; i < 6; ++i){
		bestsolve[i] = solve[i-2];
	} 
}

void dfs(int need, int stampsnum, int typesnum, int head, int tail)
{
	static int times[26] = {0};
	if(stampsnum < 5){
		if(need == 0) {
			if(flag == false) {
				flag = true;
				update(typesnum, stampsnum);
			} else {
				if(typesnum==bestsolve[0]){
					if(stampsnum==bestsolve[1]) {
						int maxcs = max(solve, 0, 4);
						int maxbs = max(bestsolve, 2, 6);
						if(maxcs == maxbs) { flag_tie = true; }
						else if(maxcs > maxbs) {
							flag_tie = false;
							update(typesnum, stampsnum);
						}
					} else if(stampsnum<bestsolve[1]) {
						flag_tie = false;
						update(typesnum, stampsnum);
					}
				} else if(typesnum>bestsolve[0]){
					flag_tie = false;
					update(typesnum,stampsnum);
				}
			}
		} else {
			for(int i = head; i < tail; ++i){
				if(need >= value[i]){
					solve[stampsnum] = value[i];
					times[i]++ == 0 && typesnum++;
					dfs(need-value[i],stampsnum+1,typesnum,i,tail);
					solve[stampsnum] = 0;
					times[i]-- == 1 && typesnum--;
				} else { break; }
			} 
		}
	}
}
