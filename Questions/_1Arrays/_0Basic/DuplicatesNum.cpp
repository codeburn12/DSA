#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> duplicates(long long arr[], int n)
    {
        map<int, int> frequency; // Hash table to store the frequency of elements
        vector<int> duplicate;

        // Count the frequency of each element
        for (int i = 0; i < n; ++i)
        {
            frequency[arr[i]]++;
        }

        // Check for elements with frequency greater than 1 (duplicates)
        for (auto &pair : frequency)
        {
            if (pair.second > 1)
            {
                duplicate.push_back(pair.first);
            }
        }

        if (duplicate.empty())
        {
            return {-1}; // No duplicates found, return -1 as a single-element vector
        }

        return duplicate; // Return the vector containing duplicate elements
    }
};

int main()
{
    int n;

    cin >> n; // Input the size of the array

    long long arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    Solution obj;
    vector<int> result = obj.duplicates(arr, n); // Find duplicate elements

    // Output the result

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity (TC): O(N) - Where N is the size of the array. We iterate through the array once to count the frequency of elements.
// Space Complexity (SC): O(N) - In the worst case, all elements in the array are unique, and we store each element's frequency in the hash table, leading to O(N) space usage.
