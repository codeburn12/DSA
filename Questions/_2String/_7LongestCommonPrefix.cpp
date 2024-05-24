#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // Function to find the longest common prefix among the array of strings
    string longestCommonPrefix(string arr[], int N)
    {
        // Initialize the prefix with the first string in the array
        string s = arr[0];
        // Initialize an empty string to store the current common prefix
        string ans = "";

        // Loop through the rest of the strings in the array
        for (int i = 1; i < N; i++)
        {
            int j = 0;
            // Compare characters of the current string with the current prefix
            while (j < s.size() && j < arr[i].size() && s[j] == arr[i][j])
            {
                ans += arr[i][j]; // Append matching characters to ans
                j++;
            }
            // Update the current prefix to the longest common prefix found so far
            s = ans;
            // Reset ans for the next iteration
            ans = "";
        }

        // If the final prefix is not empty, return it; otherwise, return "-1"
        return (s.size() != 0) ? s : "-1";
    }
};

// Main function to take input from the user and call the longestCommonPrefix function
int main()
{
    int N;
    cin >> N;
    string arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.longestCommonPrefix(arr, N) << endl;

    return 0;
}

/*
Time Complexity:
- The worst-case time complexity is O(N * M), where N is the number of strings and M is the length of the shortest string in the array. This is because for each string, we might compare up to M characters.

Space Complexity:
- The space complexity is O(M) for the space used by the prefix string, where M is the length of the shortest string in the array. The additional space used by 'ans' is negligible because it resets on each iteration.
*/
