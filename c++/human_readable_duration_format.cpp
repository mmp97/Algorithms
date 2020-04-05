#include <string>
#include <math.h>
#include <string>
#include <vector>

std::string format_duration(int seconds) {
if (seconds == 0)
return "now";
std::string result = "";
std::vector<int> dividers = {60,24,365,365};
std::vector<std::string> periods ={" second"," minute"," hour"," day"," year"};
std::vector<int> mod ={};
int quotient = floor(seconds/60);  mod.push_back(seconds%60);
int notzero = 0;
if(seconds%60!=0)
  notzero++;
int step = 0;
while (quotient != 0){
  mod.push_back(quotient%dividers[step]);
  if(quotient%dividers[step]!=0)
  notzero++;
  quotient=floor(quotient/dividers[step]);
  step++;
}
for(int i=mod.size()-1;i>=0;i--){
  if(mod[i]!=0){
    notzero--;
    std::string s = std::to_string(mod[i]);
    s+=periods[i];
    if(mod[i]>1)
    s+="s";
    if (notzero == 1 && mod.size()>1)
    s+=" and ";
    else if(i>1)
    s+=", ";
    result+=s;
    }
}
return result;
}
