#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to delete the node at the beginning of the linked list
Node *deleteNodeAtBegining(Node *head)
{
    // If the list is empty, return the head (nullptr)
    if (head == nullptr)
    {
        return head;
    }

    Node *temp = head; // Temporarily store the head node
    head = head->next; // Move the head to the next node
    delete temp;       // Delete the old head node
    return head;       // Return the new head
}

// Function to delete the node at the end of the linked list
Node *deleteNodeAtEnd(Node *head)
{
    // If the list is empty or only one node, return nullptr
    if (head == nullptr || head->next == nullptr)
    {
        delete head; // Delete the single node if it exists
        return nullptr;
    }

    Node *temp = head;
    // Traverse to the second last node
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;    // Delete the last node
    temp->next = nullptr; // Set the new end of the list
    return head;
}

// Function to delete a node with a specific value in the linked list
Node *deleteValue(Node *head, int value)
{
    // If the list is empty, return the head (nullptr)
    if (head == nullptr)
    {
        return head;
    }

    // If the value to be deleted is at the first node
    if (head->data == value)
    {
        Node *temp = head; // Temporarily store the head node
        head = head->next; // Move the head to the next node
        delete temp;       // Delete the old head node
        return head;       // Return the new head
    }

    Node *temp = head;    // Pointer to traverse the list
    Node *prev = nullptr; // Pointer to keep track of the previous node

    // Traverse the list until the end or until the value is found
    while (temp != nullptr)
    {
        // If the current value is the target value
        if (temp->data == value)
        {
            prev->next = temp->next; // Update the next pointer of the previous node to skip the target node
            delete temp;             // Delete the target node
            break;                   // Break out of the loop
        }
        prev = temp;       // Update the previous node to current node
        temp = temp->next; // Move to the next node
    }

    return head; // Return the head of the modified list
}

// Function to delete the node at position x in the linked list
Node *deleteNodeAtPosition(Node *head, int x)
{
    // If the list is empty, return the head (nullptr)
    if (head == nullptr)
    {
        return head;
    }

    // If the node to be deleted is the first node
    if (x == 1)
    {
        Node *temp = head; // Temporarily store the head node
        head = head->next; // Move the head to the next node
        delete temp;       // Delete the old head node
        return head;       // Return the new head
    }

    int cnt = 1;
    Node *temp = head;    // Pointer to traverse the list
    Node *prev = nullptr; // Pointer to keep track of the previous node

    // Traverse the list until the end or until the position is found
    while (temp != nullptr && cnt < x)
    {
        prev = temp;       // Update the previous node to current node
        temp = temp->next; // Move to the next node
        cnt++;             // Increment the counter
    }

    // If the position is valid
    if (temp != nullptr)
    {
        prev->next = temp->next; // Update the next pointer of the previous node to skip the target node
        delete temp;             // Delete the target node
    }

    return head; // Return the head of the modified list
}

// Function to create a linked list from user input
Node *createList(int n)
{
    if (n <= 0)
        return nullptr;
    int val;
    cin >> val;
    Node *head = new Node(val);
    Node *temp = head;
    for (int i = 1; i < n; ++i)
    {
        cin >> val;
        temp->next = new Node(val);
        temp = temp->next;
    }
    return head;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n, x, value;
    cin >> n;                             // Number of nodes in the list
    cin >> value;                         // Value of the node to delete
    cin >> x;                             // Position of the node to delete
    Node *head = createList(n);           // Create the list
    head = deleteNodeAtBegining(head);    // Delete the node at the beginning
    head = deleteNodeAtEnd(head);         // Delete the node at the end
    head = deleteValue(head, value);      // Delete the node with the specified value
    head = deleteNodeAtPosition(head, x); // Delete the node at the specified position
    printList(head);                      // Print the modified list
    return 0;
}

/*
Time Complexity: O(n)
- In the worst case, we might need to traverse the entire list to delete the node at the end, or the node with a specific value or at a specific position. Thus, the time complexity is linear with respect to the number of nodes in the list.

Space Complexity: O(1)
- The space complexity is constant because we are using a fixed amount of extra space (a few pointers) regardless of the size of the input list.
*/
