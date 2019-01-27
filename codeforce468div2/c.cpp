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

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}


int main(){
    int n,tem;
    cin >> n;
    vector<int> w(n); rep(i,n) cin >> w[i];;
    sort(ALL(w));
    int num=0,u,m,l,un,mn,ln;
    num=1; l=w[0];
    int c = l,cn=0;;
    rep(i,n){
        if(c!=w[i]){
            if(num==1){
                ln = cn; cn = 0; m = w[i]; c = m;
            }else if(num==2){
                mn = cn; cn = 0; u = w[i]; c = u;
            }
            num++;
        }
        cn++;
       // cout << "DEBUG" << w[i] << endl;
    }
    if(num==2) mn = cn;
    un = cn;
  //cout << "DEBUG" << num << " " << ln<< " " << mn << " " << un << endl;
    if(num==1){
        cout << n << endl;
        rep(i,n-1) cout << w[i] << " ";
        cout << w[n-1] << endl; 
    }else if(num==2){
        if(m-l==1){
            cout << n << endl;
            rep(i,n-1) cout << w[i] << " ";
            cout << w[n-1] << endl; 
        }else if(m-l==2){
            if(ln >= mn){
                cout << ln -mn << endl;
                rep(i, n-(ln-mn)) cout << l+1 << " ";
                rep(i, (ln-mn)) cout << l << " ";
                cout << endl;
            }else{ // ln <= mn
                swap(ln,mn);
                cout << ln - mn << endl;
                rep(i,n-(ln-mn)) cout << l+1 << " ";
                rep(i, (ln-mn)) cout << m << " ";
                cout << endl;
            }
        }else{cout << "ERROR"; return 0;}
    }else if(num==3){
        if(ln < un){
            swap(&ln,&un);
            swap(&l,&u);
        }

        if(n - (un * 2) < n - ((mn / 2) * 2)){
        cout << n-(un*2) << endl;
        rep(i,(un*2+mn)) cout << m << " ";
        rep(i, ln-un) cout << l << " ";
        cout << endl;
        }else{
        cout << n - ((mn / 2) * 2) << endl;
        rep(i, mn%2) cout << m << " ";
        rep(i, ln+(mn/2)) cout << l << " ";
        rep(i, un+(mn/2)) cout << u << " ";
        cout << endl;
        }
    }else{cout << "ERROR"; return 0;}


    return 0;
}