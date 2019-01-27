#include <cstdio>

typedef long long int ll;
int main(){
  int s = 43;
  ll m = 1;
 ll n = 1;
 n = 1<<s;
 m = m<<s;
 printf("%lld,%lld", n, m);
 return 0;
}
