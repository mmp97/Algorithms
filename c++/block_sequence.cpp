#include <string>
int solve(long long n)
{
  long long sum = 0, size = 0, inc = 1, step = 9, cnt = 0;
  while (sum < n){
    size += inc;
    sum += size;
    cnt++;
    if (cnt == step){
      inc++;
      step = 10 * step + 9;
    }
  }
  long long temp = n - sum + size;
  inc = 1, step = 9, sum = 0, cnt = 0, size = 0;
  while (size < temp){
    if (cnt == step){
      inc++;
      step = 10 * step + 9;
    }
    size += inc;
    cnt++;
  }
return std::to_string(cnt)[inc - size + temp - 1] - '0';
