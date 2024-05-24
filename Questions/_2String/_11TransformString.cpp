#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int transform(string A, string B)
    {
        // Check if the lengths of A and B are not equal, return -1
        if (A.size() != B.size())
            return -1;

        // Initialize variables and frequency array
        int n = A.size();
        vector<int> freq(256, 0);

        // Count frequency of characters in A and B
        for (int i = 0; i < n; i++)
        {
            freq[A[i]]++;
            freq[B[i]]--;
        }

        // Check if frequencies of all characters are balanced
        for (int i = 0; i < 256; i++)
        {
            if (freq[i] != 0)
                return -1;
        }

        // Initialize count and pointers
        int cnt = 0;
        int i = A.size() - 1, j = B.size() - 1;

        // Count the number of operations required to transform A into B
        while (i >= 0)
        {
            if (A[i] != B[j])
            {
                cnt++;
                i--;
            }
            else
            {
                i--;
                j--;
            }
        }

        // Return the count of operations
        return cnt;
    }
};

int main()
{
    string A, B;
    cin >> A >> B;
    Solution obj;
    int result = obj.transform(A, B);
    cout << result << endl;
    return 0;
}

/*
Time complexity: O(n), where n is the size of the input strings A and B.
Space complexity: O(1) or O(256) as the space required is constant or proportional to the size of the character set (ASCII characters, 256 in this case).
*/