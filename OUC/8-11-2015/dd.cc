#include <stdio.h>

struct node {
	node *next;
	int parameter;
	node():parameter(0), next(NULL){}
	node(int p): parameter(p), next(NULL){}
	node(int p, node* n): parameter(p), next(n){}
	~node(){}
};

template <class T>
class insert_queue{
	T* head;
public:
	insert_queue(){ head = new T(); }
	void insert(int position, int parameter){
		T* q = head;
		for( int cnt=0; ++cnt<=position; q=q->next );
		q->next = new T(parameter, q->next);
	}
	void output_node(){
		for(T* q=head; q->next!=NULL; q=q->next){
			printf("%d ", q->next->parameter);
		}
		printf("\n");
	}
	~insert_queue(){
		while(head->next != NULL){
			T* p = head->next;
			head->next = p->next;
			delete p;
		}
		delete head;
	}
};

int main(int argc, char const *argv[]) {
	for(int n; ~scanf("%d", &n); ){
		insert_queue<node> list;
		for(int i=0; i<n; ++i){
			int position, parameter;
			scanf("%d%d", &position, &parameter);
			list.insert(position,parameter);
		}
		list.output_node();
	}
	return 0;
}