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
#include <tuple>
#include <cassert>
#include <unordered_map>

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

typedef vector<vector<pair<int,int> > > graph;
typedef long long ll;

ll findSubArrays(int arr[], int n)
{

    ll ans=0;
    unordered_map<int, vector<int> > map;
  
    int sum = 0;
  
    for (int i = 0; i < n; i++)
    {
        // add current element to sum
        sum += arr[i];
  
        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if (sum == 0)
            ans++;
  
        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(sum) != map.end())
        {
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                ans++;
        }

        map[sum].push_back(i);
    }
  
    // return output vector
    return ans;
}
    
int a[200005];

int main()
{
    int n;
    scanf("%d", &n);
    rep(i,n){
        scanf("%d", &a[i]);
    }
  
    ll ans = findSubArrays(a, n);
  
    cout << ans << endl;
    return 0;
}
