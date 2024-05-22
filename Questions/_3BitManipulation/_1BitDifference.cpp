#include <iostream>

class Solution
{
public:
    // Function to find the number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {
        // Calculate the XOR of a and b to find differing bits
        int c = a ^ b;
        int cnt = 0; // Initialize counter to count differing bits

        // Iterate through each bit of c
        while (c != 0)
        {
            // If the least significant bit of c is 1, increment count
            if (c & 1)
            {
                cnt++;
            }
            c >>= 1; // Right shift c by 1 bit to check the next bit
        }

        return cnt; // Return the count of differing bits
    }
};

int main()
{
    Solution solution;
    int a, b;
    std::cout << "Enter two integers a and b separated by a space: ";
    std::cin >> a >> b;

    int bitsFlipped = solution.countBitsFlip(a, b);
    std::cout << "Number of bits needed to be flipped to convert a to b: " << bitsFlipped << std::endl;

    return 0;
}

/*
Time Complexity: The time complexity of this code is 𝑂(log𝑁) where 𝑁
N is the maximum of a and b. This is because the loop iterates through the bits of c, which is at most the number of bits required to represent the larger of a and b.

Space Complexity: The space complexity is𝑂(1) because the algorithm uses only a constant amount of additional space, regardless of the input size.
*/