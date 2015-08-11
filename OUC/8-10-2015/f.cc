#include <stdio.h>
#include <queue>

struct node {
	node *next;
	int position, weight;
	node():position(0), weight(0), next(NULL){}
	node(int p, int w): position(p), weight(w), next(NULL){}
	node(int p, int w, node* n): position(p), weight(w), next(n){}
	~node(){}
};

class priority_queue{
	node *head;
public:
	priority_queue(){ head = new node(); }
	bool empty(){ return NULL==head->next; }
	void push(int position, int weight){
		for(node *q = head; q!=NULL; q=q->next){
			if( q->next==NULL || 
				position < q->next->position || 
				( position == q->next->position && weight<q->next->weight ) ) {
				q->next = new node(position, weight, q->next);
				break;
			}
		}
	}
	const node& front() const {
		return *(head->next);
	}
	void pop() {
		node *p = head->next;
		head->next = p->next;
		delete p;
	}
	~priority_queue(){
		while(head->next!=NULL){
			node *p = head->next;
			head->next = p->next;
			delete p;
		}
		delete head;
	}
};

class person{
	int position;
	bool is_throw;
	priority_queue road;
public:
	person(): position(0),is_throw(true){}
	~person() {}
	void putStone(int p, int w) {
		road.push(p, w);
	}
	void run() {
		while( !road.empty() ){
			int weight = road.front().weight;
			position = road.front().position; road.pop();
			if( is_throw ) { this->putStone(position+weight, weight); }
			is_throw = !is_throw;
		}
	}
	int ans(){ return position; }
};

int main(int argc, char const *argv[]){
	int T; for( scanf("%d", &T); T; --T){
		person Sempr; int n;
		for( scanf("%d", &n); n; --n){
			int x, y; scanf("%d%d", &x, &y);
			Sempr.putStone(x,y);
		}
		Sempr.run();
		printf("%d\n", Sempr.ans());
	}
	return 0;
}