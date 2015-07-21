#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 1111111

typedef unsigned int uint;

struct S{
	int binary, step;
	S():binary(0),step(0){}
	S(int b, int s):binary(b),step(s){}
};

int change(uint x, int pos, int len){
	uint res;
	if(len<3 || pos==0){
		res = x^3;
	} else {
		if(pos+1==len){
			res = x^(3<<--pos);
		} else {
			res = x^(7<<--pos);
		}
	}
	return res;
}

int main(int argc, char const *argv[]){
	for(char s[30]; ~scanf("%s", s);){
		static bool v[MAXN];
		memset(v,0x0,sizeof(v));
		uint len = strlen(s), x = 0;
		for(int i=0; i<len; ++i){
			x = x*2+(s[len-i-1]-'0');
		}
		int ans = -1;
		std::queue<S> q;
		for(;!q.empty();q.pop());
		q.push(S(x,0)); v[x] = true;
		while(!q.empty()){
			S tmp = q.front(); q.pop();
			if(tmp.binary == 0){
				ans = tmp.step;
				break; 
			}
			for(int i=0; i<len; ++i){
				int tmpX = change(tmp.binary,i,len);
				if(!v[tmpX]){
					q.push(S(tmpX, tmp.step+1));
					v[tmpX] = true;
				}
			}
		}
		ans!=-1?printf("%d\n", ans):printf("NO\n");;
	}
	return 0;
}