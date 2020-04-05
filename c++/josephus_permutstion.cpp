#include <vector>
std::vector < int> josephus(std::vector < int > items, int k) {
  std::vector < int> result;
  unsigned long it = 0;
  while(!items.empty()){
    it = (it + k - 1) % items.size();
    result.push_back(items[it]);
    items.erase(items.begin()+it);
  }
  return result;
}
