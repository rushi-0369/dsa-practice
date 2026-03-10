#include <iostream>
using namespace std;

// stack<int>st;
// st.push()
// st.pop()
// st.top()
// st.sixe()

class Stack {
private:
    int size;
    int top;
    int* a;

public:
    // Constructor
    Stack(int s) {
        size = s;
        top = -1;
        a = new int[size];
    }

    // Destructor
    ~Stack() {
        delete[] a;
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << " to the stack\n";
        } else {
            top = top + 1;
            a[top] = value;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from the stack\n";
            return -1;
        } else {
            return a[top--];
        }
    }

    int peek(int i) {
        if (top - i + 1 < 0) {
            cout << "Not a valid position\n";
            return -1;
        } else {
            return a[top - i + 1];
        }
    }

    int getSize() {
        return top + 1;
    }

    int stackTop() {
        if (!isEmpty())
            return a[top];
        return -1;
    }

    int stackBottom() {
        if (!isEmpty())
            return a[0];
        return -1;
    }
};

int main() {
    Stack sp(5);

    sp.push(6);
    cout << sp.getSize();

    return 0;
}
