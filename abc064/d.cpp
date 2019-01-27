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
#define DEBUGM(d,n,m,i,j) printf("DEBUGM :\n"); rep(i,n){ rep(j,m) if(inf==d[i][j]) printf("inf "); else printf("%d ", d[i][j]); printf("\n");} printf("DEBUGM END LINE\n")

typedef long long ll;

const ll INF =1LL << 62;
const int inf =1 << 29;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int lc=0,rc=0;
    rep(i,n){
        if(s[i] == '('){
            lc++;
        }else if(s[i] == ')'){
            if(lc>0) lc--;
            else rc++;
        }
    }
    rep(i,rc) putchar('(');
    cout << s;
    rep(i,lc) putchar(')');
    putchar('\n');
    
    return 0;
}