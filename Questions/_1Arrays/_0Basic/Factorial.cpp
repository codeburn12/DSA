#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> factorial(int N)
    {
        vector<int> ans;
        ans.push_back(1);
        if (N == 0 || N == 1)
        {
            return ans;
        }
        for (int num = 2; num <= N; num++)
        {
            int carry = 0;      
            for (int j = 0; j < ans.size(); j++)
            {
                int currentNum = ans[j] * num + carry;
                ans[j] = currentNum % 10;       // Unit digit
                carry = currentNum / 10;        // Next digit
            }

            // If number is more than single digits, then carry should be taken as unit next digit
            while (carry)
            {
                ans.push_back(carry % 10);
                carry /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int N;
    cin >> N; // Input N

    Solution solution;
    vector<int> result = solution.factorial(N); // Compute factorial

    // Output result without using statement
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;

    return 0;
}
// TC(Time Complexity): O(N * D), where N is the input number and D is the number of digits in the result factorial. The outer loop runs N times, and each iteration of the inner loop processes D digits.
// SC(Space Complexity) : O(D), where D is the number of digits in the result factorial.We use a vector to store the digits of the factorial, which can have a maximum of D digits.