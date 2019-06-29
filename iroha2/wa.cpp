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
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))

typedef long long ll;
int n,dp[5005][5005],xlen,ylen;
string x,y;

int main(){
    cin>>x>>y;
    xlen=x.size();
    ylen=y.size();
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=xlen;i++){
      for(int j=1;j<=ylen;j++){
    if(x[i-1]==y[j-1])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
      }
    }
    cout<< dp[xlen][ylen]+1 <<endl;
    return 0;
}