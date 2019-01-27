#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n),b(n),c(n);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<long long> bv(n+1);
    bv[0] = 0;
    for(int i=1;i<n+1;i++){
        auto itr = lower_bound(a.begin(), a.end(), b[i-1]);
        bv[i] = (long long)(itr - a.begin());
    }
    //for(int i=0;i<n+1;i++) cout << bv[i] << " ";
    //cout << endl;
    for(int i=0;i<n;i++){
        bv[i+1] = bv[i] + bv[i+1];
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        auto itr = lower_bound(b.begin(), b.end(), c[i]);
        ans = ans + bv[ (int) (itr - b.begin())];
    }
    cout << ans << endl;
    return 0;
}