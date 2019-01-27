#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n; cin >> n;
    string a,b,c; cin >> a >> b >> c;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i] && c[i] == a[i]) ans += 0;
        else if(a[i] == b[i] || c[i] == a[i] || b[i]==c[i]) ans += 1;
        else ans+= 2;
    }
    cout << ans << endl;
    return 0;
}