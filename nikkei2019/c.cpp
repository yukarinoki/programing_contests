#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long long int> a(n), b(n);
    vector<pair<pair<int,int>, int> > c(n);
    for(int i=0;i<n;i++) {
        cin >> a[i] >> b[i];
        c[i].first.first = -(a[i] + b[i]);
        c[i].first.second = a[i];
        c[i].second = i;
    }
    sort(c.begin(),c.end());
    long long int tk=0,ao=0;
    for(int i=0;i < n; i++){
        if(i % 2 == 0) tk += a[c[i].second]; 
        else ao += b[c[i].second];
    }
    cout << tk - ao << endl;
    return 0;
}