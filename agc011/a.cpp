#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int (i)=0;(i) < (n); (i)++)


int main(){
    int n,c,k; cin >> n >> c >> k;
    bool state = false;
    int mt = 0,ans = 0;
    int cc = 0;
    vector<int> tv(n); 
    rep(i,n) cin >> tv[i];
    sort(tv.begin(), tv.end());
    rep(i,n){
        if(state==false){mt = tv[i]; cc = 1; ans++; state=true;}
        else{
            int t = tv[i]; 
            cc++;
            if(c==cc) state=false;
            else if(mt + k == t){
                state = false;
            }
            else if(mt + k < t){
                mt = t;
                cc = 1;
                ans++;
            }
        }
        /*
        cout << "no: " << i+1 << endl;
        cout << " mt:" <<mt << endl;
        cout << " state:" << state << endl;
        cout << " cc:" << cc << endl;   
        */
    }
    cout << ans << endl;
    return 0;
}