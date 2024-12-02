#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;         // Value of the current node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Constructors to initialize a tree node
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Function to return the inorder traversal of a binary tree
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vec;      // Vector to store the traversal results
        recursive(vec, root); // Call the recursive function
        // iterative(vec, root); // Uncomment to use the iterative function
        return vec;
    }

    // Recursive inorder traversal
    void recursive(vector<int> &vec, TreeNode *root)
    {
        if (!root) // Base case: if the node is null, return
            return;

        recursive(vec, root->left);  // Recur on the left subtree
        vec.push_back(root->val);    // Visit the root node
        recursive(vec, root->right); // Recur on the right subtree
    }

    // Iterative inorder traversal
    void iterative(vector<int> &vec, TreeNode *root)
    {
        if (!root) // If the tree is empty, return
            return;

        stack<TreeNode *> st;  // Stack to simulate recursion
        leftSubTree(root, st); // Push the leftmost subtree nodes onto the stack

        while (!st.empty())
        {                                     // Process all nodes in the stack
            TreeNode *currentNode = st.top(); // Get the top node
            st.pop();                         // Remove it from the stack

            vec.push_back(currentNode->val); // Visit the node

            if (currentNode->right)                  // If the node has a right child
                leftSubTree(currentNode->right, st); // Process its leftmost subtree
        }
    }

    // Helper function to push all left subtree nodes onto the stack
    void leftSubTree(TreeNode *node, stack<TreeNode *> &st)
    {
        st.push(node); // Push the current node
        while (node->left)
        { // Traverse to the leftmost node
            st.push(node->left);
            node = node->left;
        }
    }
};

// Function to build a binary tree from user input
TreeNode *buildTree()
{
    int val;
    cin >> val;    // Input the root value
    if (val == -1) // Use -1 to represent null nodes
        return nullptr;

    TreeNode *root = new TreeNode(val);
    root->left = buildTree();  // Recursively build the left subtree
    root->right = buildTree(); // Recursively build the right subtree
    return root;
}

int main()
{
    TreeNode *root = buildTree(); // Build the binary tree from user input
    Solution solution;

    vector<int> result = solution.inorderTraversal(root); // Perform inorder traversal

    for (int val : result) // Output the result
        cout << val << " ";
    return 0;
}

/*
Time Complexity:
- Recursive and Iterative: O(N), where N is the number of nodes in the tree. Each node is visited once.

Space Complexity:
- Recursive: O(H), where H is the height of the tree due to the recursion stack.
- Iterative: O(H), for the stack used to simulate recursion.
*/
