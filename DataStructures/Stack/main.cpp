#include <iostream>
#include "../Stack/Stack.cpp"
using namespace std;


int main(){

    Stack* stack = new Stack(5);
    stack->printStack();


    return 0;
};