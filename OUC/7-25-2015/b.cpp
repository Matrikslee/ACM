#include <iostream>
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define MAXN 111111

struct TRIE{
	string val;
	TRIE* next[26];
	TRIE(){memset(next,0x0,sizeof(next));}
};

void insert(TRIE* root, TRIE*& pbuf, string &a, string &b){
	TRIE* p = root;
	int len = a.length();
	for(int i=0; i<len; ++i){
		int v = a[i]-'a';
		if(p->next[v]==NULL){
			p->next[v]=++pbuf;
		}
		p = p->next[v];
	}
	p->val = b.length()<len?b:a;
}

string& find(TRIE* root, string &s){
	TRIE* p = root;
	for(int i=0,len = s.length(); i<len; p = p->next[s[i]-'a'],++i);
	return p->val;
}

int main(int argc, char const *argv[]){
	static TRIE root[MAXN], *pbuf=root;
	int n,m; cin >> n >> m;
	for(int i=0; i<m; ++i){
		string a, b;
		cin >> a >> b;
		insert(root,pbuf,a,b);
	}
	for(int i=0; i<n; ++i){
		string s; cin >> s;
		cout << find(root,s) + " ";
	}
	return 0;
}