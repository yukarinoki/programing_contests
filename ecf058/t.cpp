#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t; cin >> t;
    for(int j=0;j < t; j++){
        int n; cin >> n;
        vector<pair<int,int> > vp(n);
        for(int i=0;i<n;i++) cin >> vp[i].second >> vp[i].first;
        sort(vp.begin(), vp.end());
        int ml = vp[n-1].second;
        int cp = -1;
        for(int i=n-2;i>=0;i--){
            if(vp[i].first < ml){cp = i; break;}
            ml = min(vp[i].second, ml);
        }
        if(cp==-1) cout << -1;
        else{
        for(int i=0;i<cp+1;i++) cout << 1 << " ";
        for(int i=0;i<n-cp-1;i++) cout << 2 << " ";
        }
        cout << endl;
    }
    return 0;
}