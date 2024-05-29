#include <iostream>
using namespace std;

class MyQueue
{
private:
    int arr[100005]; // Array to store queue elements
    int front;       // Index of the front element
    int rear;        // Index of the next element to be pushed

public:
    // Constructor to initialize front and rear
    MyQueue()
    {
        front = 0;
        rear = 0;
    }

    // Function to push an element x in a queue
    void push(int x)
    {
        arr[rear++] = x; // Assign the element to the rear index and increment the rear
    }

    // Function to pop an element from queue and return that element
    int pop()
    {
        if (front == rear)
        {
            return -1; // If the queue is empty, return -1
        }
        else
        {
            return arr[front++]; // Return the front element and increment the front index
        }
    }
};

int main()
{
    MyQueue q;
    int n;
    cin >> n; // Read the number of operations

    for (int i = 0; i < n; ++i)
    {
        int type;
        cin >> type; // Read the type of operation (1 for push, 2 for pop)
        if (type == 1)
        {
            int x;
            cin >> x; // Read the element to push
            q.push(x);
        }
        else if (type == 2)
        {
            cout << q.pop() << " "; // Pop an element and print it
        }
    }

    return 0;
}

/*
 * Time Complexity:
 * - The push operation takes O(1) time as it involves a simple assignment and increment operation.
 * - The pop operation takes O(1) time as it involves a simple check, assignment, and increment operation.
 *
 * Space Complexity:
 * - The space complexity is O(1) for the class variables (front and rear).
 * - The array `arr` has a fixed size of 100005, so the space complexity due to the array is O(1) (considering the size is a constant).
 */
