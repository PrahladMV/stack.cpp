#include <iostream>
#include <stack>

class SpecialStack {
private:
    std::stack<int> mainStack; // to store elements
    std::stack<int> minStack;  // to keep track of the minimum element

public:
    // Function to push an element onto the stack
    void push(int value) {
        mainStack.push(value);

        // Update minStack if the new element is smaller or equal
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    // Function to pop the top element from the stack
    void pop() {
        if (!mainStack.empty()) {
            // If the top element of mainStack is the minimum, pop from minStack as well
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    // Function to get the minimum element from the stack
    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        } else {
            // Handle the case where the stack is empty
            std::cerr << "Stack is empty." << std::endl;
            return -1; // or any other appropriate value
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return mainStack.empty();
    }

    // Function to check if the stack is full
    bool isFull() {
        // Since we are not using a fixed-size array, the stack is not limited in size
        return false;
    }
};

int main() {
    SpecialStack specialStack;

    specialStack.push(3);
    specialStack.push(5);
    std::cout << "Minimum element: " << specialStack.getMin() << std::endl;

    specialStack.push(2);
    specialStack.push(1);
    std::cout << "Minimum element: " << specialStack.getMin() << std::endl;

    specialStack.pop();
    std::cout << "Minimum element after pop: " << specialStack.getMin() << std::endl;

    specialStack.pop();
    std::cout << "Minimum element after pop: " << specialStack.getMin() << std::endl;

    return 0;
}
