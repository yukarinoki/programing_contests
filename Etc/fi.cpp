#include <iostream>
#include <sstream>
#include <istream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  // start from 1 to ignore script name; argv[0] will be a name of processing file.
  /*
  for (int i = 1; i < argc; i++) {
    printf ("argv[%i]: %s\n", i, argv[i]);
  }
  */
  int div = atoi(argv[argc-1]);
  vector<pair<int,string>> v;
  for(int i= 1; i<argc-1; i++){
    string s(argv[i]);
    string separator = string(":");
    auto separator_length = separator.length(); // 区切り文字の長さ
    auto offset = string::size_type(0);
    auto pos = s.find(separator, offset);
    string buf1 = "",buf2 = "";
    //cout << s << endl;
    buf1 = s.substr(offset, pos - offset);
    offset = pos + separator_length;
    buf2 = s.substr(offset);
    int num = atoi(buf1.c_str());
    v.push_back(make_pair(num, buf2));
  }
  sort(v.begin(),v.end());
  bool flag = false;
  for(int i=0;i<v.size();i++){
    if(div % v[i].first == 0){ cout << v[i].second; flag = true;}
  }
  if(!flag) cout << div << endl;
  else cout << endl;
  return 0;
}
