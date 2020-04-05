#include <string>
#include <math.h>
class Dec2Fact
{
public:
  static std::string dec2FactString(long long nb){
  long long temp = nb , i = 1;
  int cnt = 1;
  std::string res;
  while(i < temp){
    i = i * (cnt + 1);
    cnt++;
  }
  i /= cnt;
  cnt--;
  while(cnt > 0){
    int fact=floor(temp/i);
    temp -= (fact*i);
    if(fact < 10)
      res.push_back(fact + 48);
    else
      res.push_back(fact + 55);
    i /= cnt;
    cnt--;
  }
  res.push_back('0');
  return res;
  }
  
  static long long factString2Dec(const std::string &str){
  long long sum = 0 , cnt = 1;
  for(int i = 1;i<str.length();i++){
    cnt = cnt * i;
    if(str[str.length()-1-i] < 58)
      sum += (str[str.length()-1-i] - 48) * cnt;
    else
      sum += (str[str.length()-1-i] - 55) * cnt;
  }
  return sum;
  }
};
