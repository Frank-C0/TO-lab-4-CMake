#include "ArrayStack.cc"
#include "Stack.h"
#include "iostream"

using namespace std;

// $ g++ -o main .\main.cpp .\ArrayStack.cc .\Stack.h

int main() {
  
  ArrayStack<int> *stackArray = new ArrayStack<int>(5);

  Stack<int> *stack = stackArray;

  // Stack<int> *stack = new ArrayStack<int>(5);

  cout << "empty: " << stack->empty() << '\n';

  stack->push(2);
  stack->push(3);

  stackArray->print(cout);
  cout << "empty2: " << stack->empty() << '\n';

  stack->push(5);
  stack->push(6);
  stackArray->print(cout);
  stack->push(7);
  stackArray->print(cout);
  stack->push(9);
  stackArray->print(cout);

  stack->pop();
  stack->pop();
  stack->pop();

  stackArray->print(cout);
  //
  cout << "top: " << stack->top() << '\n';

  stack->push(24);
  stack->push(534);
  stack->push(56);
  stack->push(67);
  stack->push(87);
  stackArray->print(cout);
  stack->push(22);
  stack->push(24);
  stack->push(26);
  stack->push(27);
  stack->push(27);
  stack->push(34);
  stack->push(334);
  stack->push(36);
  stack->push(37);
  stack->push(3);
  stackArray->print(cout);

  delete stackArray;
}