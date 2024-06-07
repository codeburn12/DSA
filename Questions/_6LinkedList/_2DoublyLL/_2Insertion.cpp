#include <iostream>
#include <vector>

using namespace std;

// Definition of the Node class for a doubly linked list
class Node {
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

class Solution {
    public:
        Node *insertionAtBegining(Node *head, int x) {
            if(head == nullptr) {
                return head;
            }
            
            return new Node(x, head, nullptr);
        }
};

int main() {
    Solution sol;
    Node *head = nullptr;

    int n;
    cin >> n; // Input: number of elements to insert at the beginning
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x; // Input: element to insert at the beginning
        head = sol.insertionAtBegining(head, x);
    }

    // Output the list
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
