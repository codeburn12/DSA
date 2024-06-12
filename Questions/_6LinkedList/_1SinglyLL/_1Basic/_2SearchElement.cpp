#include <iostream>

// Definition for singly-linked list node.
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution
{
public:
    // Function to search for a key in the linked list.
    bool searchKey(int n, struct Node *head, int key)
    {
        // Initialize a temporary pointer to traverse the list starting from head.
        Node *temp = head;

        // Traverse the linked list.
        while (temp)
        {
            // If the current node's data matches the key, return true.
            if (temp->data == key)
            {
                return true;
            }
            // Move to the next node.
            temp = temp->next;
        }
        // If the key is not found, return false.
        return false;
    }
};

int main()
{
    // Create a linked list from user input
    int n;
    std::cin >> n; // Number of nodes in the linked list
    if (n <= 0)
        return 0; // If no nodes, return

    int value;
    std::cin >> value;
    Node *head = new Node(value); // Create head node
    Node *tail = head;

    // Read the rest of the nodes
    for (int i = 1; i < n; ++i)
    {
        std::cin >> value;
        tail->next = new Node(value);
        tail = tail->next;
    }

    // Read the key to search for
    int key;
    std::cin >> key;

    // Create a Solution object
    Solution sol;

    // Search for the key in the linked list and print the result
    bool found = sol.searchKey(n, head, key);
    std::cout << (found ? "true" : "false") << std::endl;

    // Cleanup: Delete all nodes to avoid memory leak
    Node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*
Time Complexity:
The time complexity of the searchKey function is O(n), where n is the number of nodes in the linked list.
This is because in the worst case, we might have to traverse all the nodes to find the key or to confirm it is not present.

Space Complexity:
The space complexity of the searchKey function is O(1).
This is because we are only using a constant amount of extra space (a single pointer to traverse the list).
*/
