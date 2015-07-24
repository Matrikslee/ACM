#include <iostream>

#define MAXN 1111

using std::cin;
using std::cout;
using std::endl;

inline int min(int a, int b){ return a<b?a:b; }

bool search(int numbers[], int max, int sum, int ans[]){
	bool res = false;
	if(sum==0){
		res = true;
		for(int j=1; j<ans[0]; ++j){
			cout << ans[j] << "+";
		}
		cout << ans[ans[0]] << endl;
	} else {
		for(int i=min(max,sum); i>0; --i){
			if( numbers[i]>0 ){
				--numbers[i];
				ans[++ans[0]] = i;
				res = search(numbers, i, sum-i, ans)||res;
				++numbers[i];
				--ans[0];
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[]){
	for(int x, n; cin>>x>>n && x!=0; ){
		int numbers[MAXN]={0}, ans[MAXN]={0};
		for(int i=0; i<n; ++i){
			int tmp; cin >> tmp;
			tmp<=x && ++numbers[tmp];
		}
		cout <<"Sums of "<<x<<":"<<endl;
		if(!search(numbers, x, x, ans)){
			cout << "NONE" <<endl;
		}
	}
	return 0;
}