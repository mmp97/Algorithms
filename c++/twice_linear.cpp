#include <math.h>
#include <algorithm>
#include <vector>
class DoubleLinear
{
public:
    static int dblLinear(int n);
};
 int DoubleLinear::dblLinear(int n){ 
  int* vec = new int[n+1];
  vec[0]=1;
  int nx = 0, ny = 0, index_x = 0, index_y = 0;
  for(int i = 0; i < n ;i++){
    nx = 2*vec[index_x]+1;
    ny = 3*vec[index_y]+1;
    if(nx <= ny){
      vec[i+1]=nx;
      index_x++;
    if(nx == ny)
      index_y++;
    }
    else{
      vec[i+1]=ny;
      index_y++;
    }
  }
  return vec[n];
 }
