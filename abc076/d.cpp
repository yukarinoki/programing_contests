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
#define DEBUGM(d,n,m,i,j) printf("DEBUGM :\n"); rep(i,n){ rep(j,m) if(inf==d[i][j]) printf("inf "); else printf("%d ", d[i][j]); printf("\n");} printf("DEBUGM END LINE\n")

typedef vector<vector<pair<int,int> > > graph;
typedef long long ll;

const ll INF =1LL << 62;
const int inf =1 << 29;

double dp[40005];
double v[105],t[105];

bool check(double tm,int tmz,double val, int n){
    // tm にはその時間帯で左から秒目かが入っている。    
    double gap = (double)t[tmz] - tm;
    if(val > v[tmz]) return false;
    double sum=0;
    while(tmz <= n){
        if(val - (gap+sum) > v[tmz+1]) return false;
        if(val - (gap+sum) < 0) break;
        sum += t[tmz+1];
        tmz++;
    }
    return true;
}

int main(){
    int n,sum=0;;
    cin >> n;
    rep(i,n){cin >> t[i]; sum += t[i];}
    rep(i,n) cin >> v[i];
    sum *= 2;
    v[n] = 0.000005;
    t[n] = 0.000005;
    dp[sum] = 0;
    dp[0] = 0;
    int tmz = 0;int timesum = t[0];
    double tm = 0;
    for(int i=1;i<sum;i++){
        tm+=0.5;
        if(i*2 == timesum){tmz++; timesum += t[tmz];tm=0;}
        if(check(tm,tmz,dp[i-1]+0.5,n)) dp[i] = dp[i-1]+0.5;
        else if(check(tm,tmz,dp[i-1],n)) dp[i] = dp[i-1];
        else dp[i] = dp[i-1] - 0.5;
    }
    double ans=0;
    rep(i,sum) {
        cout << i << ":" << dp[i] << endl;
        ans+=(dp[i]*0.5);
    }
    cout << ans << endl;
    return 0;
}