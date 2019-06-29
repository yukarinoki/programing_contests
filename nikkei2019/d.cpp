#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    int e = n-1+m;
    
    vector<bool> vb(n);
    vector<int> s(n);
    vector<vector<int> > g(n);
    for(int i=0;i<n;i++) vb[i] = false;
    /*
    vector<pair<int,int> > ch(n);
    for(int i=0;i<n;i++){ch[i].first = 1000000; ch[i].second = -1;}
    */
    
    for(int i=0;i<e;i++){
        int a,b;
        cin >>  a >> b;
        g[a-1].push_back(b-1);
        vb[b-1] = true;
    }
    int root;
    for(int i=0;i<n;i++){
        if(!vb[i]){root = i; break;}
    }

    queue<pair<int,int>> q;
    s[root] = 0;
    for(auto x: g[root]){
                s[x] = root+1;
                q.push(make_pair(x, s[x]));
    }
    while(!q.empty()){
        int idx = q.front().first;
        int oya = q.front().second;
        q.pop();
        if(s[idx] == oya){
            for(auto x: g[idx]){
                    s[x] = idx+1;
                    q.push(make_pair(x, s[x]));
                
         }
        }
    }
    for(auto x: s) cout << x << endl;
    return 0;
}
