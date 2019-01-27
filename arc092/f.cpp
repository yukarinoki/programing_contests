#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<vector<pair<int,int> > > graph;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

bool dfs_condition_1(graph &g,vector<bool> &check,int now,int dest){
    if(now==dest) return true;
    check[now-1] = true;
    //cout << now << endl;
    rep(i,g[now-1].size()){
        if(!check[g[now-1][i].second-1]){ 
            if(dfs_condition_1(g, check,g[now-1][i].second,dest)) return true;
        }
    }
    return false;
}

void dfs_condition_2(graph &g,vector<int> &check,int num, int now,int a){

    if(check[now-1]==-1) check[now-1] = num;
          
    rep(i,g[now-1].size()){
        if(g[now-1][i].second!=a && check[g[now-1][i].second-1]==-1) dfs_condition_2(g, check, num, g[now-1][i].second, a);

    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<pair<int,int>, int> > e(m);
    rep(i,m){
        int a,b; 
        cin >> a; 
        cin >> b; 
        e[i] = make_pair(make_pair(a,b), i);
    }
    graph g(n);
    sort(ALL(e));
    int j=0;
    rep(i,n){
        while(j<m && e[j].first.first==i+1){
            g[i].push_back(e[j].first);
            j++;
        }
    }
   
    vector<bool> cf(m), cs(m);
     
    rep(i,m){
        vector<bool> check(n);
        cf[e[i].second] = dfs_condition_1(g, check, e[i].first.second, e[i].first.first);
    } 
 
    rep(i,n){
        vector<int> cmax(n),cmin(n);
        rep(k,n){cmax[k]=-1; cmin[k]=-1;}
        rep(k,g[i].size()){
            dfs_condition_2(g, cmin, k, g[i][k].second, i+1);
        }

        rep(k,g[i].size()){
            dfs_condition_2(g, cmax, g[i].size() - k - 1, g[i][g[i].size() - k - 1].second, i+1);
        }
        //rep(k,n) cout << cmax[k] << endl;
        pair<pair<int,int>, int> pp = make_pair(make_pair(i + 1, 0), 0);
        vector<pair<pair<int,int>, int> >::iterator itr = lower_bound(e.begin(), e.end(), pp);
        rep(k,g[i].size()){
           if(cmax[g[i][k].second-1]==k && cmin[g[i][k].second-1]==k) cs[(*itr++).second]=true;
        }

    }
    //rep(i,m) if(cf[i]) cout << i+1 << ": cf true" << endl;
    //rep(i,m) if(cs[i]) cout << i+1 << ": cs true" << endl;
    rep(i,m){
        if((cf[i]||cs[i])&&!(cf[i]&&cs[i])) cout << "same" << endl;
        else cout << "diff" << endl;

    }
    return 0;
}
