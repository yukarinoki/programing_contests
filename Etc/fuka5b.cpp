#include <cstdio>
#include <vector>
#include <algorithm>
#define sci(n) scanf("%d", &n)

using namespace std;

int main(){
  while(1){
    char s[20], time[20];
    scanf("%s", s);
    if(s[0]=='0') break;

    scanf("%s", time);
    long long int yea, mon, day, hou, min, sec;
    char yea2[6], mon2[3], day2[3], hou2[3], hou2[3], min2[3], sec2[3]; 
      int yea1, mon1, day1, hou1, min1, sec1;
      int read=0;      
      while(1){
	if(s[read]=='/'){yea2[read++]='\0' break;}
	else {
	  yea2[read]=s[read];
	  read++;
	}
      }
      mon2[0]=s[read+1]; mon2[1]=s[read+2]; mon2[2]='\0';
      day2[0]=s[read+2]; day2[1]=s[read+2]; day2[2]='\0';
      hou2[0]=time[0]; hou2[1]=time[1]; hou2[2]='\0';
      min2[0]=time[3]; min2[1]=time[4]; min2[2]='\0';
      sec2[0]=time[6]; sec2[1]=time[7]; sec2[2]='\0';
      yea=atoi(yea2);
      mon=atoi(mon2);day=atoi(day2); hou=atoi(hou2); min=atoi(min2);
      sec= atoi(sec2);
    char one[31]
      scanf("%s", &one);
    int i=0;
    while(one[i]!='\0')
i++
  }
  long long int bi=1, one1=0;
  for(int j=0; j<i;j++){
    one1+=bi;
    bi= 2*bi;
  }
  sec += bi;
  min += sec / 60;
  sec = sec % 60;
  hou += min / 60;
  min = min % 60;
  day = hou / 24;
  hou = hou % 24;
  
  return 0;
}
