#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> AllPrimeFactors(int N)
    {
        vector<int> primes;

        // Check for number of 2s that divide N
        if (N % 2 == 0)
        {
            primes.push_back(2);
            while (N % 2 == 0)
            {
                N /= 2;
            }
        }

        // N must be odd at this point so we can skip one element (i.e., we start from 3 and step by 2)
        for (int i = 3; i <= sqrt(N); i += 2)
        {
            // While i divides N, add i and divide N
            if (N % i == 0)
            {
                primes.push_back(i);
                while (N % i == 0)
                {
                    N /= i;
                }
            }
        }

        // This condition is to check if N is a prime number greater than 2
        if (N > 2)
        {
            primes.push_back(N);
        }

        return primes;
    }
};

// Time complexity: O(sqrt(N)), where N is the input number
// Space complexity: O(log(N)), where N is the input number (the space required is proportional to the number of prime factors)
