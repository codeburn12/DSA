#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;                                                                               // Value of the node
    TreeNode *left;                                                                        // Pointer to the left child
    TreeNode *right;                                                                       // Pointer to the right child
    TreeNode() : val(0), left(nullptr), right(nullptr) {}                                  // Default constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}                             // Constructor with value
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // Constructor with value and children
};

class Solution
{
public:
    // Function to perform preorder traversal and return the result as a vector
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> vec; // Vector to store preorder traversal
        // Uncomment below line for recursive approach
        // recursive(vec, root);

        // Using iterative approach
        iterative(vec, root);
        return vec;
    }

    // Recursive function for preorder traversal
    void recursive(vector<int> &vec, TreeNode *root)
    {
        if (!root) // Base condition: if node is null, return
            return;
        vec.push_back(root->val);    // Visit the root node
        recursive(vec, root->left);  // Recursively traverse the left subtree
        recursive(vec, root->right); // Recursively traverse the right subtree
    }

    // Iterative function for preorder traversal
    void iterative(vector<int> &vec, TreeNode *root)
    {
        if (!root) // Return if the tree is empty
            return;

        stack<TreeNode *> st; // Stack to simulate recursion for preorder traversal
        st.push(root);        // Push the root node to the stack

        while (!st.empty())
        {                                     // Process nodes while the stack is not empty
            TreeNode *currentNode = st.top(); // Get the top node
            st.pop();                         // Remove the node from the stack

            vec.push_back(currentNode->val); // Visit the node

            // Push the right child first, so the left child is processed first
            if (currentNode->right != nullptr)
                st.push(currentNode->right);
            if (currentNode->left != nullptr)
                st.push(currentNode->left);
        }
    }
};

// Function to build a binary tree from input
TreeNode *buildTree()
{
    int val;
    cin >> val; // Read root value from input
    if (val == -1)
        return nullptr;                 // -1 indicates null node
    TreeNode *root = new TreeNode(val); // Create a new node for the root
    root->left = buildTree();           // Recursively build the left subtree
    root->right = buildTree();          // Recursively build the right subtree
    return root;
}

int main()
{
    TreeNode *root = buildTree(); // Build the tree from input
    Solution sol;
    vector<int> result = sol.preorderTraversal(root); // Get preorder traversal
    for (int val : result)                            // Output the result
        cout << val << " ";
    return 0;
}

/*
Time Complexity:
- Recursive approach: O(n), where n is the number of nodes in the binary tree. Each node is visited exactly once.
- Iterative approach: O(n), since each node is processed once using the stack.

Space Complexity:
- Recursive approach: O(h), where h is the height of the binary tree (for the recursion stack).
- Iterative approach: O(h), where h is the height of the binary tree (for the stack used explicitly).
*/
