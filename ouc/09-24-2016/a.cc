#include <iostream>
#include <string>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::priority_queue;

struct node{
  int d;
  string s;
  node *l, *r;
  node():s(),l(NULL),r(NULL),d(0){};
  node(const string& s, int d):s(s),l(NULL),r(NULL),d(d){};
  void del();
};
bool operator<(const node& a, const node& b) {
  bool ret = false;
  if((a.l&&b.l) || (!a.l&&!b.l)){
    ret = a.s > b.s;
  } else {
    if(!a.l) { ret = true; }
    else { ret = false; }
  }
  return ret;
}

class tree{
  node *root;
  void put(node* root);
public:
  tree();
  ~tree();
  void clear();
  void ins(const string& s);
  void print();
};

int main(){
  tree tre;
  tre.clear();
  int cas = 0;
  string s;
  while(cin>>s) {
    if(s[0]=='0') {
      cout << "Case " <<++cas<<":"<<endl;
      tre.print();
      tre.clear();
      continue;
    }
    tre.ins(s+'/');
  }
  return 0;
}

tree::tree() {
  this->root = new node();
}

tree::~tree(){
  this->clear();
}

void tree::clear(){
  this->root->del();
  this->root = new node();
}

void tree::ins(const string& s){
  node* p = root;
  string ss = "";
  int len = s.size();
  for ( int i = 0; i < len; ++i ){
    if(s[i]=='/'){
      if(p->l) {
        p = p->l;
        if(p->s==ss){ ss.clear(); }
        while(!ss.empty() && p->r) {
          p = p->r;
          if(p->s==ss){ ss.clear(); }
        }
        if(!ss.empty()){
          p->r = new node(ss, p->d);
          p = p->r;
        }
      } else {
        p->l = new node(ss,p->d+1);
        p = p->l;
      }
      ss.clear();
    } else {
      ss += s[i];
    }
  }
}

void node::del() {
  if(this->l) {
    this->l->del();
  }
  if(this->r) {
    this->r->del();
  }
  delete(this);
}

void tree::print(){
  if(root->l) { put(root->l); }
}

void tree::put(node* root){
  priority_queue<node> Q;
  Q.push(*root);
  node* p = root;
  while(p->r) {
    Q.push(*p->r);
    p = p->r;
  }
  while(!Q.empty()) {
    const node& p = Q.top();
    for ( int i = 1; i < p.d; ++ i ){
      cout << "    ";
    }
    cout << p.s << endl;
    if(p.l) { put(p.l); }
    Q.pop();
  }
}
