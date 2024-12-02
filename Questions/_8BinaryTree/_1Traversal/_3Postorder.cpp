#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include<queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vec;

        // Recursive approach
        recursive(vec, root);

        // Iterative approach (comment out the recursive call and uncomment below lines to use iterative method)
        // iterative(vec, root);

        return vec;
    }

    // Recursive postorder traversal (Left, Right, Root)
    void recursive(vector<int> &vec, TreeNode *root)
    {
        if (!root) // Base case: If the node is null, return
            return;

        // Traverse the left subtree
        recursive(vec, root->left);

        // Traverse the right subtree
        recursive(vec, root->right);

        // Process the root node
        vec.push_back(root->val);
    }

    // Iterative postorder traversal using a stack
    void iterative(vector<int> &vec, TreeNode *root)
    {
        if (!root) // If the root is null, return
            return;

        stack<TreeNode *> st; // Stack to store nodes
        st.push(root);        // Start with the root node

        while (!st.empty())
        {
            TreeNode *currentNode = st.top(); // Get the top node
            st.pop();                         // Remove the top node from the stack

            // Push the current node value into the result vector
            vec.push_back(currentNode->val);

            // Push the left and right children to the stack (push left after right to process left first)
            if (currentNode->left)
                st.push(currentNode->left);
            if (currentNode->right)
                st.push(currentNode->right);
        }

        // Reverse the result since we processed it as Root, Right, Left
        reverse(vec.begin(), vec.end());
    }
};

// Utility function to create a binary tree from level-order input
TreeNode *buildTree(vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (nodes[i] != "null")
        {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null")
        {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main()
{
    string input;
    getline(cin, input); // Read level-order input as a single line

    stringstream ss(input);
    vector<string> nodes;
    string node;

    while (ss >> node) // Split the input by spaces
        nodes.push_back(node);

    TreeNode *root = buildTree(nodes); // Build the binary tree

    Solution sol;
    vector<int> result = sol.postorderTraversal(root); // Perform postorder traversal

    for (int val : result) // Output the traversal result
        cout << val << " ";

    return 0;
}

/*
Time Complexity:
- Recursive: O(N), where N is the number of nodes, as we visit each node once.
- Iterative: O(N), as each node is pushed and popped from the stack once.

Space Complexity:
- Recursive: O(H), where H is the height of the tree (due to recursion stack).
- Iterative: O(H), for the stack used to simulate recursion.
*/
