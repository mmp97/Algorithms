#include <vector>

class PrimeDecomp
{
public:
  static std::string factors(int lst);
};

std::string PrimeDecomp::factors(int lst){
  std::string result;
  for(int i = 2; lst>1; i++){
    int k = 0;
  while(lst % i == 0){
    lst = lst/i;
    k++;
  }
  if(k == 1)
    result += "(" + std::to_string(i) + ")"; 
  else if(k > 1)
    result += "(" + std::to_string(i) + "**" + std::to_string(k) + ")"; 
  }
  return result;
}
