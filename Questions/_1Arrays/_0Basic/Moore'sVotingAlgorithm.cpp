#include <iostream>
using namespace std;

class Solution
{
public:
    int majorityElement(int a[], int size)
    {
        // Finding majority element using Boyer-Moore Voting Algorithm
        int majorEle, cnt = 0;

        // Iterate through the array to find potential majority element
        for (int i = 0; i < size; i++)
        {
            if (cnt == 0)
            {
                majorEle = a[i];
                cnt = 1;
            }
            else if (a[i] == majorEle)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        cnt = 0;

        // Count occurrences of potential majority element
        for (int i = 0; i < size; i++)
        {
            if (a[i] == majorEle)
            {
                cnt++;
            }
        }

        // Check if the potential majority element is indeed a majority element
        return cnt > size / 2 ? majorEle : -1;
    }
};

int main()
{
    int size;
    cin >> size;

    int *a = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    Solution obj;
    int result = obj.majorityElement(a, size);
    if (result != -1)
    {
        cout << "Majority Element: " << result << endl;
    }
    else
    {
        cout << "No majority element found." << endl;
    }

    delete[] a; // Freeing dynamically allocated memory
    return 0;
}
// The time complexity of this algorithm is O(n) as it iterates through the array twice
// the space complexity is O(1) as it uses constant extra space.