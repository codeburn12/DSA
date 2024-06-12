#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list node
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution
{
public:
    // Function to construct a linked list from a given vector of integers
    Node *constructLL(vector<int> &arr)
    {
        // Create the head node with the first element of the array
        Node *head = new Node(arr[0]);
        // Initialize a pointer 'mover' to traverse the list
        Node *mover = head;
        // Loop through the rest of the elements in the array
        for (int i = 1; i < arr.size(); i++)
        {
            // Create a new node with the current element
            Node *temp = new Node(arr[i]);
            // Link the current node to the new node
            mover->next = temp;
            // Move the 'mover' pointer to the new node
            mover = temp;
        }
        // Return the head of the constructed linked list
        return head;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    Node *head = sol.constructLL(arr);

    // Print the constructed linked list
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}

/*
Time Complexity: O(n)
- We traverse the array once to construct the linked list, where n is the number of elements in the array.

Space Complexity: O(n)
- We use additional space to store the linked list nodes, which requires O(n) space, where n is the number of elements in the array.
*/
