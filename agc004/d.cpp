#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

bool c[10005];
int d[10005];

int solve(vector<vector <int> > &t,int n,int k,int now,bool capt,int *ans){
    //首都につながっている場合 capt = ture else capt = false;
    int max=0;
    bool flag = false;
    if(t[now].empty()){
        return 0;
    }else{
        rep(i,t[now].size()){
            int tem = solve(t,n,k,t[now][i],false,ans);
            if(capt){
                if(tem==k){
                    *ans += 1;
                    tem = 0;
                }else flag = true;
            }else{
                if(tem==k-1){
                    *ans += 1;
                    tem = 0;
                }else flag = true;
            }
            if(max < tem) max = tem;
        }
        return flag ? (max + 1) : 0;
    }
}

int main(){
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int>  a(n+1);
    vector<vector <int> > t(n+1);
    rep(i,n) cin >> a[i+1];
    rep(i,10005) c[i] = false;
    if(a[1]!=1){ a[1] = 1; ans++;}
    FOR(i,2,n+1){
        t[a[i]].push_back(i);
    }
    solve(t,n,k,1,true,&ans);
    cout << ans << endl;
    return 0;
}