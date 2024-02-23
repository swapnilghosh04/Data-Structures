#include <iostream>
#include <cstring> // include for string functions
#include <cctype>  // include for isalnum function

using namespace std;

class infixpostfix {
    char s[100];
public:
    int top = -1;
    void push(char x) {
        s[++top] = x;
    }
    char pop() {
        if (top == -1) // Corrected the condition here
            return -1;
        else
            return s[top--];
    }
    int priority(char x) {
        if (x == '(')
            return 0;
        if (x == '+' || x == '-')
            return 1;
        if (x == '*' || x == '/')
            return 2;
        return -1; // Return a value indicating an invalid operator
    }
};

int main() {
    infixpostfix ob;
    char s[100], exp[100], x, *e;
    cout << "Enter the expression: ";
    cin.getline(exp, 100); // Use getline to read entire line
    cout << endl;
    e = exp;
    while (*e != '\0') {
        if (isalnum(*e)) {
            cout << *e;
        } else if (*e == '(') {
            ob.push(*e);
        } else if (*e == ')') {
            while ((x = ob.pop()) != '(')
                cout << x;
        } else {
            while (ob.top != -1 && ob.priority(s[ob.top]) >= ob.priority(*e))
                cout << ob.pop();
            ob.push(*e);
        }
        e++;
    }
    while (ob.top != -1) {
        cout << ob.pop();
    }
    return 0;
}

