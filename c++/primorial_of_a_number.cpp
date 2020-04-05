#include <math.h>
#include <vector>
using namespace std;
long long recursion(int);
vector <int> primes;
void SieveOfEratosthenes(int n);
unsigned long long numPrimorial (unsigned short int number )
{
int n=number*(log10(number)+10);
SieveOfEratosthenes(n);
return recursion(number);
}
long long recursion(int number)
{
    if (number > 1)
    {
        return primes[number-1]*recursion(number-1);
    }
    else
    {
        return 2;
    }
}
 void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p]){
          primes.push_back(p);
       }
}
