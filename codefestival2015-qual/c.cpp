#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


int main(){
    long long int t;
  int n;
    cin >> n >> t;
    vector<int> a(n), b(n);
  	vector<pair<int, int> > c(n);
  long long int sum=0;
  for(int i=0;i<n;i++){ 
    cin >> a[i] >> b[i];
    c[i].first = a[i] - b[i];
    c[i].second = i;
    sum = sum + a[i];
  }
  sort(c.begin(),c.end());
  int ans = 0;
  for(int i=n-1;i>=0;i--){
  	if(sum <= t) break; 
    sum -= c[i].first;
    ans++;
  }
  if(sum <= t) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}
