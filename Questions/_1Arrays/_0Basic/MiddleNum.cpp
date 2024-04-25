#include <iostream>
using namespace std;

class Solution
{
public:
    int middle(int A, int B, int C)
    {

        if ((A <= B && B <= C) || (A >= B && B >= C))
            return B;
        else if ((A <= C && B >= C) || (A >= C && B <= C))
            return C;
        else
            return A;
    }
};

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    Solution obj;
    int result = obj.middle(A, B, C);
    cout <<result << endl;

    return 0;
}

// Time Complexity: O(1)
// The function compares A, B, and C to determine the middle element.
// Since it only involves a few comparisons, the time complexity is constant.

// Space Complexity: O(1)
// The function uses a constant amount of extra space regardless of the input size.