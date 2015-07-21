#include <cstdio>

bool search(int curval, int target, int* num);

int main(int argc, char const *argv[])
{
	int num[6]={0}, cnt=0;
	while(scanf("%d%d%d%d%d%d",num,num+1,num+2,num+3,num+4,num+5) != EOF){
		if(!num[0] && !num[1] && !num[2] && !num[3] && !num[4] && !num[5]) { break; }
		printf("Collection #%d:\n", ++cnt);
		for(int i=1; i<7; ++i){ num[i-1] %= (60/i); }
		int sumval = num[0]*1+num[1]*2+num[2]*3+num[3]*4+num[4]*5+num[5]*6;
		if(sumval&1){ printf("Can't be divided.\n\n"); }
		else if(search(0, sumval>>1, num)){ printf("Can be divided.\n\n"); }
			 else { printf("Can't be divided.\n\n"); }
	}
	return 0;
}

bool search(int curval, int target, int* num){
	bool ret = false;
	if(curval==target) { ret=true; }
	else if(curval<target){
		for(int i=5; i>=0; --i){
			if(num[i]==0){ continue; }
			if(i+1>target) { continue; }
			num[i]--;
			if(search(curval+i+1, target, num)) { ret=true; }
			num[i]++;
			if(ret) { break; }
		}
	}
	return ret;
}

