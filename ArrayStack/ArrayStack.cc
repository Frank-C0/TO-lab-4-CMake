#ifndef ArrayStack_h
#define ArrayStack_h
#define FACTOR 10

// #include "Stack.hpp"
#include <cassert>

#include <iostream>

using namespace std;

template <typename T>
class Stack {
  // int data;
  public:
  // virtual Stack() {}
  // virtual ~Stack() {}
  virtual void push(T) = 0;
  virtual void pop() = 0;
  virtual T top() = 0;
  virtual bool empty() = 0;
};

template <typename T>
class ArrayStack : public Stack<T> {

  // private:
public:
  T *pointer;
  void resize();
  int size;
  T *data;

  // public:
  ArrayStack(int);
  ~ArrayStack();
  void push(T);
  void pop();
  T top();
  bool empty();
  void print(ostream &);
  int sizeUsed();
};

// AXIOMS
//    e1. pop(newstack)   = newstack   // solo nuevo stack
//    2. pop(push(S,I))  = S          // se cumple en cada momento (invariante)
//    e3. top(newstack)   = undefined  // solo nuevo stack
//    e4. top(push(S,I))  = I          // se cumple en cada momento (invariante)
//    e5. empty(newstack) = true       // solo nuevo stack
//    e6. empty(push(S,I))= false      // se cumple en cada momento (invariante)

template <typename T>
ArrayStack<T>::ArrayStack(int z) : size{z}, data{new T[size]} {
  pointer = data;
  assert(pointer == data);
  assert(empty() == true); // 5. empty(newstack) = true
  // assert();
}
template <typename T>
int ArrayStack<T>::sizeUsed() {
  return pointer - data;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
  delete data;
}

template <typename T>
void ArrayStack<T>::push(T e) {

  // cout << "rrrrrr?" << pointer << " -d " << data << " - " << data[0] << " -<" << ((pointer - data) + 1) << " <> " << size << " \n";
  if (size == ((pointer - data))) {
    resize();
  }
  *pointer = e;
  pointer = (pointer + 1);

  assert(empty() == false); // 6. empty(push(S,I))= false
  assert(top() == e);       // 4. top(push(S,I))  = I
  // assert()
  // cout << "size: " << (pointer - data) << "\n";
}

template <typename T>
void ArrayStack<T>::pop() {
  if (empty()) {    // newstack equivale a empty
    assert(empty() == true); // 1. pop(newstack)   = newstack   
    return;
  }
  pointer = pointer - 1;
  assert(true); // 2. pop(push(S,I))  = S  // ?? solo podria provarse haciendo una copia(o copia parcial) antes de pop y comparar.
  
  // cout << "pop: " << empty() << ' ' << pointer << ' ' << data << '\n';
  }

template <typename T>
T ArrayStack<T>::top() {
  // cout << "top: " << empty() << ' ' << pointer << ' ' << data << '\n';
  assert(empty() == false); // no definido para pila vacia // 3. top(newstack) = undefined // newstack = pila vacia
  return *(pointer - 1);
}

template <typename T>
bool ArrayStack<T>::empty() { return pointer == data; }

template <typename T>
void ArrayStack<T>::resize() {
  // std::cout << "resize"
  //           << " : \n";
  T *newData = new T[10];
  // std::cout << "pass"
  //           << " : \n";
  for (int i = 0; i < size; i++) {
    newData[i] = data[i];

    // std::cout << i << "r"
    //           << " : \n";
  }
  pointer = newData + size;
  size += FACTOR;
  data = newData;
}

template <typename T>
void ArrayStack<T>::print(ostream &o) {
  // std::cout << "stack p = " << pointer <<" "<<(pointer-data)<< " : ";
  // std::cout << "stack p = " << (pointer - data) << " : ";

  int n = pointer - data;
  for (int i = 0; i < n; i++) {
    o << data[i] << ", ";
  }
  // o << " sz" << this->sizeUsed() << "\n";
  o << "\n";
}

int main() {
  // cout << "print0\n";

  ArrayStack<int> *stackArray = new ArrayStack<int>(5);

  Stack<int> *stack = stackArray;  

  // Stack<int> *stack = new ArrayStack<int>(5);

  stack->push(2);
  stack->push(3);

  stackArray->print(cout);
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
  cout << "top: "<<stack->top() << '\n';

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

#endif