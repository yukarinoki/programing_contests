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
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1e+9
#define MAX_V 2000005

struct edge {
    int to;
    int cost;
};

// <最短距離, 頂点の番号>
using P = pair<int, int>;
int K;
int V;
vector<edge> G[MAX_V];
int d[MAX_V];
vector<bool> visited[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin >> V >> K;
    int E;
    cin >> E;
    for (int i=0; i<E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edge e = {b-1, c};
        G[a-1].push_back(e);
        e = {a-1, c};
        G[b-1].push_back(e);
    }
    return 0;
}