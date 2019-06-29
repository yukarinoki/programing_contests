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
long long int gcd(long long int x,long long int y){
    long long int r;
    if(x == 0 || y == 0)  return 0;

    while((r = x % y) != 0) 
    {
         x = y;
        y = r;
    }
    return y;
}

int main(){
    long long int n,m;
    string s,t; cin >> n >> m >> s >> t;
    if(n==m){
        if(s == t) cout << n << endl;
        else cout << -1 << endl;
        return 0;
    }
    if(n<m){swap(s,t); swap(n,m);}
    ll lcm = (n * m) / gcd(n,m);
    ll gc  = gcd(n,m);
    rep(i,gc){
        if(s[(n / gc) * i] != t[(m / gc) * i]){
            cout << -1 << endl;
            return 0;
        }
    }
    
    if(s[0] == t[0]){ cout << lcm << endl;}
    else cout << -1 << endl;
    return 0;
}