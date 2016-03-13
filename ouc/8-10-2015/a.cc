#include <iostream>
#include <string>
#include <queue>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]){
	for(int n; cin>>n; ){
		string a, b; cin >> a >> b;
		std::stack<char> st;
		std::queue<string> ans;
		for(int i=0,j=0; i<n; ++i){
			st.push(a[i]);
			ans.push("in");
			while(!st.empty() && st.top()==b[j]) {
				st.pop();
				ans.push("out");
				++j;
			}
		}
		if(!st.empty()){
			cout << "No." << endl;
		} else {
			cout << "Yes." << endl;
			for(; !ans.empty(); ans.pop()) {
				cout << ans.front() << endl;
			}
		}
		cout << "FINISH" << endl;
	}
	return 0;
}