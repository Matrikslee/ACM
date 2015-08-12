#include <stdio.h>
#include <queue>

struct node {
	int position, weight;
	node() : position(0), weight(0){}
	node(int p, int w) : position(p), weight(w){}
	bool friend operator < (const node& a, const node& b){
		return a.position>b.position || (a.position==b.position && a.weight>b.weight);
	}
	~node(){}
};

class person{
	int position;
	bool is_throw;
	std::priority_queue<node> road;
public:
	person(): position(0), is_throw(true){ }
	~person() { }
	void putStone(int p, int w) {
		road.push(node(p, w));
	}
	void run() {
		while( !road.empty() ) {
			int weight = road.top().weight;
			position = road.top().position; road.pop();
			if( is_throw ) {
				putStone(position+weight, weight);
			}
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