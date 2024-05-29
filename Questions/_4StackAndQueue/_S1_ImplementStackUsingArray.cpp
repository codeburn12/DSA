#include <iostream>
using namespace std;

class MyStack
{
private:
    int arr[1000]; // Array to store stack elements
    int top;       // Index of the top element in the stack

public:
    // Constructor to initialize stack
    MyStack() { top = -1; }

    // Function to push an integer into the stack
    void push(int x);

    // Function to remove an item from the top of the stack
    int pop();
};

// Function to push an integer into the stack
void MyStack::push(int x)
{
    // Increment the top index and assign the value x to the new top position
    arr[++top] = x;
}

// Function to remove an item from the top of the stack
int MyStack::pop()
{
    // Check if the stack is empty
    if (top == -1)
    {
        // Return -1 if the stack is empty
        return -1;
    }
    else
    {
        // Return the top element and decrement the top index
        return arr[top--];
    }
}

int main()
{
    MyStack stack;
    int n, value;

    // Read the number of operations from the user
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string operation;
        cin >> operation;

        if (operation == "push")
        {
            cin >> value;
            stack.push(value);
        }
        else if (operation == "pop")
        {
            cout << stack.pop() << endl;
        }
    }

    return 0;
}

/*
Time Complexity:
- push(int x): O(1) because inserting an element at the end of an array is a constant-time operation.
- pop(): O(1) because removing an element from the end of an array is a constant-time operation.

Space Complexity:
- The space complexity of the stack is O(1) for each element, so for an array of size 1000, the space complexity is O(1000), which simplifies to O(1) as the array size is fixed.
*/
