#include <string>
#include <vector>

std::vector<std::string> uniq(std::vector<std::string> v) {
  int i = 1;
  while(i < v.size() ){
    if(v[i-1] == v[i])
      v.erase(v.begin()+i);
    else
      i++;
  }
  return v;
}
