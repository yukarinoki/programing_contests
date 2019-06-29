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
    string ss; cin >> ss;
    string s;
    for(int i=0;i<ss.length();i++){
        if(ss[i]=='A') s += 'A';
        else if(ss[i]=='B' && i!=s.length()-1 && ss[i+1]=='C'){
            s += 'K';
            i++;
        }else{
            s += 'X';
        }
    }
    //cin >> s;
    int pos = 0;
    long long  ans = 0;
    rep(i, s.length()){
        if(s[i]=='A'||s[i]=='K'){
            long long len = 0;
            while(i!=s.length() && (s[i]=='A'||s[i]=='K')){
                if(s[i]=='A'){len++;}
                else if(s[i]=='K'){ans = ans + len;}
                i++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}