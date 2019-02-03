#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

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

//頂点名は 0 ... n-1 で振られている
//
int main(){
    int V,E; cin >> V >> E;
    struct UnionFind uf(V);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > s;
    vector<pair<int,int> > edge(E);
    for(int i=0;i<E;i++){
        int wi; 
        cin >> edge[i].first >> edge[i].second >> wi;
        s.push(make_pair(wi, i));
    }
    int sum = 0;

    while(!s.empty()){
        int weight = s.top().first, index = s.top().second;
        s.pop();
        if(!uf.findSet(edge[index].first, edge[index].second)){
            sum += weight; 
            uf.unionSet(edge[index].first, edge[index].second);
        }
    }
    cout << sum << endl;
    return 0;
}