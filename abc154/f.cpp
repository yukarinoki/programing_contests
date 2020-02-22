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
#include <cstdint>
#include <cctype>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))
#define MOD 1000000007;

typedef long long ll;



template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

using mint = modint<1000000007>;

int main() {
    int r1,r2,c1,c2; cin >> r1 >> c1 >> r2 >> c2;
    vector<mint> fact(2000005);
    fact[0] = 1;
    for (int i = 1; i < fact.size(); ++i) {
        fact[i] = fact[i - 1] * i;
    }
    const auto comb = [&fact](int n, int r) {
        return fact[n] / fact[r] / fact[n - r];
    };
    mint ans=0, aa=0,bb=0,cc=0,dd=0;
    int c = c2, r = r2;
    for(int i=0;i<=c;i++){
        aa += mint(r+1) * comb(i+r+1,r+1) / mint(i+1);   
    }
    c = c1-1, r = r2;
    for(int i=0;i<=c;i++){
        bb += mint(r+1) * comb(i+r+1,r+1) / mint(i+1);   
    }
    c = c2, r = r1-1;
    for(int i=0;i<=c;i++){
        cc += mint(r+1) * comb(i+r+1,r+1) / mint(i+1);
    }
    c = c1-1, r = r1-1;
    for(int i=0;i<=c;i++){
        dd += mint(r+1) * comb(i+r+1,r+1) / mint(i+1);   
    }
    
    cout << (aa-bb-cc+dd).a << endl;
    return 0;
}
