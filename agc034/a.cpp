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
    int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
    string s; cin >> s;
    for(int i=a-1; i<=c-2;i++){
        if(s[i]=='#' && s[i+1] == '#'){
        cout << "No" << endl;
        return 0;
        }
    }
    for(int i=b-1; i<=d-2;i++){
        if(s[i]=='#' && s[i+1] == '#'){
        cout << "No" << endl;
        return 0;
        }
    }
    if(c < d){
        cout << "Yes" << endl;
        return 0;
    }else{
        for(int i=b-1; i <= d-1;i++){
            if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    assert(0);
    return 0;
}