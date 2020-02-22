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

ll comb(int num, int rnum){
    ll ans = 1;
    if(num>rnum){
        for(int i=num;i>=num-rnum+1; i--){ans = i * ans; ans = ans / (num-i+1);}
    }
    return ans;
}

int main(){
    int n,a,b; cin >> n >> a >> b;
    vector<long long int> v(n); rep(i,n) cin >> v[i];
    sort(v.begin(), v.end(), greater<long long int>());
    long long int suma = 0; for(int i=0;i<a;i++) suma += v[i];
    double ansd = (double)suma / (double)a;
    bool same = true;
    rep(i,a+1) if(v[i]!=v[0]) same = false;
    if(same){
        int r = a-1;
        while(r<n&&v[r]==v[a-1]) r++;
        if(v[r]!=v[a-1]) r--;
        long long int ans = 0;
        for(int i=a-1;i<=min(r,b-1);i++) ans = ans + comb(r+1, i+1);
        printf("%.10lf\n", ansd);
        cout << ans << endl;   
    }else {
        int l = a-1, r = a-1;
        while(0<=l&&v[l]==v[a-1]) l--;
        if(v[l]!=v[a-1]) l++;
        while(r<n&&v[r]==v[a-1]) r++;
        if(v[r]!=v[a-1]) r--;
        //long long int comb = 1;
        int num = r-l+1;
        int rnum = a-1-l+1;
        
        printf("%.10lf\n", ansd);
        cout << comb(num,rnum) << endl;   
    }
    
    return 0;
}