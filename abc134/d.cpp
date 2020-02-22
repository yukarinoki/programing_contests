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
    vector<int> a(n); rep(i,n) cin >> a[i];
    vector<int> r(n);
    for(int i= (n/2); i < n; i++) r[i] = a[i];
    for(int i = (n/2)-1; i>=0; i--){
        int num = i+1;
        int pr = num-1;
        pr += num;
        int sum = 0;
        while(pr < n){sum +=a[pr]; pr += num;} 
        r[i] = (sum + a[i]) % 2;
    }
    int summ = 0;
    rep(i,n) summ += r[i];
    cout << summ << endl;
    rep(i,n) if(r[i]==1) cout << i+1 << endl;
    
    return 0;
}