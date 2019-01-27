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


int main(){
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i=0; i< n-1; i++){
    int u, v;
    scanf("%d %d", &u,&v);
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int K;
  cin >> K;
  vector<int> val(n, INT_MAX);
  priority_queue<pair<int, int>> q;
  for(int i=0; i<K; i++){
    int v, p;
    scanf("%d %d", &v,&p);
    v--;
    val[v] = p;
    q.emplace(val[v],v);
  }
  while (!q.empty()){
    int u;
    tie(ignore,u) = q.top(); q.pop();
    for(int v : g[u]){
      if (val[v] == INT_MAX) {
	val[v] = val[u] - 1;
	q.emplace(val[v],v);
      } else if  (abs(val[v] -val[u]) != 1){
	puts("No");
	return 0;
      }
    }
  }
  puts("Yes");
  for (int i=0; i< n; i++){
    printf("%d\n", val[i]);
  }
  return 0;
}
