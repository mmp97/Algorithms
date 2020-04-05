#include <math.h>
long long rectangle_rotation(int a_bis, int b_bis)
{
  int a=a_bis/sqrt(2);
  int b=b_bis/sqrt(2);
return 2*a*b+a+b+(a+b-1)%2; 
}
