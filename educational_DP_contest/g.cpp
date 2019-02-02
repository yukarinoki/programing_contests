#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<int> sorted;
int topological_sort(vector<vector<int> > &dag){
    int n = dag.size();
    vector<int> in_degree(n);
    for(int i=0;i<n;i++){
        for(auto x: dag[i]){
            in_degree[x]++;
        }
    }
    queue<int> node_set;
    for(int i=0;i<n;i++){
        if(in_degree[i] == 0){
            node_set.push(i);
        }
    }
    while(!node_set.empty()){
        int node = node_set.front();
        node_set.pop();
        sorted.push_back(node);
        for(auto x: dag[node]){
            in_degree[x]--;
            if(in_degree[x] == 0) node_set.push(x);
    }
    }
    return 0;
}

int dp[100005];
int main(){
    rep(i,100005) dp[i] = 0;
    int n, m; cin >> n >> m;
    vector<vector <int> > g(n);
    vector<int> in_degree(n);
    rep(i,m){
        int fr,to; cin >> fr >> to;
        g[fr-1].push_back(to-1);
        in_degree[to-1]++;
    }
    topological_sort(g);
    rep(i,n){
        int idx = sorted[i];
        for(auto x: g[idx]){
            dp[x] = max(dp[x], dp[idx]+1);
        }
    }
    int ans = 0;
    rep(i,n) ans = max(ans, dp[i]);
    cout << ans << endl;
}
