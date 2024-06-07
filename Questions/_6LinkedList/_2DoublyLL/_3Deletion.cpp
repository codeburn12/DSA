#include <iostream>
#include <vector>

using namespace std;

// Definition of the Node class for a doubly linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node

    // Constructor to initialize a node with a given value
    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }

    // Constructor to initialize a node with given value, next pointer, and previous pointer
    Node(int x, Node *nextPtr, Node *prevPtr)
    {
        data = x;
        next = nextPtr;
        prev = prevPtr;
    }
};

// Solution class to construct a doubly linked list from a vector
class Solution
{
public:
    Node *constructDLL(vector<int> &vec)
    {
        // Initialize the head of the linked list with the first element of the vector
        Node *head = new Node(vec[0]);
        Node *prev = head; // Keep track of the previous node

        // Loop through the rest of the elements in the vector to construct the linked list
        for (int i = 1; i < vec.size(); i++)
        {
            Node *temp = new Node(vec[i], nullptr, prev); // Create a new node with the current element
            prev->next = temp;                            // Link the previous node to the current node
            prev = temp;                                  // Update the previous node to the current node
        }
        return head; // Return the head of the constructed doubly linked list
    }

    Node *deleteAtBegining(Node *head) {
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }

    Node *deleteAtEnd(Node *head) {
        
    }
};

int main()
{
    int n;
    cin >> n; // Read the number of elements
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i]; // Read each element into the vector
    }

    Solution sol;
    Node *head = sol.constructDLL(vec); // Construct the doubly linked list
    head = sol.deleteAtBegining(head); // Construct the doubly linked list


    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " "; // Print the data of each node in the linked list
        temp = temp->next;         // Move to the next node
    }
    return 0;
}

