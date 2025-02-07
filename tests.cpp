#include <iostream>
#include <cassert>
#include "Stack.h"

void test_stack() {
    Stack<int> s;

    // Test: Stack should be empty initially
    assert(s.empty() && "Test Failed: Stack should be empty initially");

    // Test: Pushing elements
    s.push(10);
    s.push(20);
    s.push(30);
    assert(s.size() == 3 && "Test Failed: Stack size should be 3 after three pushes");
    assert(s.top() == 30 && "Test Failed: Top should be 30");

    // Test: Popping elements
    s.pop();
    assert(s.size() == 2 && "Test Failed: Stack size should be 2 after popping once");
    assert(s.top() == 20 && "Test Failed: Top should be 20 after popping 30");

    s.pop();
    assert(s.size() == 1 && "Test Failed: Stack size should be 1 after popping twice");
    assert(s.top() == 10 && "Test Failed: Top should be 10 after popping 20");

    // Test: Empty check after popping all elements
    s.pop();
    assert(s.empty() && "Test Failed: Stack should be empty after popping all elements");

    // Test: pop() should throw exception on empty stack
    try {
        s.pop();
        assert(false && "Test Failed: pop() should throw exception on empty stack");
    } catch (const std::out_of_range& e) {
        std::cout << "Test Passed: Exception caught for pop() on empty stack\n";
    }

    // Test: top() should throw exception on empty stack
    try {
        s.top();
        assert(false && "Test Failed: top() should throw exception on empty stack");
    } catch (const std::out_of_range& e) {
        std::cout << "Test Passed: Exception caught for top() on empty stack\n";
    }

    // Test: Clearing the stack
    s.push(100);
    s.push(200);
    s.clear();
    assert(s.empty() && "Test Failed: Stack should be empty after clear()");

    std::cout << "All tests passed!\n";
}

int main() {
    test_stack();
    return 0;
}
