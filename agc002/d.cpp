#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
typedef long long ll;
 
#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

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

int bin(int n, vector<int> &x, vector<int> &y, vector<int> &z, vector<int> &a, vector<int> &b, vector<int> &ans, vector<int> &s, int l, int u){
    //l < score <= u
    if(l+1==u){
        rep(i,s.size()) ans[s[i]-1] = u;
        return 0;
    }
    int mid = (l + u) / 2;
   
    struct UnionFind uf(n);
    vector<int> s1,s2;
    rep(i,mid){
        uf.unionSet(a[i]-1,b[i]-1);
    }
    rep(i,s.size()){
        if(uf.findSet(x[s[i]-1]-1,y[s[i]-1]-1)){
            if(uf.size(x[s[i]-1]-1) >= z[s[i]-1]){
                s1.push_back(s[i]);
            }else{
                s2.push_back(s[i]);          
            }
        }else{
            if(uf.size(x[s[i]-1]-1) + uf.size(y[s[i]-1]-1) >= z[s[i]-1]){
                s1.push_back(s[i]);           
            }else{
                s2.push_back(s[i]);           
            }
        }
    }
    bin(n,x,y,z,a,b,ans,s1,l,mid);
    bin(n,x,y,z,a,b,ans,s2,mid,u);
    return 0;
} 

int main(){
    int N,M,Q;
    cin >> N >> M;
    vector<int> a(M),b(M);
    rep(i,M){cin >> a[i]; cin >> b[i];}
    cin >> Q;
    vector<int> x(Q),y(Q),z(Q),ans(Q),s(Q);
    rep(i,Q){cin >> x[i]; cin >>y[i]; cin >> z[i];}
    rep(i,Q) s[i] = i + 1;
    bin(N,x,y,z,a,b,ans,s,0,M);
    rep(i,Q) cout << ans[i] << endl;

    return 0;
 }