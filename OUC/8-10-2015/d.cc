#include <iostream>
#include <queue>
#include <string>

using std::cin;
using std::cout;
using std::endl;;
using std::string;

struct node{
	node *next;
	int index, priority;
	node():index(0), priority(0), next(NULL){}
	node(int i, int p): index(i), priority(p), next(NULL){}
	node(int i, int p, node *n): index(i), priority(p), next(n){}
	~node(){}
};

class link_table{
	node *head;
public:
	link_table(){ head = new node(); }
	bool empty(){ return NULL==head->next; }
	void insert(int i, int p){
		for(node *q = head; q!=NULL; q=q->next){
			if( q->next==NULL || p > q->next->priority){
				q->next = new node(i,p,q->next);
				break;
			}
		}
	}
	int pop(){
		node *p = head->next;
		head->next = p->next;
		int ans = p->index;
		delete p;
		return ans;
	}
	~link_table(){
		while(head->next!=NULL){
			node *p=head->next;
			head->next=p->next;
			delete p;
		}
		delete head;
	}
	
};

int main(int argc, char const *argv[]){
	for(int n; cin>>n; ){
		int cnt = 0;
		link_table dc[3];
		for(int i=0; i<n; ++i){
			string s; cin>>s;
			if( s=="IN" ){
				int x,y; cin >> x >> y;
				dc[x-1].insert(++cnt, y);
			}
			if( s=="OUT" ){
				int x; cin >> x;
				if( !dc[x-1].empty() ){
					cout << dc[x-1].pop() << endl;
				} else {
					cout << "EMPTY" << endl;
				}
			}
		}
	}
	return 0;
}