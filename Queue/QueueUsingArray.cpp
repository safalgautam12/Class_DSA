#include <iostream>
using namespace std;

#define n 100

class Queue {
public:
    int front, rear;
    int *arr;

    Queue() {
        front = rear = -1;
        arr = new int[n];
    }

    void push(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        front++;
        if (front > rear) {
            front = rear = -1; // Resetting queue when it becomes empty
        }
    }

    void top() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Top element is: " << arr[front] << endl;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == n - 1);
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q;
    cout << "Pushing 1, 2, 3, and 4 to the queue\n";
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.top();
    cout << "Popping element...................\n";
    q.pop();
    q.top();
    cout << "Popping element...................\n";
    q.pop();
    q.top();
    cout << "Popping element...................\n";
    q.pop();
    q.top();
    cout << "Popping element...................\n";
    q.pop();
    q.top(); // This should now show the queue is empty.

    return 0;
}
