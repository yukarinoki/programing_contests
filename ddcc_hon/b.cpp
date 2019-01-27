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

typedef long long ll;

int main(){
    int n,k;
    long long int r; cin >> n >> k >> r;
    //long long thesum = 0;
   // for(int i=1;i <= n-k;i++) thesum += n - k - i + 1 > 0 ? n-k-i+1 : 0;
    //if(r > thesum){cout << "No Luck" << endl; return 0;}
    vector<int> v(n);
    int lp = 0,rp = n-1;
    for(int i=n;i>=1;i--){
        if(i-k > 0 && r >= i-k){
            r = r - (i-k);
            v[lp++] = i;
        }else{
            v[rp--] = i;
        }
       // cout << i << ":" << r << endl;
    }
    if(r != 0){cout << "No Luck" << endl; return 0;}
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}