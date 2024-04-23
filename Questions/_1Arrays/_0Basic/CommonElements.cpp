#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        int i = 0, j = 0, k = 0;
        vector<int> vec;

        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] == B[j] && B[j] == C[k])
            {
                vec.push_back(A[i]);

                int commonEle = A[i];

                // Skip all occurrences of the common element in arrays A, B, and C
                while (i < n1 && A[i] == commonEle)
                {
                    i++;
                }
                while (j < n2 && B[j] == commonEle)
                {
                    j++;
                }
                while (k < n3 && C[k] == commonEle)
                {
                    k++;
                }
            }
            else if (A[i] < B[j])
            {
                i++;
            }
            else if (B[j] < C[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }

        return vec;
    }
};

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int A[n1], B[n2], C[n3];
    for (int i = 0; i < n1; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> C[i];
    }

    Solution solution;
    vector<int> result = solution.commonElements(A, B, C, n1, n2, n3);

    // Output the common elements without using a statement
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}

// time complexity of O(n1 + n2 + n3), where n1, n2, and n3 are the sizes of arrays A, B, and C respectively.
// space complexity is O(1) as we use constant extra space for variables and the result vector.