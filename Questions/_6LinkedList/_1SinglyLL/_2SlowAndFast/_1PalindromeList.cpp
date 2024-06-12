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
    // Function to reverse a linked list
    ListNode *reverseLL(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *temp = head;    // Current node
        ListNode *prev = nullptr; // Previous node (initially null)

        // Traverse the list and reverse pointers
        while (temp != nullptr)
        {
            ListNode *front = temp->next; // Store next node
            temp->next = prev;            // Reverse the pointer
            prev = temp;                  // Move prev to current node
            temp = front;                 // Move to the next node
        }

        return prev; // New head of the reversed list
    }

    // Function to check if a linked list is a palindrome
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Initialize slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;

        // Find the middle of the linked list
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;       // Move slow by one step
            fast = fast->next->next; // Move fast by two steps
        }

        // Reverse the second half of the list
        ListNode *reversedLL = reverseLL(slow->next);
        ListNode *temp = head; // Pointer to the start of the list

        // Compare the first half and the reversed second half
        while (reversedLL != nullptr)
        {
            if (temp->val != reversedLL->val)
            {
                return false; // Not a palindrome if values differ
            }
            temp = temp->next;             // Move to the next node in the first half
            reversedLL = reversedLL->next; // Move to the next node in the reversed second half
        }

        return true; // All values matched, it's a palindrome
    }
};

// Helper function to create a linked list from an array
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

// Main function to test the solution
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ListNode *head = createLinkedList(arr, n);
    Solution solution;
    bool result = solution.isPalindrome(head);
    cout << (result ? "true" : "false") << endl;
    return 0;
}

/*
Time Complexity:
- The time complexity is O(n), where n is the number of nodes in the linked list. This is because we traverse the list to find the middle, then traverse the second half to reverse it, and finally traverse both halves to compare values.

Space Complexity:
- The space complexity is O(1), as we are using a constant amount of extra space (pointers) regardless of the input size.
*/
