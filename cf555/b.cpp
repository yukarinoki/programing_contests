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
    vector<int> v(9); rep(i,9) cin >> v[i];
    int pos = -1;
    for(int i=0;i<n;i++){
        if(v[s[i]-'1'] > s[i]-'1'+1){pos = i; break;}
    }
    if(pos == -1){cout << s << endl; return 0;}
    //cout << pos << endl;
    while(pos < n && v[s[pos]-'1'] >= s[pos]-'1'+1){s[pos] = (char)(v[s[pos]-'1'] + '0'); pos++; }
    cout << s << endl;
    return 0;
}