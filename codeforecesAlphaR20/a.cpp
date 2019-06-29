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

#define INF 1e+15
#define MAX_V 100005

struct edge {
    long long int to;
    long long int cost;
};

// <最短距離, 頂点の番号>
using P = pair<long long int,long long int>;

int V;
vector<edge> G[MAX_V];
long long int d[MAX_V];
int prev_vertex[MAX_V];

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
                prev_vertex[e.to] = v;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin >> V;
    int E;
    cin >> E;
    for (int i=0; i<E; ++i) {
        long long int a, b;
        long long int c;
        cin >> a >> b >> c;
        {
            edge e = {b-1, c};
            bool flag = true;
            rep(i, G[a-1].size()){
                if(G[a-1][i].to == b-1){
                    G[a-1][i].cost = min(G[a-1][i].cost, c);
                    flag = false;
                    break;
                }
            }
            if(flag) G[a-1].push_back(e);
        }
        swap(a,b);
        {
            edge e = {b-1, c};
            bool flag = true;
            rep(i, G[a-1].size()){
                if(G[a-1][i].to == b-1){
                    G[a-1][i].cost = min(G[a-1][i].cost, c);
                    flag = false;
                    break;
                }
            }
            if(flag) G[a-1].push_back(e);
        }
    }
    dijkstra(0);
    int v = V-1;
    if(d[v]==INF){
        cout << -1 << endl;
       // rep(i,V) cout << i+1 << ":" << d[i] << endl;
    }else{
        vector<int> shortest_path;
        shortest_path.push_back(v+1);
        while(v!=0) {
            v = prev_vertex[v];
            shortest_path.push_back(v+1);
        }
        reverse( all(shortest_path) );
        rep(i,shortest_path.size()) cout << shortest_path[i] << " ";
        cout << endl;
    }
    return 0;
}