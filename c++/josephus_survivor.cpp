#include <vector>
int josephusSurvivor(int n, int k) {
  std::vector <int> soliders;
  int it=0;
  for(int i = 1; i <= n; i++)
    soliders.push_back(i);
  while(soliders.size() > 1){
    it = (it+k-1) % soliders.size();
    soliders.erase(soliders.begin()+it);
  }
  return soliders[0];
}
