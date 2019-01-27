#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> vp(n);
    vector<int> v(n);

    for(int i=0;i<n;i++){
        int sc; cin >> sc;
        vp[i].first = sc; vp[i].second = i;
    }
    sort(vp.begin(),vp.end());
    int c=1;
    v[vp[n-1].second] = 1; c++;
    for(int i=n-2;i>=0;i--){
        if(vp[i].first == vp[i+1].first) v[vp[i].second] = v[vp[i+1].second];
        else v[vp[i].second] = c;
        c++;
    }
    for(int i=0;i<n;i++) cout << v[i] << endl;
    return 0;
}