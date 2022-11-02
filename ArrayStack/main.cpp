#include "ArrayStack.cpp"
#include "Stack.hpp"
#include "iostream"

using namespace std;
int main() {
    cout<<"print0";
  ArrayStack<int> *s = new ArrayStack<int>(10);
//   s->print();
cout<<"prin1";
  s->push(11);
  cout<<"print";
//   s->print();
  s->push(76);
//   s->print();
  s->push(54);
  s->print();
}