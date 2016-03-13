#include <iostream>
#include <string>

#define MAXN 111

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]){
	string currentPage = "http://www.acm.org/";
	string forwardStack[MAXN], *forwardTop=forwardStack;
	string backwardStack[MAXN], *backwardTop=backwardStack;
	for(string s; cin>>s && s!="QUIT"; ){
		bool ignored = false;
		if(s=="VISIT"){
			*backwardTop++ = currentPage;
			forwardTop = forwardStack;
			cin >> currentPage;
		}
		if(s=="BACK"){
			if(backwardTop==backwardStack){
				ignored = true;
			} else {
				*forwardTop++ = currentPage;
				currentPage = *--backwardTop;
			}
		}
		if(s=="FORWARD"){
			if(forwardTop==forwardStack){
				ignored = true;
			} else {
				*backwardTop++ = currentPage;
				currentPage = *--forwardTop;
			}
		}
		if(ignored){
			cout << "Ignored" << endl;
		} else {
			cout << currentPage << endl;
		}
	}
	return 0;
}