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
    int n; cin >> n;
    string s; cin >> s;
    int mi = 100000000;
    for(int i=0; i<n-3;i++){
        int t;
        t = min(abs(s[i] - 'A'), 26 - abs(s[i] - 'A'));
        t += min(abs(s[i+1] - 'C'), 26 - abs(s[i+1] - 'C'));
        t += min(abs(s[i+2] - 'T'), 26 - abs(s[i+2] - 'T'));
        t += min(abs(s[i+3] - 'G'), 26 - abs(s[i+3] - 'G'));
        mi = min(t, mi);
    }
    cout << mi << endl;
    return 0;
}