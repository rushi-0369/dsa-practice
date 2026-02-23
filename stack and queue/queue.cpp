#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int frontInd;
    int backInd;
    int* a;

public:
    // Constructor
    Queue(int s) {
        size = s;
        frontInd = -1;
        backInd = -1;
        a = new int[size];
    }

    // Destructor
    ~Queue() {
        delete[] a;
    }

    bool isFull() {
        return backInd == size - 1;
    }

    bool isEmpty() {
        return frontInd == backInd;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
        } else {
            backInd = backInd+1;
            a[backInd] = value;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "No element to dequeue\n";
            return -1;
        } else {
            return a[++frontInd];
        }
    }

    int peek(int i) {
        if (backInd - i + 1 < 0) {
            cout << "Not a valid position\n";
            return -1;
        } else {
            return a[backInd - i + 1];
        }
    }

    int getSize() {
        return backInd + 1;
    }

    int queueTop() {
        if (!isEmpty())
            return a[backInd];
        return -1;
    }

    int queueBottom() {
        if (!isEmpty())
            return a[0];
        return -1;
    }
};

int main() {
    Queue q(10);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;
    cout << q.queueTop() << endl;

    return 0;
}
