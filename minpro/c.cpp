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

long long int tb[18][1 << 18];
vector<int> x(18), c(18), v(18);
bool is_up(int mask, int x){
    return (mask & (1 << x)) == x;
}

long long get_point(int n, int x, int mask){
    long long p = 0, money=0;
    rep(i,n){
        money += is_up(mask, i) ? c[i] : 0;
    }
}
long long max_value[18][1 << 18];

void fill_max_value(int n){
    rep(j,n) rep(i, 1 << n) max_value[j][i] = 0;
    rep(i, n){
        long long money = 0;
        rep(j,i) money += x[j];
        rep(j, 1<<n){
            
        }
    }
}

int main(){
    int n; cin >> n;
    rep(i,n) cin >> x[i];
    rep(i,n) cin >> c[i];
    rep(i,n) cin >> v[i];
    sort(x.begin(), x.end(), greater<long long>());
    rep(i,n){
        rep(j,n){

        }
    }
    return 0;
}