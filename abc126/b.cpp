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
    int u,d;
    int n; cin >> n;
    u = n / 100;
    d = n - u*100;
    if(u == 0 && d <= 12 && d > 0) cout << "YYMM" << endl;
    else if(u==0) cout << "NA" << endl;
    else if(d == 0 && u <= 12 && u > 0) cout << "MMYY" << endl;
    else if(d == 0) cout << "NA" << endl;
    else if(u <= 12 && d <= 12) cout << "AMBIGUOUS" << endl;
    else if(u <= 12 && u > 0 && d > 12) cout <<  "MMYY" << endl;
    else if(u > 12 && d <= 12 && d > 0) cout << "YYMM" << endl;
    else cout << "NA" << endl;
    return 0;
}