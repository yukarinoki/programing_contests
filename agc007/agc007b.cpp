
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
  vector< pair<int, int> > vv;
  rep(i,n){
    int tem;
    cin >> tem;
    vv.push_back(mp(tem,i+1));
  }
  sort(all(vv));
  vector<int> v;
  rep(i,n){
    v.push_back(vv[i].second);
  }
  vector<int> b, a;
  b.push_back(v[0]-1);
  a.push_back(1);
  for(int i=1;i<n;i++){
    int tem = v[i]-(a[i-1]+1);
    if(b[i-1]<tem+1){b.push_back(b[i-1]-1);a.push_back(v[i]-b[i-1]+1);}
    else {b.push_back(tem); a.push_back(v[i]-tem);}
  }
  int offset = 1-b[n-1];
  rep(i,n){
    b[i] += offset; 
  }
  rep(i,n){
    cout << a[i] << " ";
  }
  cout << "\n";
  rep(i,n){
    cout << b[i] << " ";
  }
  cout << "\n";
  return 0;
}
