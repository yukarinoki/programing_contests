#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

int dp[200005];
string p[5000];

class Trie{
    vector<int> base;
    vector<int> check;
    vector<int> code;
    //vector<int> code;
    Trie(vector <int> cd,size){
        base.push_back(1);
        check.push_back(0);
        for(int i=0; i< cd.size();i++) code.push_back(cd[i]);
    }
    Trie(vector<string> vs){
        int n = vs.size() + 5;
        bool flag[n];
        for(int i=0;i<n;i++) flag[i] = false;
        flag[0] = true;
        base.resize(n);
        check.resize(n);
        base[0] = 1;
        check[0] = 0;
    }


}


int main(){
    string s; cin >> s;
    int m; scanf("%d", &m);
    int n = s.length();
    unordered_map<string, int> um;
    vector<string> p(m);
    for(int i=0;i<m;i++)    cin >> p[i];
    for(int i=0;i<m;i++){
        int w;
        scanf("%d", &w);
        um.emplace(p[i],w);
    }
    sort(p.begin(),p.end());
    for(int i=0; i<n; i++) dp[i] = 0;
    for(int i=0; i<n; i++){
        for(int j= max(0, i-200); j<i; j++) dp[i] = max(dp[i],dp[j]);
        for(int j=200; j>0; j--){
            if(i+j <= n && um.find(s.substr(i,j)) != um.end()){
            int w = um[s.substr(i,j)];
            dp[i + j] = max(dp[i+j], w + dp[i]);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=n; i++) ans = max(ans, dp[i]);
   // for(int i=0; i<=n; i++) cout << i << ": " << dp[i] <<endl;
    cout << ans << endl;
    return 0;
}