#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class Plusonegame {
public:
  string getorder(string s) {
    int len = s.length();
      int plus,num[10];
      for(int i=0;i<len;i++)
	if(s[i]=='+')plus++;
	else {
	  for(int j=0;j<10;j++){
	    if((j+(int)'0')==s[i]) num[j]++;
	      }
	}
      for(int i=0;i<10;i++) printf("%d ", num[i]);
      
      string ans;
      for(int j=0;j<10;j++){
      for(int i=0;i<num[j];i++){
	ans.push_back((char)(j+'0'));
      }
      if(plus>0){ans.push_back('+'); plus--;}
      }
      for(int i=0;i<plus;i++){ ans.push_back('+');}
      return s;
  }
};
