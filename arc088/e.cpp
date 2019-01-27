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
 
ll merge_sort(vector<int> &a) {
  int n = a.size();
  if (n == 1) {
    return 0;
  }
  ll ret = 0;
  vector<int> b(begin(a), begin(a) + n/2);
  vector<int> c(begin(a) + n/2, end(a));
  ret += merge_sort(b);
  ret += merge_sort(c);
  int sz_b = b.size();
  int sz_c = c.size();
  for (int i = 0, j = 0, k = 0; i < n; ++i) {
    if (j >= sz_b) {
      a[i] = c[k]; k += 1;
    } else if (k >= sz_c) {
      a[i] = b[j]; j += 1;
    } else if (b[j] <= c[k]) {
      a[i] = b[j]; j += 1;
    } else {
      a[i] = c[k]; k += 1;
      ret += n/2 - j;
    }
  }
  return ret;
}


int main(){
  string s;
  cin >> s;
  int n = s.length();
  int c[256];
  for(int i=0;i<256;i++) c[i] = 0;
  for(int i=0;i<n;i++) c[s[i]]++;
  int flag = 0;
  for(int i=0;i<256;i++) if(c[i] % 2 != 0){
    if(n % 2 == 1) flag += 1;
    else flag += 2;
  }
  if(flag>1){cout << -1 << endl; return 0;}
  
  vector<int>  bv(n);
  vector<int> iv(n);
  rep(i,n) iv[i] = 0;
  rep(i,n){
      iv[s[i]]++;
      if(c[s[i]] % 2){
        if(iv[s[i]] == (c[s[i]]+1)/2) bv[i] = 3;
        else if(iv[s[i]] < c[s[i]]/2) bv[i] = 1;
        else bv[i] = 2;
      }else{
          if(iv[s[i]] <= c[s[i]]/2) bv[i] = 1;
          else bv[i] = 2;
      }
  }
  vector<int> v(n), cv(n);
  int lp = 0, rp = (n+1) / 2;
  int mid_p;
  rep(i,n) v[i] = 1;
  rep(i,n){
      if(bv[i]==1) v[lp++] = i;
      else if(bv[i] == 2) v[rp++] = i;
      else mid_p = i;
      cv[i] = i;
  }
  if(n % 2) v[n/2] = mid_p;
  rep(i,n) cout << v[i] << " ";
  vector<int> ind(n);
  rep (i, n) {
    ind[v[i]] = i;
  }
 cout << endl;
  printf("%lld\n", merge_sort(v));
 
  return 0;
    return 0;
}
