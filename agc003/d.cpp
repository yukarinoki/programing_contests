#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

void generate_prime_table(vector<int> &prime){
    for(int i=2;i <= 3000;i++){
        bool c = true;
        rep(j, prime.size()){
            if(i % prime[j] == 0){c = false; break;}
        } 
        if(c) prime.push_back(i);
    }
}


int main(){
    // generate prime table P <= 3000;
    vector<int> prime;
    generate_prime_table(prime);
    // cubic prime table
    vector<ll> cup(prime.size()), sqp(prime.size());
    rep(i,prime.size()) cup[i] = (ll)(prime[i] * prime[i]) * prime[i];
    rep(i,prime.size()) sqp[i] = (ll)(prime[i] * prime[i]);

    int N;
    cin >> N;
    vector<ll> s(N), norm(N),pair(N);
    rep(i,N) cin >> s[i];
    rep(i,N){
        ll normal = s[i];
        rep(j,cup.size()){
            if(normal >= cup[j] && normal % cup[j]==0){
                normal /= cup[j];
                j = -1;
            }
        }
        norm[i] = normal;
    }
    rep(i,N){
        ll pa = 1;
        rep(j,prime.size()){
            if(norm[i] % sqp[j]==0){
                pa *= prime[j];
            }else if(norm[i] % prime[j] == 0){
                pa *= sqp[j];
            }
        }
        pair[i] = pa;
    }
    
   
  
    //rep(i,N) cout << "S : " << s[i] << " Norm : " << norm[i] << " Pair : " << pair[i] << endl;
    
    //ここからの処理を書くのが凄く嫌なので保留します。
    //実は素因数分解も上手くできていない
    vector<bool> used(N);
    int ans=0;
    int i=0;
    
    ans += i;


    cout << ans << endl;
    

    return 0;
}