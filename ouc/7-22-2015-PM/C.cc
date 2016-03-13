#include <cstdio>

#define MAXN 40

inline int min(int a, int b) {return a<b?a:b;}

bool find(int finishNum,const int targetNum,int maxSize, int *cake){
	bool res = false;
	static int row[MAXN];
	if(finishNum==targetNum){
		res = true;
	} else {
		int pos = MAXN, minrow = 1<<10;
		for(int i=0; i<maxSize; ++i){
			if(row[i]<minrow){
				minrow = row[i];
				pos = i;
			}
		}
		int width = 0;
		for(;pos+width<maxSize&&row[pos+width]==minrow;++width);
		int length = maxSize - minrow;
		int maxLen = min(width,length);
		for(int i=maxLen; i>0; --i){
			if(cake[i]){
				--cake[i];
				for(int j=0;j<i;row[pos+j++]+=i);
				res = find(finishNum+1,targetNum,maxSize,cake);
				for(int j=0;j<i;row[pos+j++]-=i);
				++cake[i];
			}
			if(res) { break; }
		}
	}
	return res;
}

int main(int argc, char const *argv[]){
	int t;
	for(scanf("%d",&t); t; --t){
		int maxSize,n,pieceSize,totArea=0,cake[MAXN]={0};
		scanf("%d%d", &maxSize,&n);
		for(int i=0; i<n; ++i){
			scanf("%d", &pieceSize);
			totArea += pieceSize*pieceSize;
			++cake[pieceSize];
		}
		bool is_ok = false;
		if(totArea==maxSize*maxSize){
			is_ok = find(0,n,maxSize,cake);
		}
		if(is_ok){
			printf("KHOOOOB!\n");
		} else {
			printf("HUTUTU!\n");
		}
	}
	return 0;
}