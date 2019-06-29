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
#define MOD 1000000007

typedef long long ll;
long long int tpow[100005];
string s;
long long int func(int st){
    if(st == s.length()) return 1;
    if(s[st]=='1'){
        return (tpow[s.length()-st-1] + 2*func(st+1)) % MOD;
    }else return func(st+1) % MOD;
}

int main(){
    tpow[0] = 1;
    for(int i=1;i<100005;i++) tpow[i] = (3 * tpow[i-1]) % MOD;
    cin >> s;
    long long int ans = 0;
    cout << func(0) << endl;
    return 0;
}