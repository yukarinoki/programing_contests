

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;

struct Edge {
  int to, cost;  // 辺の接続先頂点, 辺の重み
  Edge(int to, int cost) : to(to), cost(cost) {}  // コンストラクタ
};

typedef vector<vector<Edge> > AdjList;  // 隣接リストの型
AdjList graph;  // グラフの辺を格納した構造体
// graph[v][i]は頂点vから出るi番目の辺Edge

const int INF = 100000000;


int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> co;
  graph = AdjList(n+1);

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back(Edge(to, cost));
    graph[to].push_back(Edge(from, cost));
    co.push_back(cost);
  }



  int nn=1;
  int ch[n+1];
  ch[1]=0;
  int num=0;
  while(nn<n){
    queue<int> q;
   
    q.push(nn);
    while(!q.empty()&&nn<n+1){
      int now = q.front();
      ch[now]=1;
      q.pop();
      //      cout << now << ":" <<nn << endl;
      vector<Edge> tte = graph[now];
      rep(i,(tte.size())){
	Edge tem = tte[i];
	if(ch[tem.to]!=1) q.push(tem.to);
      }
    }
      num++;
     while(nn<n+1&&ch[nn]==1) nn++;
  }
  int ans=0;
  sort(all(co));

  if(k>num){
    rep(i, (k-num)){
      ans+=co[i];
    }
  }
  cout << ans << ":" << num;
  cout << endl;
  return 0;
}
