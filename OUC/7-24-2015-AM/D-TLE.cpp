#include <iostream>
#include <cstring>

#define MAXLEN 51111

using std::cin;
using std::cout;
using std::endl;

bool dfs(int stickNum[], int nowlen, int sidelen, int totnum){
	bool res = false;
	if(nowlen==sidelen){
		res = true;
	} else {
		for(int singlelen=sidelen; singlelen>0; --singlelen){
			if(stickNum[singlelen]>0 && singlelen+nowlen<=sidelen){
				--stickNum[singlelen];
				if(dfs(stickNum, nowlen+singlelen, sidelen, totnum)){
					res = true;
					break;
				}
				++stickNum[singlelen];
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[]){
	static int stickNum[MAXLEN], T;
	for(cin >> T; T; --T){
		memset(stickNum, 0x0, sizeof(stickNum));
		int n, totlen=0; cin>>n;
		for(int i=0; i<n; ++i){
			int x; cin >> x;
			++stickNum[x];
			totlen += x;
		}
		bool hasAns = true; 
		if(totlen%4==0){
			int sidelen = totlen/4, finish=0;
			while(finish<4 && hasAns){
				int nowlen = 0;
				for(int singlelen=sidelen; singlelen>0; --singlelen){
					if(stickNum[singlelen]>0){
						--stickNum[singlelen];
						if(dfs(stickNum, singlelen, sidelen, n)){
							++finish;
						} else {
							hasAns = false;
						}
						break;
					}
				}
			}
			hasAns = (finish==4);
		} else{
			hasAns = false;
		}
		const char ans[2][5] = {"no","yes"};
		cout << ans[hasAns?1:0] << endl;
	}
	return 0;
}