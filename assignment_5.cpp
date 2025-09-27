#include <iostream>
#include <string>
using namespace std;


bool isEmpty(int top) {
    return (top == -1);
}

bool isFull(int top) {
    return (top == 4);
}

class Stack {
    char s[5];   
    int top;     

public:
    // Constructor
    Stack() { top = -1; }

    // Push element
    void push(char ch) {
        if (isFull(top)) {
            cout << "Stack Overflow" << endl;
        } else {
            s[++top] = ch;
        }
    }

    // Pop element
    char pop() {
        if (isEmpty(top)) {
            // underflow case
            return '\0';
        } else {
            return s[top--];
        }
    }

    char peek() {
        if (isEmpty(top)) return '\0';
        return s[top];
    }


    bool empty() {
        return isEmpty(top);
    }


    bool checkParenthesis(const string &expr, string &errorMsg, string &fix) {
        for (int i = 0; i < (int)expr.size(); i++) {
            char ch = expr[i];

            if (ch == '(' || ch == '[' || ch == '{') {
                push(ch);
            }
            else if (ch == ')' || ch == ']' || ch == '}') {
                if (empty()) {
                    errorMsg = "Extra closing bracket '" + string(1, ch) +
                               "' at position " + to_string(i + 1);
                    fix = "Remove '" + string(1, ch) + "'";
                    return false;
                }
                char topChar = pop();
                if (!((topChar == '(' && ch == ')') ||
                      (topChar == '[' && ch == ']') ||
                      (topChar == '{' && ch == '}'))) {
                    char expected = (topChar == '(' ? ')' : (topChar == '[' ? ']' : '}'));
                    errorMsg = "Mismatched bracket: expected '" + string(1, expected) +
                               "' but found '" + string(1, ch) +
                               "' at position " + to_string(i + 1);
                    fix = "Replace '" + string(1, ch) + "' with '" + string(1, expected) + "'";
                    return false;
                }
            }
        }

        if (!empty()) {
            char unclosed = pop();
            char expected = (unclosed == '(' ? ')' : (unclosed == '[' ? ']' : '}'));
            errorMsg = "Unclosed opening bracket '" + string(1, unclosed) + "'";
            fix = "Add '" + string(1, expected) + "' at end";
            return false;
        }

        return true; // expression valid hai...
    }
};


int main() {
    cout << "Enter code/text (end with an empty line):\n";
    string line;
    int lineNo = 1;
    bool allGood = true;

    while (true) {
        getline(cin, line);
        if (line.empty()) 
            break; 

        Stack st;

        string errorMsg, fix;
        if (!st.checkParenthesis(line, errorMsg, fix)) {
            cout << "Error in Line " << lineNo << ": " << errorMsg << "\n";
            cout << "Suggested Fix: " << fix << "\n";
            allGood = false;
        }
        lineNo++;
    }

    if (allGood)
        cout << "\nThe equation " << line << " is balanced and correct!\n";
    else
        cout << "\nNeed to fix the above bracket issues.\n";

    return 0;
}
