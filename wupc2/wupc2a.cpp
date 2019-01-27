#include <iostream>
using namespace std;
int main(){
  int n,m,a;
  cin >> n;
  cin >> m;
  a = (n * (2*n+1) * (n+1)) / 6;
  a %= m;
  cout << a;
  cout << endl;
  return 0;

}
