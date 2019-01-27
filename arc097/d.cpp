#include <iostream>
#include <string>
#include <vector>
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
    int n;
    cin >> n;
    struct UnionFind uf(n);
    int m;
    cin >> m;
    int p[n];
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        uf.unionSet(a-1,b-1);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(uf.findSet(i,p[i]-1)) ans++;
    }
    cout << ans << endl;
    return 0;
}