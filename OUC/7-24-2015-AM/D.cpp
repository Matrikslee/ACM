#include <cstdio>
#include <algorithm>

#define MAXN 22

int  totnum, requirenum, singlelen, totlen, sticklen[MAXN];

bool check(int curlen, int position, int finishnum);
bool cmp(int a, int b) { return a>b; }

int main(int argc, char const *argv[]){
	int T; 
	for(scanf("%d",&T);T;--T){
		scanf("%d", &totnum);
		totlen = 0;
		for(int i = 0; i < totnum; ++i){
			scanf("%d", sticklen+i);
			totlen += sticklen[i];
		}
		std::sort(sticklen, sticklen+totnum, cmp);
		bool hasAns = true; 
		if(totlen%4==0){
			requirenum = 4;
			singlelen = totlen / requirenum;
			hasAns = check(0, 0, 0);
		} else {
			hasAns = false;
		}
		const char ans[2][5] = {"no","yes"};
		printf("%s\n", ans[hasAns?1:0]);
	}
	return 0;
}

bool check(int curlen, int position, int finishnum)
{
	static bool flag[MAXN] = {false};
	bool ans = false;
	if(curlen == singlelen){
		if(++finishnum == requirenum) {
			ans = true;
		} else {
			for(position=0; flag[position]; ++position);
			flag[position] = true;
			ans = check(sticklen[position], position+1, finishnum);
			flag[position] = false;
		}
	} else if(curlen < singlelen) {
		int prelen = 0, newlen;
		for(int pos = position; pos<totnum; ++pos){
			if(flag[pos] || sticklen[pos] == prelen) { continue; }
			prelen = sticklen[pos];
			newlen = curlen+prelen;
			flag[pos] = true;
			ans = check(newlen,pos+1,finishnum);
			flag[pos] = false;
			if(ans || newlen==singlelen || curlen == 0) { break; }
		}
	}
	return ans;
}