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
    string s; cin >> s;
    int n = s.length();
    long long int ans = 0;
    int bn = 0;
    int c=0;
    for(int i=0;i<n;i++){
        if(s[i] == 'B') bn++;
    }
    for(int i=0;i<n;i++){
        if(s[i] == 'B'){
            ans = ans + (n - bn + c - i);  
            c++;
        }
    }
    cout << ans << endl;
    return 0;
}