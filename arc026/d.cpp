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

int main(){
    int n,m; cin >> n >> m;


    vector<pair<int,int> > edge(m);
    vector<double> c(m),t(m);
    for(int i=0;i<m;i++) cin >> edge[i].first >> edge[i].second >> c[i] >> t[i];
    double left = 0.0, right = 100000000.0;
    while(right - left > 0.0001){
        double mid = (left + right) / 2.0;

        vector<pair<double, int>> s;
        for(int i=0;i<m;i++) s.push_back(make_pair(c[i] - (t[i] * mid), i));
        sort(s.begin(), s.end());
        struct UnionFind uf(n);
        double sum = 0;
        for(int i=0;i<s.size();i++){
            double weight = s[i].first; 
            int index = i;
            if(weight <= 0 && !uf.findSet(edge[index].first, edge[index].second)) { sum += weight; uf.unionSet(edge[index].first, edge[index].second);}
            else if(weight <= 0) sum += weight;
            else if(!uf.findSet(edge[index].first, edge[index].second)){
            //    cout << weight <<"," << index << endl;
                sum += weight; 
                uf.unionSet(edge[index].first, edge[index].second);
            }
        }

        if(sum <= 0.0) right = mid;
        else left = mid;
    }

    cout << right << endl;
    return 0;
}