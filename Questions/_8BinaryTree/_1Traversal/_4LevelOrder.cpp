#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor with value and child pointers
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Function to perform level-order traversal of the binary tree
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans; // Result to store level-order traversal
        if (!root)               // If the tree is empty, return an empty result
            return ans;

        queue<TreeNode *> q; // Queue to manage nodes at each level
        q.push(root);        // Start with the root node

        // Process nodes level by level
        while (!q.empty())
        {
            int qSize = q.size();        // Get the number of nodes in the current level
            vector<int> currentLevelAns; // Temporary vector to store values of the current level

            // Traverse all nodes in the current level
            while (qSize--)
            {
                TreeNode *currentNode = q.front(); // Get the front node from the queue
                q.pop();                           // Remove it from the queue

                currentLevelAns.push_back(currentNode->val); // Add the node's value to the level result

                // Add left child to the queue if it exists
                if (currentNode->left)
                    q.push(currentNode->left);

                // Add right child to the queue if it exists
                if (currentNode->right)
                    q.push(currentNode->right);
            }

            ans.push_back(currentLevelAns); // Add the current level's result to the final answer
        }

        return ans; // Return the level-order traversal
    }
};

// Helper function to create a binary tree from input
TreeNode *createTree()
{
    int val;
    cin >> val;    // Take value for the root node
    if (val == -1) // -1 represents a null node
        return nullptr;

    TreeNode *root = new TreeNode(val); // Create the root node
    root->left = createTree();          // Recursively create the left subtree
    root->right = createTree();         // Recursively create the right subtree
    return root;
}

// Driver code
int main()
{
    TreeNode *root = createTree(); // Create the tree from user input
    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root); // Get level-order traversal

    // Print the result
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/**
 * Time Complexity: O(n)
 * - Each node is visited once, where n is the total number of nodes in the binary tree.
 *
 * Space Complexity: O(n)
 * - In the worst case, the queue will store nodes of the largest level (at most n/2 nodes in a perfect binary tree).
 */
