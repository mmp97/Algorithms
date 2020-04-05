#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) 
{
if(snail_map[0].empty())
  return {};
std::vector<int> result = snail_map[0];
int n = snail_map[0].size();
int x = n-1;
int y = 0;
int a = 1;
while (n-1>0){
  for(int i = 0;i<n-1;i++){
    y=y+a;
    result.push_back(snail_map[y][x]);
    }
  a=-a;
  for(int i = 0;i<n-1;i++){
    x=x+a;
    result.push_back(snail_map[y][x]);
    }
  n--;
}
return result;
}
