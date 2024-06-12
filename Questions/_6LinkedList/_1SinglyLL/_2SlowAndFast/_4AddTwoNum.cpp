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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;                        // Initialize carry to handle sum greater than 9
        ListNode *dummyNode = new ListNode(); // Dummy node to simplify code
        ListNode *temp = dummyNode;           // Temp node to traverse the new list

        // Loop until both lists and carry are processed
        while (l1 || l2 || carry)
        {
            int sum = 0; // Initialize sum for the current digit

            // Add value from l1 if it exists
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from l2 if it exists
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;                               // Add carry to the sum
            carry = sum / 10;                           // Calculate new carry
            ListNode *newNode = new ListNode(sum % 10); // Create new node with the current digit
            temp->next = newNode;                       // Link the new node to the result list
            temp = temp->next;                          // Move to the next position
        }

        // Return the next node of dummy node which is the head of the result list
        return dummyNode->next;
    }
};

// Helper function to create a linked list from an array of values
ListNode *createList(int arr[], int size)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode *node)
{
    while (node != nullptr)
    {
        cout << node->val;
        if (node->next != nullptr)
        {
            cout << " -> ";
        }
        node = node->next;
    }
    cout << endl;
}

int main()
{
    // Input for list 1
    int arr1[] = {2, 4, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode *l1 = createList(arr1, size1);

    // Input for list 2
    int arr2[] = {5, 6, 4};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode *l2 = createList(arr2, size2);

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}

/*
Time Complexity:
The time complexity of this solution is O(max(m, n)), where m and n are the lengths of the input lists l1 and l2 respectively. This is because we traverse each list once.

Space Complexity:
The space complexity is also O(max(m, n)) since we create a new list that at most contains the maximum of the lengths of l1 and l2 nodes plus one additional node for a possible carry.
*/
