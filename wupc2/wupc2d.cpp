#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;

int pre(ll n1,ll n2,ll n3,ll n4,ll n5){
  ll N[6]={0};

  N[1]=n1;
  N[2]=n2;
  N[3]=n3;
  N[4]=n4;
  N[5]=n5;

  //5のオブジェクトの個数だけコンテナが必要
  ll ans=N[5];
  //4のオブジェクト1個に付き1個のコンテナが必要
  //1個のコンテナに付き61個分(5^3-4^3)のスペースができ
  //1*1*1のキューブを目一杯入れる
  ans=ans+N[4];
  N[1]=max(N[1]-(61*N[4]),(ll)0);

  //3のオブジェクト1個に付き1個のコンテナが必要
  ll s3=N[3];
  ans=ans+N[3];
  if(N[3]>0){
    //3のオブジェクトを入れた後コンテナには2のオブジェクトが7個入る
    //k :=キューブを入れた後に出来るスペースの個数
    //k個分スペースができるのでそこに1のオブジェクトを目一杯入れる
    ll k=min(7*N[3],N[2]);
    N[2]=max(N[2]-(N[3]*7),(ll)0);
    k=(pow(5,3)-pow(3,3))*N[3]-pow(2,3)*k;
    N[1]=max(N[1]-k,(ll)0);
  }

  if(N[2]>0){
    //1個のコンテナに2のオブジェクトが8個入る
    ll s2=N[2]/8;
    if(N[2]%8>0){
      s2++;
    }

    //k :=キューブを入れた後に出来るスペースの個数
    //k個分スペースができるのでそこに1のオブジェクトを入れる
    ll k=(pow(5,3)*s2-pow(2,3)*N[2]);
    N[1]=max(N[1]-k,(ll)0);
    ans=ans+s2;
  }
  //1個のコンテナには1のオブジェクトが125個入る
  if(N[1]>0){
    ans=ans+N[1]/125;
    if(N[1]%125!=0){
      ans++;
    }
  }

  return ans;
}

int main(){
  // ll n1,n2,n3,n4,n5,ans=0;
  //cin >> n1 >> n2 >> n3 >> n4 >> n5;
  rep(n1a,50){
    rep(n2a,50){
      rep(n3a,50){
	rep(n4a,1){
	  rep(n5a,1){
	    ll ans =0;
	    ll an = pre(n1a,n2a,n3a,n4a,n5a);
	 int n1 = n1a;
	 int n2=n2a;
	 int n3=n3a;
	 int n4=n4a;
	 int n5=n5a;
  ans += n5;
  ans += n4;
  n1 -= n4*(125-64);
  if(n1<0) n1 = 0;
  ans += n3;
  // cout << ans;
  ll t = n3*7;
  ll quo,sub;
  if(n2<t){quo=n2/7; sub=n2%7; n2 -= t; n1 -= ((quo*(125-27-56))+(125-27-8*sub)+(n3-quo-1)*(125-27));}
    else {n2 -= n3*7; n1 -= n3*(125-27-56);}
  //cout << ans;
  if(n2<0) n2=0;
  if(n1<0) n1=0;
  if(!(n2==0&&n1==0)){ 
  ans += n2/8;
  //cout << ans;
  n1 -= (n2/8)*(125-64);
  if(n1<0)n1=0;
  if(n2%8>0){
    ans++;
    n1 -= ((125-(8*(n2%8))));
  if(n1<0)n1=0;
  }
  ans += n1 / 125;
  if(n1%125 != 0)ans++;
  }
  if(ans != an) cout<<n1a <<","<<n2a<<","<<n3a<<","<<n4a<<","<<n5a<<"\n";
  cout << ".";
	  }}}}}
 
  return 0;
}
