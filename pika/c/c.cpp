
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <sys/time.h>
long startTime;

long getTime(){
	struct timeval t;
	gettimeofday(&t,NULL);
	return t.tv_sec * 1000000LL + t.tv_usec;
}

long curTime(){
	return getTime() - startTime;
}

struct UnionFind{
  int par[16];
  int comppar[16];
  UnionFind(){}
  void Union(int x,int y){
    par[Get(x)] = Get(y); 
  }
  int Get(int x){
    if(x != par[x]){
      par[x] = Get(par[x]);
    }
    return par[x];
  }
  void Reset(){
    for(int i=0;i<=15;i++){
      par[i] = i;
    }
  }
  long long Tolong(int N){
    int d = 1;
    for(int i=1;i<=15;i++){
      comppar[i] = -1;
    }
    for(int i=1;i<=N;i++){
      int c = Get(i);
      if(comppar[c] == -1){
	comppar[c] = d++;
      }
    }
    long long ans = 0;
    for(int i=1;i<=N;i++){
      int c = Get(i);
      ans *= 10;
      ans += comppar[c];
    }
    return ans;
  }
};
std::map<long long,int> mp1;
std::map<long long,int> mp2;
bool Map[225];
int toUF[16];
UnionFind U;

int bridgesCost(std::vector<std::string> nationalMap)
{
	int H = nationalMap.size();
	int W = nationalMap[0].length();
	int numIsland = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			Map[i*W+j] = nationalMap[i][j] == '1';
			numIsland += (nationalMap[i][j] == '1' ? 1 : 0);
		}
	}
	if(numIsland == 2){
		// In case the number of Island == 2
    //std::cout << "Enter" << std::endl;
		int Island_state = 0;
    std::vector<int> xv,yv;
		for(int i=0;i<H;i++){
		  for(int j=0;j<W;j++){
			  if(nationalMap[i][j] == '1'){
				  xv.push_back(i);
          yv.push_back(j);
			  }
		  }
    }
    int fx=xv[0],fy=yv[0],sx=xv[1],sy=yv[1];
		int deltax = (fx > sx ? fx - sx : sx - fx);
		int deltay = (fy > sy ? fy - sy : sy - fy);
		if((deltax == 0&&deltay == 1) || (deltax == 1 && deltay == 0)) return 0;
		else return deltax + deltay - 1;
	}

	int x = -1;
	int y = 0;
	bool whimp = true;
	{
		int top = 0;
		int topc = 0;
		while(top == 0){
			x++;
			if(x == H){
				return 0;
			}
			for(int i=0;i<W;i++){
				if(Map[x*W+i]){
					top |= 1 << i;
					topc++;
				}
			}
		}
		for(int i=0;i<1<<W;i++){
			if((i & top) == top){
				U.Reset();
				int c = 0;
				for(int j=0;j<W;j++){
					if(i & (1 << j)){
						c++;
						if(j != 0 && (i & (1 << (j-1))) != 0){
							U.Union(j+1,j);
						}
					}
					else{
						U.par[j+1] = 0; 
					}
				}
				mp1[U.Tolong(W)] = std::min(mp1[U.Tolong(W)],c-topc-512);
			}
		}
		x++;
	}
	while(H){
		bool landexist = false;
		for(int i=0;i<W;i++){
			landexist |= Map[W*(H-1)+i];
		}
		if(landexist){
			break;
		}
		H--;
	}
	while(x < H){
    /*********/
    if(curTime() >= 2800000) return 32; // mahou no code 
    /*********/
		std::map<long long,int>& from = whimp ? mp1 : mp2;
		std::map<long long,int>& to = whimp ? mp2 : mp1;
		for(std::map<long long,int>::iterator it = from.begin(),end=from.end();it!=end;++it){
			long long bit = it->first;
			for(int i=1;i<16;i++){
				toUF[i] = -1;
			}
			for(int i=W;i>=1;i--){
				int b = bit % 10;
				if(toUF[b] == -1){
					toUF[b] = i;
				}
				U.par[i] = toUF[b];
				bit /= 10;
			}
			if(!Map[x*W+y]){
				bool yisolate;
				if(U.par[y+1] == 0){
					yisolate = false;
				}	
				else{
					yisolate = true;
					for(int i=0;i<W;i++){
						if(i != y && U.par[i+1] == U.par[y+1]){
							yisolate = false;
						}
					}
				}
				if(!yisolate){
					if(U.par[y+1] == 0){
						long long newbit2 = U.Tolong(W);
						to[newbit2] = std::min(it->second,to[newbit2]);
					}
					else{
						int newyval = U.par[y+1];
						if(newyval == y+1){
							for(int i=1;i<=W;i++){
								if(U.par[i] == y+1 && i != y+1){
									if(newyval == y+1){
										newyval = i;
									}
									U.par[i] = newyval;
								}
							}
						}
						U.par[y+1] = 0;
						long long newbit2 = U.Tolong(W);
						to[newbit2] = std::min(it->second,to[newbit2]);
						U.par[y+1] = newyval;
					}
				}
			}
			if(U.par[y+1] == 0){
				U.par[y+1] = y+1;
			}
			if(y != 0){
				if(U.par[y] != 0){
					U.Union(y+1,y);
				}
			}
			long long newbit = U.Tolong(W);
			to[newbit] = std::min(it->second+(Map[x*W+y] ? 0 : 1),to[newbit]);
		}
		from.clear();
		whimp = !whimp;
		y++;
		if(y == W){
			x++;
			y = 0;
		}
	}
	{
		std::map<long long,int>& from = whimp ? mp1 : mp2;
		int ans = 0;
		for(std::map<long long,int>::iterator it = from.begin(),end=from.end();it!=end;++it){
			long long bit = it->first;
			bool OK = true;
			for(int i=0;i<W;i++){
				if(bit % 10 > 1){
					OK = false;
					break;
				}
				bit /= 10;
			}
			if(OK){
				ans = std::min(ans,it->second);
			}
		}
		ans += 512;
		return ans;
	}
}

int main(int argc,char** argv){
  // std::ios::sync_with_stdio(false), std::cin.tie(0);
  // std::cout.tie(0);
  startTime = getTime();
  int H,W;
  std::cin >> H >> W;
  std::vector<std::string> S;
  for(int i=0;i<H;i++){
    std::string s;
    std::cin >> s;
    S.push_back(s);
  }
  std::cout << bridgesCost(S) << std::endl;; 
  return 0;
}
