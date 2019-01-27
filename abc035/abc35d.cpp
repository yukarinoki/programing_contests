#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue> 

using namespace std;

#define deb(x) printf("deb:%d\n", x)
#define DEB(x) printf("x")
#define REP(i,a,b) for(int i=a;i<b;i++)
#define PQ priority_queue 

class node{
public:
  vector<int> edge_to;//
  vector<int> edge_cost;//
  int num;
  bool done;
  int cost;

  node(int n){
  done =false;
  cost=-1;
  num=n;
  }

  bool operator<( const node& t) const {
    return cost>t.cost;
  }
};

void dik(vector<node> t){
    PQ <node, vector<node> > q;
    t[0].cost=0;
    q.push(t[0]);
    DEB(1);
    while(!q.empty()){
      if(t[q.top().num].done==true){q.pop();}
      else{
      for(int i=0;i<((q.top()).edge_to).size();i++){
	DEB(2);
	int to = q.top().edge_to[i];
	int cost = q.top().cost+(q.top().edge_cost)[i];
	if(t[to].cost<0||cost<t[to].cost){
	  t[to].cost=cost;
	  q.push(t[to]);
	  t[q.top().num]=q.top();
	  t[q.top().num].done=true;	  
	  q.pop();
	}
      }
      }
    }
}

  int main(){
    int n, m, T;
    scanf("%d%d%d",&n,&m,&T);
    vector<node> t;
    int A[n];
    REP(i,0,n){
      node tem(i);
      t.push_back(tem);
      scanf("%d", &A[i]);
}
    deb(T);
    REP(i,0,m){
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      t[a].edge_to.push_back(b);
      t[a].edge_cost.push_back(c);
      t[b].edge_to.push_back(a);
      t[b].edge_cost.push_back(c);
}
    deb(m);
    dik(t);
    int ans=0;
    REP(i,0,n){
      ans =  (ans>=(T-2*t[i].cost)*A[i]?ans:(T-2*t[i].cost)*A[i]);
      printf("%d\n", ans);
}
  return 0;
} 
