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

typedef vector<vector<pair<int,int> > > graph;
typedef long long ll;

const ll INF =1LL << 62;
const int inf =1 << 29;


int main(){
    int a=0,b=0,c=0,d=0,n,t;
    cin >> n;
    rep(i,n){
        cin >> t;
        switch(t){
            case 1:
            a++;
            break;
            case 2:
            b++;
            break;
            case 3:
            c++;
            break;
            case 4:
            d++;
            break;
        }
    }
    int ans=0;
    ans+=d;
    if(c>0){
        if(a>0){
            if(a>c){
                a -= c; ans+=c;
            }
            else{
                a=0; ans+=c;
            }
        }else{
            ans+=c;
        }
    }

    if(b>0){
        if(b%2==0){
            ans += (b / 2); b=0;
        }else if(b%2==1){
            ans += ((b - 1) / 2);
            if(a>1) a-=2;
            else a=0;
            b=0;
            ans++;
        }
    }

    ans += (a / 4) + (a % 4 == 0 ? 0 : 1);
    cout << ans << endl;
    return 0;
}