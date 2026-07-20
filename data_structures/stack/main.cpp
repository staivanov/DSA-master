#include <iostream>
#include "../stack/stack.cpp"
using namespace std;


int main(){

    Stack* stack = new Stack(5);
    stack->push(15);
    stack->push(55);
    stack->printStack();
    string tkn(15, '*');
    cout << tkn << endl;
    cout << "Popped value from the stack is : " << stack->pop() << endl;

    return 0;
};
