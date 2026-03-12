#include <iostream>
#include <string>
#include "ArrayStack.hpp"
using namespace std;

template <typename T>
void printBasicInfo(const ArrayStack<T>& s, const string& name) {
    cout << "----- " << name << " -----" << endl;
    cout << "Length: " << s.getLength() << endl;
    cout << "Max size: " << s.getMaxSize() << endl;
    cout << "Empty? " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "Full? " << (s.isFull() ? "true" : "false") << endl;
    cout << s << endl;
}

template <typename T>
void testRotate(ArrayStack<T>& s, typename Stack<T>::Direction dir, const string& label) {
    try {
        cout << "Rotating " << label << "..." << endl;
        s.rotate(dir);
        cout << s << endl;
    }
    catch (string error) {
        cout << "Exception: " << error << endl;
    }
}

template <typename T>
void testEmptyOperations(ArrayStack<T>& s, const string& name) {
    cout << "===== Testing empty operations on " << name << " =====" << endl;

    try {
        cout << "Attempting peek..." << endl;
        cout << s.peek() << endl;
    }
    catch (string error) {
        cout << "Exception: " << error << endl;
    }

    try {
        cout << "Attempting pop..." << endl;
        s.pop();
    }
    catch (string error) {
        cout << "Exception: " << error << endl;
    }

    try {
        cout << "Attempting rotate left..." << endl;
        s.rotate(Stack<T>::LEFT);
    }
    catch (string error) {
        cout << "Exception: " << error << endl;
    }

    cout << endl;
}

void testIntStack() {
    cout << "================ INT STACK TESTS ================\n" << endl;

    ArrayStack<int> s(5);
    printBasicInfo(s, "Initial int stack");

    testEmptyOperations(s, "int stack");

    cout << "Pushing 10, 20, 30..." << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s << endl;

    cout << "Peek: " << s.peek() << endl;
    printBasicInfo(s, "After pushes");

    testRotate(s, Stack<int>::RIGHT, "right");
    testRotate(s, Stack<int>::LEFT, "left");

    cout << "Popping once..." << endl;
    s.pop();
    cout << s << endl;

    cout << "Pushing 40 and 50..." << endl;
    s.push(40);
    s.push(50);
    cout << s << endl;

    cout << "Trying to push into full stack..." << endl;
    try {
        s.push(60);
    }
    catch (string error) {
        cout << "Exception: " << error << endl;
    }
    cout << endl;

    cout << "Testing copy constructor..." << endl;
    ArrayStack<int> copyStack(s);
    cout << "Original:\n" << s << endl;
    cout << "Copy:\n" << copyStack << endl;

    cout << "Modifying original by popping..." << endl;
    s.pop();
    cout << "Original after pop:\n" << s << endl;
    cout << "Copy should remain unchanged:\n" << copyStack << endl;

    cout << "Testing assignment operator..." << endl;
    ArrayStack<int> assigned(3);
    assigned.push(999);
    cout << "Assigned before = :\n" << assigned << endl;

    assigned = s;
    cout << "Assigned after = s:\n" << assigned << endl;

    cout << "Testing self-assignment..." << endl;
    assigned = assigned;
    cout << assigned << endl;

    cout << "Clearing assigned stack..." << endl;
    assigned.clear();
    cout << "After clear:" << endl;
    cout << assigned << endl;
}

void testStringStack() {
    cout << "================ STRING STACK TESTS ================\n" << endl;

    ArrayStack<string> s(4);

    cout << "Pushing strings..." << endl;
    s.push("apple");
    s.push("banana");
    s.push("cherry");
    cout << s << endl;

    cout << "Peek: " << s.peek() << endl;

    testRotate(s, Stack<string>::RIGHT, "right");
    testRotate(s, Stack<string>::LEFT, "left");

    cout << "Popping top..." << endl;
    s.pop();
    cout << s << endl;

    cout << "Pushing date..." << endl;
    s.push("date");
    cout << s << endl;

    cout << "Pushing elderberry..." << endl;
    s.push("elderberry");
    cout << s << endl;

    cout << "Trying one more push on full stack..." << endl;
    try {
        s.push("fig");
    }
    catch (string error) {
        cout << "Exception: " << error << endl;
    }
    cout << endl;
}

void testSingleElementRotate() {
    cout << "================ SINGLE ELEMENT ROTATE TEST ================\n" << endl;

    ArrayStack<int> s(3);
    s.push(42);
    cout << s << endl;

    try {
        s.rotate(Stack<int>::LEFT);
    }
    catch (string error) {
        cout << "Exception: " << error << endl;
    }
    cout << endl;
}

void testBadConstructor() {
    cout << "================ BAD CONSTRUCTOR TEST ================\n" << endl;

    try {
        ArrayStack<int> bad(0);
    }
    catch (string error) {
        cout << "Exception: " << error << endl;
    }

    try {
        ArrayStack<int> bad2(-5);
    }
    catch (string error) {
        cout << "Exception: " << error << endl;
    }

    cout << endl;
}

int main() {
    testBadConstructor();
    testIntStack();
    testStringStack();
    testSingleElementRotate();

    return 0;
}