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

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int all_non_plus=1;
    rep(i,n) if(a[i]>0) all_non_plus=0;
    if(all_non_plus){
        // all of a_n are 0 or minus
        ll max=a[0],max_id=0;
        rep(i,n){
            if(max < a[i]){max = a[i]; max_id=i;}
        }
        cout << max << endl;
        cout << n-1 << endl;
        rep(i,n - max_id - 1) cout << n - i << endl;
        rep(i,max_id) cout << 1 << endl;
    }else{
        ll e_sum=0;
        ll o_sum=0;
        rep(i,n) if(((i + 1) % 2 == 0) &&(a[i] > 0)) e_sum += a[i];
        rep(i,n) if(((i + 1) % 2 == 1) &&(a[i] > 0)) o_sum += a[i];
        vector<pair<ll,ll> > v(n);
        vector<ll> ord;
        if(e_sum > o_sum){
            rep(i,n){ 
                if(((i + 1) % 2 == 0) &&(a[i] > 0)){
                    v[i] = make_pair(a[i], 1);
                }else{
                    v[i] = make_pair(a[i], 0);
                }
            }
            cout << e_sum << endl;    
        }else{
            rep(i,n){ 
                if(((i + 1) % 2 == 1) &&(a[i] > 0)){
                    v[i] = make_pair(a[i], 1); 
                }else{
                    v[i] = make_pair(a[i], 0); 
                }
            }
            cout << o_sum << endl;
        }

        while(v.size()!=1){
                rep(j,v.size()){
                    if(j==0&&v[j].second==0){
                        v.erase(v.begin()+j);               
                        ord.push_back(j+1);
                        break;
                    }else if(j>0&&j<v.size()-1&&v[j+1].second==1&&v[j-1].second==1){
                        v[j]= make_pair(v[j+1].first+v[j-1].first,1);
                        v.erase(v.begin()+j-1);
                        v.erase(v.begin()+j);                 
                        ord.push_back(j+1);
                        break;
                    }else if(j>0&&j<v.size()-1&&v[j+1].second==0&&v[j-1].second==0){
                        v[j]= make_pair(v[j+1].first+v[j-1].first,0);
                        v.erase(v.begin()+j-1);
                        v.erase(v.begin()+j);                    
                        ord.push_back(j+1);
                        break;
                    }else if(j==v.size()-1&&v[j].second==0){
                        v.erase(v.begin()+j);
                        ord.push_back(j+1);
                        break;
                    }
                }
            }
        cout << ord.size() << endl;
        rep(i,ord.size()) cout << ord[i] << endl;
     
    }
    return 0;
}