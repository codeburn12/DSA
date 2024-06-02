#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution
{
public:
    // Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x)
    {
        // Create a new node with the given value
        Node *temp = new Node(x);

        // Set the next of new node to the current head
        temp->next = head;

        // Update head to the new node
        head = temp;

        return head;
    }

    // Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)
    {
        // If the list is empty, create a new node and return it as the head
        if (head == nullptr)
        {
            Node *temp = new Node(x);
            return temp;
        }

        // Traverse to the end of the list
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        // Create a new node and attach it to the last node
        Node *endNode = new Node(x);
        temp->next = endNode;

        return head;
    }

    // Function to insert a node at given position of the linked list.
    Node *insertAtPosition(Node *head, int x, int pos)
    {
        // If the position is 1, insert at the beginning
        if (pos == 1)
        {
            Node *temp = new Node(x);
            temp->next = head;
            return temp;
        }

        // Traverse to the position before where new node is to be inserted
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; ++i)
        {
            temp = temp->next;
        }

        // If the position is valid, insert the new node
        if (temp != nullptr)
        {
            Node *newNode = new Node(x);
            newNode->next = temp->next;
            temp->next = newNode;
        }

        return head;
    }

    // Function to insert a value before given value of the linked list.
    Node *insertBeforeValue(Node *head, int x, int value)
    {
        // If the list is empty, return nullptr
        if (head == nullptr)
        {
            return nullptr;
        }

        // If the head node contains the value, insert at the beginning
        if (head->data == value)
        {
            Node *newNode = new Node(x);
            newNode->next = head;
            return newNode;
        }

        // Traverse to the node before the one containing the value
        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;
        }

        // If the value is found, insert the new node
        if (temp->next != nullptr)
        {
            Node *newNode = new Node(x);
            newNode->next = temp->next;
            temp->next = newNode;
        }

        return head;
    }
};

int main()
{
    Solution sol;
    Node *head = nullptr;

    int n;
    cin >> n; // Input: number of elements to insert at the beginning
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x; // Input: element to insert at the beginning
        head = sol.insertAtBegining(head, x);
    }

    int m;
    cin >> m; // Input: number of elements to insert at the end
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x; // Input: element to insert at the end
        head = sol.insertAtEnd(head, x);
    }

    int p, pos;
    cin >> p >> pos; // Input: element to insert and position
    head = sol.insertAtPosition(head, p, pos);

    int q, value;
    cin >> q >> value; // Input: element to insert and value before which to insert
    head = sol.insertBeforeValue(head, q, value);

    // Output the list
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}

/*
Time Complexity:
- insertAtBegining: O(1) because inserting at the beginning is a constant time operation.
- insertAtEnd: O(N) because in the worst case we need to traverse the entire list to find the end (N is the number of nodes in the list).
- insertAtPosition: O(N) because in the worst case we need to traverse the entire list to find the position.
- insertBeforeValue: O(N) because in the worst case we need to traverse the entire list to find the value.

Space Complexity:
- All functions use O(1) extra space because they only use a constant amount of extra memory for new nodes and pointers.
*/
