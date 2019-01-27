#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > a(n),b(n);
    rep(i,n){int ta,tb; cin >> ta >> tb; a[i]= make_pair(ta,tb);}
    rep(i,n){int tc,td; cin >> tc >> td; b[i]= make_pair(tc,td);}
    sort(ALL(a));
    sort(ALL(b));
    int ans=0;
    rep(i,n){
        int bx = b[i].first, by = b[i].second;
        int id,maxy=-1;
        rep(j,n){
            if(a[j].first < bx && a[j].second < by && a[j].second > maxy){id=j; maxy = a[j].second;}
        }
        if(maxy!=-1){ ans++;
        a[id] = make_pair(400,400);}
    }
    cout << ans << endl;

    return 0;
}