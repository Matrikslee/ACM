#include <stdio.h>
#include <string.h>
#include <stack>

int main(int argc, char const *argv[]){
	for(static char s[222]; gets(s) && s[0]!='0'; ){
		std::stack<double> num;
		std::stack<char> flag;
		for(int i=0, f=0, x=0, len=strlen(s); i<=len; ++i){
			if( s[i]>='0' && s[i]<='9' ){ x = x*10 + s[i]-'0'; }
			if( s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' ){ flag.push(s[i]); }
			if( s[i]==' ' || s[i]=='\0' ) {
				if( !f ) {
					num.push(x); x = 0;
					if( !flag.empty() && flag.top()=='*' ) {
						double y = num.top(); num.pop();
						double x = num.top(); num.pop();
						flag.pop(); num.push(x*y);
					}
					if( !flag.empty() && flag.top()=='/' ) {
						double y = num.top(); num.pop();
						double x = num.top(); num.pop();
						flag.pop(); num.push(x/y);
					}
				}
				f = !f;
			}
		}
		while( !flag.empty() ){
			double y = num.top(); num.pop();
			double x = num.top(); num.pop();
			if(flag.top()=='+') { num.push(x+y); }
			if(flag.top()=='-') { num.push(x-y); }
			flag.pop();
		}
		printf("%.2lf\n", num.top());
	}
	return 0;
}