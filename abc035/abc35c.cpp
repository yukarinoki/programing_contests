#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define deb(x) printf("deb:%d\n", x)

int main(){
  int n,q;
  scanf("%d%d", &n,&q);
  vector<int> l(q),r(q);
for(int i=0;i<q;i++){
  scanf("%d%d", &l[i],&r[i]);
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  int e=0,rr=0,rl=0;
  for(int i=1;i<n+1;i++){
    while(rl<q&&l[rl]==i){e++; rl++;}
    printf("%d" ,(e%2));
    while(rr<q&&r[rr]==i){e--; rr++;}
   
}
  printf("\n");
  return 0;
}

