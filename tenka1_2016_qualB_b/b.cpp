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
    string s;
    cin >> s;
    int rp = 0,head = 0, ans = 0;
    rep(i, s.length()){
        switch(s[i]){
            case '(':
            if(rp==0){
                rp++;
            }else{
                bool lf=false, valid=true;; int rc=rp;
                for(int j=i+1; j<s.length(); j++){
                    if(lf){
                        if(s[])
                        if(rc==0){ valid = false; break;}
                        
                    }
                    else{
                        if(s[j]=='(') rc++;
                        else if(s[j]==')'){lf = true; rc--} 
                    }
                }
            }
            break;

            case ')':
            if(rp==0){
                ans += i - head;
                head = i;
                ans++;
                rp++;
            }else{
                rp--;
            }
            break;
        }

    }

    cout << ans << endl;
    return 0;
}