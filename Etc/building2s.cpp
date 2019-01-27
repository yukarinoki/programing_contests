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
typedef vector<int> vi;
int n;
int tall[100005];
vi g[100005];
pair<vi,vi> memo[100005];
int ans;

void merge_up(vi& a,vi& b){
  if(a.size() < b.size()) swap(a,b);
  rep(i,b.size()) a[i] = min(a[i],b[i]);
}

void merge_down(vi& a, vi& b){
  if(a.size() < b.size()) swap(a,b);
  rep(i,b.size()) a[i] = max(a[i],b[i]);
}
void calc(vi& up,int mid,vi& down){
  if(up.size() < down.size()){
    rep(i,up.size()){
      if(up[i]< mid) ans =
		       max(ans,
			   i+1+
			   (int)(
				 lower_bound(all(down),
					     mid,
					     greater<int>())
				 -down.begin())-1);
			   

int main(){


  return 0;
}
