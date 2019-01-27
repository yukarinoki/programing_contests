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
  vector<pair <ll, int> > f;
  int c[n]; //0isR 1 is B ,2 is G
  rep(i,n){
    ll tem;
    char a[3];
    cin >> tem >> a;
    if(a[0]=='R') c[i]=0;
    else if(a[0]=='B') c[i]=1;
    else if(a[0]=='G') c[i]=2;
    f.push_back(mp(tem,i));
  }
  sort(all(f));
  int cl[3][n];
  //cl[i][j] is the number of i th color fish by j (j is contained)
  rep(j,3) cl[j][0]=0;
  cl[c[f[0].second]][0]++;
  
  for(int i=1;i<n;i++){
    int ind = f[i].second;
    rep(j,3){
      cl[j][i]=cl[j][i-1];
    }
    cl[c[ind]][i]++;
  }

  memo[7][3];
  //r 0 g 1 b 2
  //rg 3 rb 4 gb 5 all 6
  rep(i,7){rep(j,3){memo[i][j]=0;}}

  rep(i,n-1){
    int ind = f[i].second;
    ll si = f[i].first;
   
  //binary search
    int low=0,up=n-1;
    ll bo = 2*si;
    while(low+1!=up){
      int mid = (low+up)/2;
      if(f[mid].first < bo){low = mid;}
      if(f[mid].first > bo){up = mid;}
      if(f[mid].first == bo){low = mid; break}
    }
    
    if(memo[0][0]>)

    
    
  }
    return 0;
}
