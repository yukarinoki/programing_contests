#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int n; cin >> n;
    int m; cin >> m;
    int d; cin >> d;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
    sort(v[i].begin(),v[i].end());
    vector<vector<int> > g(n);
    

}