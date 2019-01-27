#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int x,y; cin >> x >> y;
    int ans = 0;
    for(int i=x;i<=y;i++){
        int c = 0;
        for(int j=0; i - j*j > 0; j++){
            int n = i - j*j;
            int m = sqrt(n);
            if ( m*m == n ) c++;
        }
        ans = max(ans, 4*c);
    }
    cout << ans << endl;
    return 0;
}