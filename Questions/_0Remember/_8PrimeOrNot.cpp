#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int isPrime(int num)
    {
        // Check if the number is less than or equal to 1
        // Numbers less than or equal to 1 are not prime
        if (num <= 1)
        {
            return 0;
        }

        // Check divisibility from 2 to the square root of the number
        // If any number in this range divides num without a remainder,
        // then num is not prime
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                return 0;
            }
        }

        // If no divisors were found, num is prime
        return 1;
    }
};

int main()
{
    Solution sol;
    int num;

    // Take input from user
    cin >> num;

    // Check if the number is prime
    int result = sol.isPrime(num);

    // Print the result
    cout << result << endl;

    return 0;
}

/*
Time Complexity: O(sqrt(n))
- The loop runs from 2 to sqrt(num), so the time complexity is O(sqrt(n)).

Space Complexity: O(1)
- The space complexity is constant as no additional space proportional to input size is used.
*/
