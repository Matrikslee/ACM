#include <iostream>
#include <vector>

#define MAXN 1111

using std::cin;
using std::cout;
using std::endl;

bool search(int numbers[], int sum, int ans[]){
	bool res = false;
	if(sum==0){
		res = true;
		for(int j=1; j<ans[0]; ++j){
			cout << ans[j] << "+";
		}
		cout << ans[ans[0]] << endl;
	} else {
		for(int i=sum-1; i>0; --i){
			if( numbers[sum-i]>0 ){
				--numbers[sum-i];
				ans[++ans[0]] = sum-i;
				res = search(numbers, i, ans)||res;
				++numbers[sum-i];
				--ans[0];
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[]){
	for(int x, n; cin>>x>>n && x*n!=0; ){
		int numbers[MAXN]={0}, ans[MAXN]={0};
		for(int i=0; i<n; ++i){
			int tmp; cin >> tmp;
			tmp<=x && ++numbers[tmp];
		}
		cout <<"Sum of "<<x<<":"<<endl;
		if(!search(numbers, x, ans)){
			cout << "NONE" <<endl;
		}
	}
	return 0;
}