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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int a=0,b=0,ab=0;
    rep(i,n){
        if(s[i][s[i].length()-1] == 'A' && s[i][0] =='B') ab++;
        else if(s[i][0] =='B') b++;
        else if(s[i][s[i].length()-1] == 'A') a++;
    }
    int c=0;
    rep(i,n){
        rep(j,s[i].length()-1) if(s[i][j]=='A' && s[i][j+1]=='B') c++;
    }
    int pl = (ab > 0 ? ab-1 : 0);
    if(ab > 0 && a > 0){pl++; a--;}
    if(ab > 0 && b > 0){pl++; b--;}
    pl += min(a,b);
    //cout << b << endl;
    cout << c + pl << endl;
    return 0;
}