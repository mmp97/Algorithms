using namespace std;
class KPrimes
{
public:    
   static vector<long long> countKprimes(int k, long long start, long long end)
   {
    vector <long long> kprimes;
    long long count=0;
    
    for(long long i=start;i<=end;i++)
    {
      long long temp=i;
      long long divisor=2;
      while(temp>1 && divisor*divisor<=i)
      {
        while(temp%divisor==0)
        {
          temp/=divisor;
          count++;
        }
        if(count>k)
          break;
        divisor++;
      }
      if(temp!=1)
        count++;
      if(count==k)
        kprimes.push_back(i);         
      count=0;
    }
    return kprimes;
   }
   
    static int puzzle(int s)
    {
    vector <long long> ones,threes,sevens;
    int res=0;
    int divisor=1,count=0;
    for(int i=2;i<=s;i++)
    {
      int temp=i;
      while(temp>1)
      {
        divisor++;
        if(temp%divisor==0)
        {
          temp/=divisor;
          divisor=1;
          count++;
        }
      }     
      if(count==1)
        ones.push_back(i);
      if(count==3)
        threes.push_back(i);
      if(count==7)
        sevens.push_back(i);
      count=0;
       }
      for(int i=0;i<sevens.size();i++)
        for(int j=0;j<threes.size();j++)
          for(int k=0;k<ones.size();k++)
            if(sevens[i]+threes[j]+ones[k]==s)
              res++;
      return res;
    }
};
