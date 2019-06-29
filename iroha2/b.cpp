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
    double x, y, a, b,sx,sy,tx,ty; 
    cin >> x >> y;
    cin >> a >> b;
    cin >> sx >> sy;
    cin >> tx >> ty;
    // x * (vary) + (a - b) * (varx) - a * x = 0;
    double p1 = x * sy + (a - b) * sx - a * x;
    double p2 = x * ty + (a - b) * tx - a * x;
    if( p1 * p2 < 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}