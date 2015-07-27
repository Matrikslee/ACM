#include <iostream>
#include <cstring>
#include <string>
#define MAXN 111
#define MAXW 2111

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
	int T;for(cin>>T; T; --T){
		int n, k, w[MAXN], v[MAXN], maxWeight;
		cin >> n >> k;
		for(int i=0; i<n; ++i){
			cin >> v[i] >> w[i];
		}
		cin >> maxWeight;
		static int f[MAXN][MAXW];
		memset(f,0x0,sizeof(f));
		for(int j=0; j<n; ++j){
			for(int i=k; i>0; --i){
				for(int k=maxWeight; k>=w[j]; --k){
					if(f[i][k]<f[i-1][k-w[j]]+v[j]){
						f[i][k] = f[i-1][k-w[j]]+v[j];
					}
				}
			}
		}
		cout << f[k][maxWeight] << endl;
	}
	return 0;
}