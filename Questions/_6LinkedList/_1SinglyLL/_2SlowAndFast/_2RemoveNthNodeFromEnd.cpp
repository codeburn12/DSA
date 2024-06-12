#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Initialize two pointers, both starting at the head of the list.
        ListNode *slow = head;
        ListNode *fast = head;

        // Move the fast pointer n steps ahead.
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // If fast reached the end, we need to remove the head node.
        if (fast == nullptr)
        {
            return head->next;
        }

        // Move both pointers until fast reaches the end of the list.
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Slow is now at the node before the one we want to delete.
        ListNode *deleteNode = slow->next;
        slow->next = slow->next->next;

        // Delete the node to free up memory.
        delete deleteNode;

        // Return the head of the modified list.
        return head;
    }
};

// Function to create a linked list from an array of values.
ListNode *createLinkedList(int arr[], int size)
{
    if (size == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list.
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    // Take the number of elements in the linked list.
    int size;
    cin >> size;

    // Take the elements of the linked list.
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Create the linked list.
    ListNode *head = createLinkedList(arr, size);

    // Take the value of n.
    int n;
    cin >> n;

    // Create an object of Solution class.
    Solution sol;

    // Call the function to remove the nth node from the end.
    head = sol.removeNthFromEnd(head, n);

    // Print the modified linked list.
    printLinkedList(head);

    return 0;
}

/**
 * Time Complexity: O(L), where L is the length of the linked list.
 * Space Complexity: O(1), since we only use a constant amount of extra space.
 */
