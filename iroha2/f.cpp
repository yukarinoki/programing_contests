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
#define DP(i) dp[(i)%2][a][b][c][d][e][f]

double dp[2][11][11][11][11][11][11];

double prob(int e, int f){
    return ((double) e * 100.0) + (double) f * 50) / (double)(e + f);
}

int main(){
    double x[2];
    int a1,b1,c1,a2,b2,c2; cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    memset(dp,0,sizeof(dp));
    x[0] = 0; x[1] = 0;
    dp[0][a1][a2][b1][b2][c1][c2] = 1.0;
    int sum = a1 + b1 + c1 + c2 + b2 + a2;
    for(int i=1; i<=sum;i++){
        rep(a,a1) rep(b,a1) rep(c,c1) rep(d,c2) rep(e,b1) rep(f,b2){
            if(a+b+c+d+e+f == 0) continue;
            else if(a+b+c+d == 0) x[i%2] += prob(e,f) * DP(i);
            else if(a+b+e+f==0) x[i%2] += prob(c,d) * DP(i);
            else if(c+d+e+f==0) x[i%2] += prob(a,b) * DP(i);
            else if(a+b==0) x[i%2] += max(prob(c,d), prob(e,f)) * DP(i);
            else if(c+d==0) x[i%2] += max(prob(a,b), prob(e,f)) * DP(i);
            else if(e+f==0) x[i%2] += max(prob(c,d), prob(a,b)) * DP(i);
            else x[i%2] += max(prob(a,b) , max(prob(c,d), prob(e,f))) * DP(i);
        }
        rep(a,a1) rep(b,a1) rep(c,c1) rep(d,c2) rep(e,b1) rep(f,b2) DP(i+1) = 0.0;
        rep(a,a1) rep(b,a1) rep(c,c1) rep(d,c2) rep(e,b1) rep(f,b2){
            if(a+b+c+d+e+f == 0) continue;
            else if(a+b+c+d == 0){dp[(i+1)%2][a][b][c][d][e-1][d-1] += prob(e,f) * DP(i%2);}
            else if(a+b+e+f==0)  += prob(c,d) * DP(i%2);
            else if(c+d+e+f==0) x[(i+1)%2] += prob(a,b) * DPe;
            else if(a+b==0) x[(i+1)%2] += max(prob(c,d), prob(e,f)) * DPe;
            else if(c+d==0) x[(i+1)%2] += max(prob(a,b), prob(e,f)) * DPe;
            else if(e+f==0) x[(i+1)%2] += max(prob(c,d), prob(a,b)) * DPe;
            else x[i%2] += max(prob(a,b) , max(prob(c,d), prob(e,f))) * DPe;
        }
    }
    return 0;
}