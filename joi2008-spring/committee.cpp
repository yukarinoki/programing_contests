#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans = -100000005;

int subtree_max(int node, vector<int> &a, vector<vector<int>> &g){
    int pos_sum = 0;
    if(g[node].size() == 0){
        ans = max(a[node], ans);
        return a[node];
    }
    for(auto x: g[node]){
        int tem = subtree_max(x, a, g);
        pos_sum += tem > 0 ? tem : 0;
    }
    ans = max(a[node] + pos_sum, ans);
    return a[node]+pos_sum;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int> > g(n);
    int leader_id;
    for(int i=0;i<n;i++){
        int s, ai; cin >> s >> a[i];
        if(0 == s) leader_id = i;
        else g[s-1].push_back(i);
    }
    subtree_max(leader_id, a, g);
    cout << ans << endl;
    return 0;
}