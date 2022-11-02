#ifndef ArrayStack_h
#define ArrayStack_h
#define FACTOR 10

#include "Stack.h"
#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class ArrayStack : public Stack<T> {

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
  void print(ostream &);
  int sizeUsed();
};

#endif