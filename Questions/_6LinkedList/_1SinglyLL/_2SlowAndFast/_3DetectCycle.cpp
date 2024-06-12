#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // Initialize two pointers, slow and fast, both starting at the head
        ListNode *slow = head;
        ListNode *fast = head;

        // Loop until the fast pointer reaches the end of the list
        while (fast != nullptr && fast->next != nullptr)
        {
            // Move slow pointer one step
            slow = slow->next;
            // Move fast pointer two steps
            fast = fast->next->next;
            // If slow and fast pointers meet, there is a cycle
            if (fast == slow)
            {
                return true;
            }
        }
        // If fast pointer reaches the end, there is no cycle
        return false;
    }
};

int main()
{
    // Creating a linked list
    int n;
    cin >> n; // Number of nodes
    if (n == 0)
        return 0;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    unordered_set<ListNode *> nodes;

    // Taking input for the linked list
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        ListNode *newNode = new ListNode(value);
        nodes.insert(newNode);
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

    // Creating a cycle for testing purposes (comment out if not needed)
    // if (n > 1) {
    //     tail->next = head->next;  // Example: pointing the last node to the second node
    // }

    // Creating the Solution object and checking for cycle
    Solution solution;
    bool result = solution.hasCycle(head);

    // Output the result
    cout << (result ? "Cycle detected" : "No cycle detected") << endl;

    // Clean up the allocated nodes to avoid memory leak
    for (auto node : nodes)
    {
        delete node;
    }

    return 0;
}

/**
 * Time Complexity: O(n), where n is the number of nodes in the linked list.
 * Space Complexity: O(1), as no extra space is used other than the slow and fast pointers.
 */
