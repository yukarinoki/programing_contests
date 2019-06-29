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

int main(){
    long long int ans = 0;
    long long int n; cin >> n;
    if(n==1 || n==2){cout << 0 << endl; return 0;}
    for(long long int i = 0; n >= (i * i); i++){
        if(n % (i+1) == 0){
            long long int t = (n / (i+1) )-1;
            if( n / t == (n % t)) ans = ans + t;
            if(i != 0 &&  n / i == (n % i)) ans = ans + i;
        }
    }
    cout << ans << endl;
    return 0;
}