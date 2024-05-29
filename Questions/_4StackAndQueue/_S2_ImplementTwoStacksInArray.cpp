#include <iostream>
using namespace std;

class twoStacks
{
public:
    int top1, top2;
    int *arr;
    int size;

    // Constructor to initialize the two stacks
    twoStacks()
    {
        int n = 1000; // Initialize size of array to 1000
        size = n;
        arr = new int[n];
        top1 = -1;   // Initialize top1 for stack1
        top2 = size; // Initialize top2 for stack2
    }

    // Function to push an integer into the stack1
    void push1(int x)
    {
        // Check for overflow
        if (top1 < top2 - 1)
        {
            arr[++top1] = x;
        }
        else
        {
            cout << "Stack Overflow" << endl;
            return;
        }
    }

    // Function to push an integer into the stack2
    void push2(int x)
    {
        // Check for overflow
        if (top1 < top2 - 1)
        {
            arr[--top2] = x;
        }
        else
        {
            cout << "Stack Overflow" << endl;
            return;
        }
    }

    // Function to remove an element from top of the stack1
    int pop1()
    {
        // Check for underflow
        if (top1 >= 0)
        {
            int x = arr[top1--];
            return x;
        }
        else
        {
            return -1; // Return -1 if stack1 is empty
        }
    }

    // Function to remove an element from top of the stack2
    int pop2()
    {
        // Check for underflow
        if (top2 < size)
        {
            int x = arr[top2++];
            return x;
        }
        else
        {
            return -1; // Return -1 if stack2 is empty
        }
    }
};

// Main function to test the twoStacks class
int main()
{
    twoStacks ts;
    int choice, stackNumber, value;

    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1: // Push operation
            cin >> stackNumber >> value;
            if (stackNumber == 1)
            {
                ts.push1(value);
            }
            else if (stackNumber == 2)
            {
                ts.push2(value);
            }
            break;
        case 2: // Pop operation
            cin >> stackNumber;
            if (stackNumber == 1)
            {
                cout << ts.pop1() << endl;
            }
            else if (stackNumber == 2)
            {
                cout << ts.pop2() << endl;
            }
            break;
        case 3: // Exit
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

/*
Time Complexity:
- push1(x) and push2(x) are O(1) operations.
- pop1() and pop2() are O(1) operations.

Space Complexity:
- The space complexity is O(n) where n is the size of the array, which is 1000 in this case.
*/
