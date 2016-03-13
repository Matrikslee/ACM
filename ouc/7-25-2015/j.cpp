#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int maxDayNum[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int gcd(int a, int b){ return b?gcd(b,a%b):a; }

int main(int argc, char const *argv[]){
	int T; cin>>T;
	for(int t=1; t<=T; ++t){
		int x, y, day, month, year,ans=0;
		cin >> x >> y >> year;
		for(int j=1; j<=12; ++j){
			int maxDay = maxDayNum[j]+(j==2&&(year%400==0||(year%4==0&&year%100!=0)));
			for(int i=1; i <= maxDay; ++i){
				int tx = gcd(i,j), ty = (i*j)/tx;
				if(tx==x && ty==y ){
					++ans; day = i; month = j;

				}
			}
		}
		cout << "Case #"<< t << ": ";
		if(ans==0){
			cout << -1;
		} else if(ans==1){
			cout << year << "/"; 
			if(month<10){
				cout << 0;
			}
			cout << month << "/";
			if(day<10){
				cout << 0;
			}
			cout << day;
		} else {
			cout << 1;
		}
		cout << endl;
	}
	return 0;
}