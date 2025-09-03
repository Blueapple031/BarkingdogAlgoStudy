#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <functional>

using namespace std;

template <typename T>
class StackException : public runtime_error {
    const T value;
public:
    StackException(const string& msg, const T& value = T{})
        : runtime_error(msg), value(value) {}

    T getValue() const { return value; }
};

template <typename T>
class Stack {
    int size;
    int top;
    T* items;

    pair<function<bool(const T&)>, string> itemValidCondition;

public:
    Stack(int _size)
        : size(_size) {
        top = 0;
        items = new T[size];
    }

    void pop() {
        if (top == 0) {
            throw StackException<T>("Stack is Empty!", 0);
        }
        top--;
    }

    void push(const T& obj) {
        if (!itemValidCondition.first(obj)) {
            throw StackException<T>(itemValidCondition.second, obj);
        }
        if (top == size) {
            throw StackException<T>("Stack is Full!", obj);
        }
        items[top++] = obj;
    }

    void setItemValidCondition(function<bool(const T&)> condition, const string& msg) {
        itemValidCondition.first = condition;
        itemValidCondition.second = msg;
    }

    friend ostream& operator<<(ostream& os, const Stack<T>& stack) {
        if (stack.top == 0) {
            os << "Stack is empty!";
        } else {
            for (int i = 0; i < stack.top; ++i) {
                os << stack.items[i];
            }
            os << '\n';
        }
        return os;
    }
};

int main() {
    Stack<char> alphabetStack(3);
    alphabetStack.setItemValidCondition([](const char c) { return isalpha(c); }, "Only alphabet allowed!");
    
    try {
        alphabetStack.pop(); //element가 없는데 pop을 요청 error! "Stack is Empty!" 출력
    }
    catch (const StackException<char>& e) {
        cerr << e.what() << endl;
    }

    try {
        alphabetStack.push('A');
        alphabetStack.push('5'); //alphabetStack인데 숫자를 push error! "Only alphabet allowed!" 출력
    }
    catch (const StackException<char>& e) { 
        cerr << e.what() << endl;
    }

    try {
        alphabetStack.push('B');
        alphabetStack.push('C');
        alphabetStack.push('D'); //3개를 넘음 error! "Cannot Push: D" 출력
    }
    catch (const StackException<char>& e) {
        cerr << e.what() << endl;
        cerr << "Cannot push: " << e.getValue() << endl;
    }

    cout << alphabetStack;

    Stack<int> positiveNumbers(3);
    function<bool(const int)> condition = [](const int item) { return item > 0; };
    positiveNumbers.setItemValidCondition(condition, "Only positive number allowed!");

    try {
        positiveNumbers.push(100);
        positiveNumbers.push(-10); // 음수 push! error! "Only positive number allowed!"
        positiveNumbers.push(200);
    }
    catch (const StackException<int>& e) {
        cerr << e.what() << endl;
    }
}
