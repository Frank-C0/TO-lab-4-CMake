#include "ArrayStack.h"
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

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
  if (size == ((pointer - data))) {
    resize();
  }
  *pointer = e;
  pointer = (pointer + 1);

  assert(empty() == false); // 6. empty(push(S,I))= false
  assert(top() == e);       // 4. top(push(S,I))  = I
}

template <typename T>
void ArrayStack<T>::pop() {
  if (empty()) {             // newstack equivale a empty
    assert(empty() == true); // 1. pop(newstack)   = newstack
    return;
  }
  pointer = pointer - 1;
  assert(true); // 2. pop(push(S,I))  = S  // ?? solo podria provarse haciendo una copia(o copia parcial) antes de pop y comparar.
}

template <typename T>
T ArrayStack<T>::top() {
  assert(empty() == false); // no definido para pila vacia // 3. top(newstack) = undefined // newstack = pila vacia
  return *(pointer - 1);
}

template <typename T>
bool ArrayStack<T>::empty() { return pointer == data; }

template <typename T>
void ArrayStack<T>::resize() {
  T *newData = new T[10];
  for (int i = 0; i < size; i++) {
    newData[i] = data[i];
  }
  pointer = newData + size;
  size += FACTOR;
  data = newData;
}

template <typename T>
void ArrayStack<T>::print(ostream &o) {
  // std::cout << "stack = " << pointer <<" "<<(pointer-data)<< " : ";
  std::cout << "stack z(" << (pointer - data) << ") : ";

  int n = pointer - data;
  for (int i = 0; i < n; i++) {
    o << data[i] << ", ";
  }
  o << "\n";
}