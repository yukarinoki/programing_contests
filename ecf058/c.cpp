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
        vector<pair<pair<int,int>, int> > vp(n);
        for(int i=0;i<n;i++){
            cin >> vp[i].first.first >> vp[i].first.second;
            vp[i].second = i;
        }
        sort(vp.begin(), vp.end());
        int mr = vp[0].first.second;
        int cp = -1;
        for(int i=1;i<n;i++){
            if(mr < vp[i].first.first){cp = i; break;}
            mr = max(mr, vp[i].first.second);
        }
        if(cp==-1) cout << -1;
        else{
        vector<int> v(n);
        for(int i=0;i<cp;i++) v[vp[i].second] = 1;
        for(int i=cp;i<n;i++) v[vp[i].second] = 2;
        for(int i=0;i<n;i++) cout << v[i] << " ";
        }
        
        cout << endl;
    }
    return 0;
}