#ifndef ArrayStack_h
#define ArrayStack_h
#define FACTOR 10

#include "Stack.hpp"
#include <cassert>

#include <iostream>

using namespace std;

template <typename T>
class ArrayStack {
  private:
  T *pointer;
  void resize();
  int size;
  T *data;

  public:
  ArrayStack(int);
  ~ArrayStack();
  void push(T);
  void pop();
  T top();
  bool empty();
  void print();
  int sizeUsed();
};

// AXIOMS
//    e1. pop(newstack)   = newstack   // solo nuevo stack
//    2. pop(push(S,I))  = S          // se cumple en cada momento (invariante)
//    e3. top(newstack)   = undefined  // solo nuevo stack
//    4. top(push(S,I))  = I          // se cumple en cada momento (invariante)
//    e5. empty(newstack) = true       // solo nuevo stack
//    6. empty(push(S,I))= false      // se cumple en cada momento (invariante)

template <typename T>
ArrayStack<T>::ArrayStack(int z) : size{z}, data{new T[size]} {
  pointer = data;
  assert(pointer == data);
  assert(empty()==true);    // 5. empty(newstack) = true
  // assert();
}
template <typename T>
int ArrayStack<T>::sizeUsed(){
  return pointer-data;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
  delete data;
}

template <typename T>
void ArrayStack<T>::push(T e) {

  // cout << "rrrrrr?" << pointer << " -d " << data << " - " << data[0] << " -<" << ((pointer - data) + 1) << " <> " << size << " \n";
  if (size == ((pointer - data) + 1)) {
    resize();
  }
  *pointer = e;
  pointer = (pointer + 1);

  // *(pointer + 1) = e;

  assert(empty()==false);
}

template <typename T>
void ArrayStack<T>::pop() {
  if (empty())
    assert(empty()==true);  // pop(newstack)   = newstack
    return;
  pointer--;
}

template <typename T>
T ArrayStack<T>::top() {
  assert(empty()==false); // no definido para pila vacia // 3. top(newstack) = undefined // newstack = pila vacia
  return *(pointer - 1);
}

template <typename T>
bool ArrayStack<T>::empty() { return pointer == data; }

template <typename T>
void ArrayStack<T>::resize() {
  std::cout << "resize"
            << " : \n";
  T *newData = new T[10];
  std::cout << "pass"
            << " : \n";
  for (int i = 0; i < size; i++) {
    newData[i] = data[i];

    std::cout << i << "r"
              << " : \n";
  }
  pointer = newData + size;
  size += FACTOR;
  data = newData;
}

template <typename T>
void ArrayStack<T>::print() {
  // std::cout << "stack p = " << pointer <<" "<<size<< " : ";
  int n = pointer - data;
  for (int i = 0; i < n; i++) {
    std::cout << data[i] << ", ";
  }
  std::cout <<" sz"<< this->sizeUsed() << "\n";
}

int main() {
  cout << "print0\n";
  ArrayStack<int> s(5);

  // s.print();
  s.push(2);
  s.push(3);
  
  s.print();
  s.push(5);
  s.push(6);
  s.print();
  s.push(7);
  s.print();
  s.push(9);
  s.print();
}

#endif