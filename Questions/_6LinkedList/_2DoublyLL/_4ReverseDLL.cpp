#include <iostream>
using namespace std;

// Definition for the doubly linked list node
struct Node
{
    int data;
    Node *next;
    Node *prev;

    // Constructor to initialize the node
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

// Solution class containing the method to reverse the doubly linked list
class Solution
{
public:
    Node *reverseDLL(Node *head)
    {
        // If the list is empty or contains only one node, return the head
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *temp = head;    // Pointer to traverse the list
        Node *back = nullptr; // Pointer to store the previous node

        // Traverse the list
        while (temp != nullptr)
        {
            back = temp->prev;       // Store the previous node
            temp->prev = temp->next; // Swap the prev and next pointers
            temp->next = back;
            temp = temp->prev; // Move to the next node in the original list
        }

        // Return the new head of the reversed list
        return back->prev;
    }
};

// Function to create a doubly linked list from input and return the head
Node *createDLL()
{
    int n;
    cin >> n; // Number of elements
    if (n == 0)
        return NULL;

    int val;
    cin >> val; // First element
    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 1; i < n; ++i)
    {
        cin >> val; // Next element
        Node *newNode = new Node(val);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    return head;
}

// Function to print the doubly linked list
void printDLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create the doubly linked list from user input
    Node *head = createDLL();

    // Solution object
    Solution sol;

    // Reverse the doubly linked list
    Node *reversedHead = sol.reverseDLL(head);

    // Print the reversed doubly linked list
    printDLL(reversedHead);

    return 0;
}

/*
Time Complexity:
- The time complexity is O(n) where n is the number of nodes in the doubly linked list.
- This is because we traverse each node exactly once.

Space Complexity:
- The space complexity is O(1) since we are using a constant amount of extra space regardless of the input size.
*/
