#include <iostream>

class Solution
{
public:
    // Function to find the position of the rightmost set bit in a power of 2
    int findPosition(int n)
    {
        int position = 0;

        // Check if n is positive and a power of 2 using (n & (n-1)) trick
        if (n > 0 && ((n & (n - 1)) == 0))
        {
            // Iterate through each bit of n
            while (n > 0)
            {
                position++;
                if (n & 1)
                {
                    return position; // Return position if the rightmost bit is set
                }
                n >>= 1; // Right shift n by 1 to check the next bit
            }
        }

        return -1; // Return -1 if n is not a power of 2 or not positive
    }
};

int main()
{
    Solution solution;
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    int position = solution.findPosition(n);
    if (position != -1)
    {
        std::cout << "Position of the rightmost set bit in " << n << " is " << position << std::endl;
    }
    else
    {
        std::cout << "The input is not a positive power of 2." << std::endl;
    }

    return 0;
}
/*
Time Complexity :- In the worst case, where n is a power of 2 and has all bits set, the function would iterate through all bits, leading to a time complexity of O(logn), where
Space Complexity :- O(1)
*/
