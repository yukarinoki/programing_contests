#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    int n; cin >> n;
    int bn = n / 2;
    vector<long long int> b(bn);
    vector<long long int> a(n);
    for(int i=0;i<bn;i++) cin >> b[i];
    for(int i=0;i<n;i++) a[i] = 0;
    a[0] = 0; a[n-1] = b[0];
    for(int i=1;i<bn;i++){
        long long int tb = a[i-1];
        if(a[n-i] >= b[i] - tb){
            a[i] = tb;
            a[n-i-1] = b[i] - tb;
        }else{
            tb = b[i] - a[n-i];
            a[i] = tb;
            a[n-i-1] = a[n-i];
        }
    }

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}