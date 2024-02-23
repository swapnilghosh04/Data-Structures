#include <iostream>
#include <vector>
using namespace std;

class Stack {
    private:
        vector<int> stack;
    public:
        void initialize() {
            stack.clear();
        }
        bool isFull() {
            return false;
        }
        bool isEmpty() {
            return stack.empty();
        }
        void push(int num) {
            stack.push_back(num);
        }
        int pop() {
            if (isEmpty()) {
                cout << "Stack is Empty..." << endl;
                return 0;
            }
            int top = stack.back();
            stack.pop_back();
            return top;
        }
                void printStack() {
            if (isEmpty()) {
                cout << "Stack is Empty..." << endl;
                return;
            }
            for (auto it = stack.rbegin(); it != stack.rend(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
        void insertAtBottom(int item) {
            if (isEmpty()) {
                push(item);
            } else {
                int top = pop();
                insertAtBottom(item);
                push(top);
            }
        }
        void reverse() {
            if (stack.size() > 1) {
                int top = pop();
                reverse();
                insertAtBottom(top);
            }
        }
        int getSize() {
            return stack.size();
        }
};

int main() {
    Stack st;
    int num, choice;
    while (true) {
        cout << "1. Push\n2. Pop\n3. Print Stack\n4. Reverse\n5. Get Size\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number to push: ";
                cin >> num;
                st.push(num);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.printStack();
                break;
            case 4:
                st.reverse();
                break;
            case 5:
                cout << "Size: " << st.getSize() << endl;
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice, try again" << endl;
        }
    }
    return 0;
}
