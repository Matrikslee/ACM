#include <iostream>
#include <queue>
#include <string>

using std::cin;
using std::cout;
using std::endl;;
using std::string;

struct node{
	node *next;
	string name; 
	int parameter, priority;
	node():name(""), parameter(0), priority(0), next(NULL){}
	node(const string &n, int para, int prio): name(n), parameter(para), priority(prio), next(NULL){}
	node(const string &n, int para, int prio, node *ne): name(n), parameter(para), priority(prio), next(ne){}
	~node(){}
};

class priority_queue{
	node *head;
public:
	priority_queue(){ head = new node(); }
	bool empty(){ return NULL==head->next; }
	void push(const string &name, int para, int prio){
		for(node *q = head; q!=NULL; q=q->next){
			if( q->next==NULL || prio < q->next->priority){
				q->next = new node(name,para,prio,q->next);
				break;
			}
		}
	}
	node pop(){
		node *p = head->next;
		head->next = p->next;
		node ans = *p; delete p;
		return ans;
	}
	~priority_queue(){
		while(head->next!=NULL){
			node *p=head->next;
			head->next=p->next;
			delete p;
		}
		delete head;
	}
	
};

int main(int argc, char const *argv[]){
	priority_queue Q;
	for(string s; cin>>s; ){
		if( s=="PUT" ){
			string name; int parameter, priority;
			cin >> name >> parameter >> priority;
			Q.push(name, parameter, priority);
		}
		if( s=="GET" ){
			if( !Q.empty() ){
				node x = Q.pop();
				cout << x.name << " " << x.parameter << endl;
			} else {
				cout << "EMPTY QUEUE!" << endl;
			}
		}
	}
	return 0;
}