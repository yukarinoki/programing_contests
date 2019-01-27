#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>


#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b));

using namespace std;

int ct[5][1005];

bool check(int mid,int r,int b,int c){
    vector<pair<int,int> > num(c);
    int sum=0;
    rep(i,c){
        if(mid - ct[2][i] - ct[1][i] < 0){ num[i]= mp(0,i);}
        else{
            int tem =  (mid - ct[2][i]) / ct[1][i];
            int tem1 = ct[0][i] < tem ? ct[0][i] : tem;
            num[i] = mp(tem1, i);
        }
        sum += num[i].first;
    }
  //  cout << "syutu : " << sum <<": mid=" << mid << ": b =" << b << endl;
    if(sum < b) return false;
    sort(num.begin(), num.end(), greater<pair<int, int> >());
    bool bo = false;
    int sums=0;
    rep(i,r){
        if(num[i].first==0) break;
        sums += num[i].first;
        if(sums >= b){bo = true;}
    }
//    if(bo) cout << "true" << endl;
    return bo;
}



int main(){
    int t;
    cin >> t;
    rep(k,t){
        int r,b,c;
        cin >> r >> b >> c;

        rep(i,c){
            cin >> ct[0][i] >> ct[1][i] >> ct[2][i];
        }
        int ng = 0, ok = 10000000;
        while(ok - ng > 1){
            int mid = (ok+ng) / 2;
            if(check(mid,r,b,c))
            {
                ok = mid;
            }
            else{
                ng = mid;
            }
        }

        printf("Case #%d: %d\n", k+1, ok);

    }
    return 0;
}