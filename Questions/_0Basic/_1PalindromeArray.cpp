#include <iostream>

using namespace std;

class Solution
{
public:
    // Check if each element in the array is a palindrome
    int PalinArray(int a[], int n)
    {
        // Loop through each element in the array
        for (int i = 0; i < n; i++)
        {
            int rem = 0, reverseNo = 0, num = a[i];
            // Reverse the number
            while (num)
            {
                rem = num % 10;
                reverseNo = reverseNo * 10 + rem;
                num /= 10;
            }
            // Check if the reversed number is equal to the original number
            if (reverseNo != a[i])
            {
                return 0; // If not, return 0 (not a palindrome)
            }
        }
        return 1; // If all elements are palindromes, return 1
    }
};

int main()
{
    int n;
    cin >> n; // Input the size of the array

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // Input array elements
    }

    Solution solution;
    int result = solution.PalinArray(a, n); // Call the function

    return result; // Output the result without any statement
}
// TC: O(n * log10(m)) - Time complexity where n is the size of the array and m is the maximum number in the array (log10(m) represents the number of digits in m).
// SC: O(1) - Space complexity. The space used is constant and doesn't depend on the size of the input array.
