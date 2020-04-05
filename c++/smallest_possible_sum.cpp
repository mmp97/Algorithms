#include <vector>
unsigned long long solution(const std::vector<unsigned long long>& arr){
  unsigned long long smallest=arr[0];
  for(int i=1;i<arr.size()-1;i++)
  if(smallest>arr[i])
  smallest=arr[i];
  unsigned long long quantum=smallest;
  int j=0,n=2;
  while(j<arr.size()){
  if(arr[j]%quantum==0)
    j++;
  else if(arr[j]%quantum!=0){ 
    quantum=smallest/n;
    n++;
    j=0;
    }
  }
  return quantum*arr.size();
}
