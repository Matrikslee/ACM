#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::cin; 
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
	srand(time(NULL));
	int n = rand()%1000+1;
	int r = rand()%1000+1;
	for(int i=0; i<n; ++i){
		const int d[] = {-1,1};
		int dr = (int)sqrt(r);
		cout << rand()%500*d[rand()%2] << " " << r-rand()%dr*(rand()%3+1) << endl;
	}
	return 0;
}