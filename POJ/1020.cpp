#include <cstdio>

bool search(int deep, int target, int size, int *cake);

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		int size, n, cake[40]={0}, tot=0, piecesize;
		scanf("%d%d", &size, &n);
		for(int i=0; i<n; ++i){
			scanf("%d", &piecesize);
			tot += piecesize*piecesize;
			++cake[piecesize];
		}
		bool flag=false;
		if(tot==size*size) { flag=search(0, n, size, cake); }
		if(flag){ printf("KHOOOOB!\n");} 
		else { printf("HUTUTU!\n");}
	}
	return 0;
}

bool search(int finish, int target, int size, int *cake)
{
	bool ans=false;
	static int row[40]={0};
	if(finish==target){ ans=true; }
	else{
		int pos=40, minrow=1024;
		for(int i=0; i<size; ++i) {						 //找最小的可以放蛋糕的行
			if(row[i]<minrow){
				minrow=row[i];
				pos=i;
			}
		}
		int h=0;
		while(pos+h<size&&row[pos+h]==minrow) { ++h; }   //最大的可以放蛋糕的列数
		int l=size-minrow;        						 //最大的可以放蛋糕的行数
		int maxpiece=l<h?l:h; 							 //最大的可以放蛋糕的边长
		for(int i=maxpiece; i>0; --i){
			if(cake[i]>0){
				--cake[i];
				for(int j=pos; j<pos+i; ++j) { row[j]+=i; }
				ans=search(finish+1,target,size,cake);   //深度搜索、回溯
				for(int j=pos; j<pos+i; ++j) { row[j]-=i; }
				++cake[i];
			}
			if(ans) { break; }
		}
	}
	return ans;
}