#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n,m,c; cin >> n >> m >> c;
    vector<int> a(m);
    for(int i=0;i<m;i++) cin >> a[i];
    vector<vector<pair<int, pair<int,int> > > >  g(n);
    for(int i=0;i<c;i++){
        int f,t,d,s; cin >> f >> t >> d >> s;
        g[f-1].push_back(make_pair(t-1,make_pair(d,s)));
    }
    vector<double> dp(n);
    for(int i=0;i<n;i++) dp[i] = 20000000.0;
    for(int i=0;i<m;i++){
        dp[a[i]-1] = 0.0;
    }
    double left = 0.0, right = 2000000.0;
    while(right - left > 0.001){
        double mid = (left + right) / 2.0;
        
        for(int i=0;i<n;i++) dp[i] = 20000000.0;
        for(int i=0;i<m;i++){
            dp[a[i]-1] = 0.0;
        }
        
        for(int i=0;i<n-1;i++){
            for(auto x: g[i]){
                double di = (double) x.second.first, vi = (double)x.second.second;
                int to = x.first;
                dp[to] = min(dp[to], dp[i] + di * (1.0 - (mid / vi)));
               // cout << dp[i] + di * (1.0 - (mid / vi)) << endl;
            }
        }
        if(dp[n-1] <= 0.0) right = mid;
        else left = mid;
    }
    cout << round(right) << endl;
    return 0;
}