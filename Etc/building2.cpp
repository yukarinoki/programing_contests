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
  int N;
  cin >> N;
  vector<pair <ll, int> > hv;
  ll hgt[N];
  rep(i,N){
    ll tem;
    cin >> tem;
    hv.push_back(mp(tem,i));
    hgt[i] = tem;
  }
  sort(all(hv));
  vector<vector <int> > ad(N);
  rep(i,N-1){
    int a,b;
    cin >> a >> b;
    ad[a-1].push_back(b-1);
    ad[b-1].push_back(a-1);
  }
  int dp[N];
  rep(i,N){
    dp[i]=-1;
  }
  int ans=0;
  
  rep(i,N){
    int ind = hv[i].second;
    ll hi = hv[i].first;
    int len = 0;
    
    rep(j,ad[ind].size()){
      int fromi = ad[ind][j];
      if(hgt[fromi] < hi && dp[fromi] > len){
	len = dp[fromi];
      }
    }
    dp[ind] = 1 + len;
    cout << ind <<  ":" << dp[ind] << "\n";
    if(dp[ind] > ans) ans = dp[ind];
  }
  cout << ans << "\n";
  
  return 0;
}
