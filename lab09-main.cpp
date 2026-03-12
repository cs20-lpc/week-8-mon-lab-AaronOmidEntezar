#include <iostream>
#include <string>
#include "../ArrayStack.hpp"
using namespace std;

int main() {
    ArrayStack<int> stackA(10);
    ArrayStack<int> stackB(10);

    // push 0 through 9 into stackA
    for (int i = 0; i < 10; i++) {
        stackA.push(i);
        cout << i;
        if (i < 9) cout << " ";
    }
    cout << endl;

    cout << "Stack A is full!" << endl;
    cout << "Stack A length: " << stackA.getLength() << endl;

    // copy A into B
    stackB = stackA;
    cout << "Stack B length: " << stackB.getLength() << endl;

    // try overflow push on B
    try {
        stackB.push(100);
    }
    catch (string&) {
        cout << "push: error, stack is full, avoiding overflow" << endl;
    }

    // pop 5 items from B and print them
    for (int i = 0; i < 5; i++) {
        try {
            int topVal = stackB.peek();
            cout << "Popping " << topVal << " from stack B" << endl;
            stackB.pop();
        }
        catch (string&) {
            cout << "pop error" << endl;
        }
    }

    cout << "Stack B length: " << stackB.getLength() << endl;

    // clear B
    stackB.clear();
    cout << "Stack B is now empty after being cleared" << endl;

    // underflow test
    try {
        stackB.pop();
    }
    catch (string&) {
        cout << "pop: error, stack is empty, avoiding underflow" << endl;
    }

    // empty peek test
    try {
        stackB.peek();
    }
    catch (string&) {
        cout << "peek: error, stack is empty, cannot access the top" << endl;
    }

    cout << "Stack A length: " << stackA.getLength() << endl;

    // copy constructor test
    ArrayStack<int> stackC(stackA);
    cout << "Stack C length: " << stackC.getLength() << endl;

    return 0;
}