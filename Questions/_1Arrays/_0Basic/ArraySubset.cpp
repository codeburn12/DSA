#include <iostream>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> countA1;

    // Count occurrences of elements in a1
    for (int i = 0; i < n; i++)
    {
        countA1[a1[i]]++;
    }

    // Check if all elements of a2 are present in a1 with sufficient counts
    for (int i = 0; i < m; i++)
    {
        if (countA1[a2[i]] == 0)
        {
            return "No"; // Element not found or count insufficient
        }
        countA1[a2[i]]--; // Decrease count in a1
    }

    return "Yes";
}

int main()
{
    int n, m;
    cin >> n >> m; // Input the sizes of arrays a1 and a2

    int a1[n], a2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i]; // Input elements of array a1
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a2[i]; // Input elements of array a2
    }

    // Check if a2 is a subset of a1
    string result = isSubset(a1, a2, n, m);

    // Output the result
    cout << result << endl;
    return 0;
}

// Time Complexity (TC): O(n + m) - Linear time complexity where n is the size of a1 and m is the size of a2. The function iterates through both arrays once.
// Space Complexity (SC): O(n) - Linear space complexity where n is the size of a1. This is due to the unordered_map countA1 that stores counts of elements from a1.
