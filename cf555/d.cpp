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
    long long int n,k; cin >> n >> k;
    long long int nn = n - ((k+1) * k) / 2;
    if(nn < 0){
        cout << "NO" << endl;
        return 0;
    }
    long long int d = nn / k;

    vector<long long int> ans(k);
    rep(i,k) ans[i] = nn / k;
    rep(i, nn % k) ans[k-i-1] += 1;
    rep(i,k) ans[i] = ans[i] + i + 1;
    
    if(nn!=k-1 || k==1){
        cout << "YES" << endl;
        rep(i,k) cout << ans[i] << " ";
        cout << endl;
        return 0;
    }else if(ans[0]==1 && ans[1] == 3){
        if(k==2 || k==3){
            cout << "NO" << endl;
            return 0;
        }else{
            ans[1]--;
            ans[k-1]++;
            cout << "YES" << endl;
            rep(i,k) cout << ans[i] << " ";
            cout << endl;
            return 0;
        }
    }
    return 0;
}