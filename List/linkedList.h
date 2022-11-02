#ifndef LinkedList_h
#define LinkedList_h

#include "list.h"
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
  };

template <typename T>
class LinkedList : public List<T>{

  private:
  Node<T> *last;
  void insertNextNode(Node<T>*, T);

  public:

  LinkedList(const LinkedList &s);  // copy construtor

  LinkedList();                           // new :  --> LIST
  LinkedList<T> *append(int e);           // append : LIST x E  --> LIST
  LinkedList<T> *append(int e, int pos);  
  T head();                               // head    : LIST    -/-> ELEMENT (partial)
  LinkedList<T> *tail();                  // tail    : LIST    -/-> LIST (partial)  ???
  // T tail(); 
  int size();                             // size    : LIST    --> INT
  bool isEmpty();                         // isEmpty  : LIST   --> BOOL

  void remove(int i);

  void print(ostream &);
};

#endif