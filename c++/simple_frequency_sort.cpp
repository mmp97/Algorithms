#include <map>
#include <vector>
#include <algorithm>
std::vector<int> solve(std::vector<int> vec) {
  std::map <int, int> count{};
  for(int& v : vec)
      count[v] = count.find(v) != count.end() ? count[v] + 1 : 0;
  std::sort(vec.begin(), vec.end(), [&](int a, int b){ return (count[a]>count[b]) || (count[a]==count[b] && a < b); });
  return vec;
    }
