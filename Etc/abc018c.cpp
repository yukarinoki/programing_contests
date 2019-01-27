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
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long int ll

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int n = z+x+y;
    vector<int> a,b,c;
    ll sum_c = 0;
    rep(i,n){
        int aa,bb,cc;
        cin >> aa >> bb >> cc;
        a.push_back(aa-cc);
        b.push_back(bb-cc);
        sum_c += cc;
    }
    vector< pair<ll,ll> > v;  
    rep(i,n){
        v.push_back(mp(a[i]-b[i],i));
    }
    sort(all(v));
    ll max=0;
    for(int i=y,i=<y+z;i++){
        ll i_max=0;
        //プライオリティキューで入れていく
        priority_queue<int, vector<int>, greater<int>> xq,yq;
        rep(j,i){
            yq.push(v[j]);
            if(yq.size() > y) yq.pop();
        }
        rep(j,n-i){
            xq.push(v[n-1-j]);
            if(xq.size() > x) xq.pop();
        }
        rep(i,x){
            i_max += xq.top();
            xq.pop();
        }
        rep(i,y){
            i_max += yq.top();
            yq.pop();
        }
        if(max < i_max) max = i_max;
    }
    cout << max + sum_c << endl;
    return 0;
}