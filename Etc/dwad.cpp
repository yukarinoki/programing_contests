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
  int n,m;
  cin >> n >> m;
  vector<pair <int,int> > xv;
  int x[n];
  int v[n];
  int sum[n+1];
  sum[0]=0;
  rep(i,n){
    int xx,yy;
    sum[i+1]=sum[i]+xx;
    cin >> xx >> yy;
    x[i]=xx;
    y[i]=yy;
    xv.push_back(mp(xx,i));
  }
  
  
  

  return 0;
}
