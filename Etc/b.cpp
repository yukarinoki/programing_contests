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
  int k,t;
  cin >> k;
  cin >> t;
  
  vector<int> v;
  rep(i,t){
    int tem;
    cin >> tem;
    v.push_back(tem);
  }
  if(t==1){
    cout << (k-1) << "\n";
    return 0;
  }


  sort(all(v),greater<int>());
  int sum=0;
  rep(i,v.size()){
    sum+=v[i];
  }
  sum -= v[0];
  if(v[0]>sum){
    cout << (v[0]-sum-1) << "\n";
  }
  else{
    cout << "0\n";
  }
  return 0;
}
