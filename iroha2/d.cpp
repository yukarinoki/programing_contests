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

typedef long long ll;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
      x = root(x); y = root(y);
    if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
    }
    return x != y;
    }
    bool findSet(int x, int y) {
    return root(x) == root(y);
    }
    int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
     return -data[root(x)];
    }
};

int main(){
    int V,E; cin >> V >> E;
    struct UnionFind uf(V);
    priority_queue<pair<int, int>> s;
    vector<pair<int,int> > edge(E);
    vector<bool> c(E);
    vector<pair<int,int> > wv(E);
    rep(i,E){
        cin >> edge[i].first >> edge[i].second;
        edge[i].first--; edge[i].second--;
        cin >> wv[i].first;
        wv[i].second = i;
    }
    rep(i,E) s.push(wv[i]);
    int sum = 0;
    while(!s.empty()){
            int weight = s.top().first, index = s.top().second;
            s.pop();
            if(!uf.findSet(edge[index].first, edge[index].second)){
                sum += weight; 
                uf.unionSet(edge[index].first, edge[index].second);
                c[index] = true;
            }
    }
    rep(i,E){
        if(c[i]) cout << i+1 << endl;
    }
    return 0;
}
