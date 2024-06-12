#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution
{
public:
    // Function to count nodes of a linked list.
    int getCount(struct Node *head)
    {
        // Initialize count to 0
        int cnt = 0;
        // Initialize a temporary pointer to traverse the list
        Node *temp = head;
        // Traverse the list until the end
        while (temp != nullptr)
        {
            // Move the temporary pointer to the next node
            temp = temp->next;
            // Increment the count
            cnt++;
        }
        // Return the final count
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;

    // Initialize head of the linked list
    Node *head = nullptr;
    Node *tail = nullptr;

    // Input nodes data and create the linked list
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *newNode = new Node(x);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Create a Solution object
    Solution sol;
    // Get the count of nodes in the linked list
    int count = sol.getCount(head);
    // Print the count
    cout << count << endl;

    return 0;
}

/*
Time Complexity: O(n) where n is the number of nodes in the linked list.
Space Complexity: O(1) since we are using a constant amount of extra space.
*/
