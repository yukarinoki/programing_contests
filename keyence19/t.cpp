#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int (i)=0;(i) < (n);(i)++)

vector<vector<long long> > comb(int n, int r) {
vector<vector<long long> > v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main(){
	int n,a,b; cin >> n >> a >> b;
  	vector<long long> v(n); for(int i=0;i<n;i++) cin >> v[i];
  	sort(v.begin(),v.end());
  	long long sum=0;
  	rep(i,a) sum+=v[n-i-1];
	double m = (double) sum / (double)a;
  	cout << m << endl;
  	bool flag = true;
  	
    int c = 0;
      rep(i,n) if(v[i]==v[n-a]) c++;
      vector<vector<long long> > combi = comb(c,b); 
      long long ans=0;
      for(int i=a;i<=b;i++){
      		ans += combi[c][i];
      }
    cout << ans << endl;
    
  return 0;
}