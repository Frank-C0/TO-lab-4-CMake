#include "linkedList.h"

#include <iostream>
#include <string>

#include <cassert>
using namespace std;

// Axioms
// e1. size(new) == 0
// e2. size(append(L, E)) > 0
// e3. size(append(new, E)) == 1
// e4. empty(new) == True
// e5. empty(append(L, E)) = False
// e6. head(new) = error
// 7. head(append(append(new, E), F)) = E  //primer elemento
// e8. tail(new) = error

template <typename T>
LinkedList<T>::LinkedList() {
  last = nullptr;
  cout << "nullptr: " << (last != nullptr) << true << '\n';
  assert(isEmpty() == true); // 4. empty(new) == True
  assert(size() == 0);       // 1. size(new) == 0
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &s) {
  last = nullptr;
  if (!(s.last == nullptr)) {
    Node<T> *iter = s.last->next;
    while (true) {
      append(iter->data);
      iter = iter->next;
      if (iter == s.last) {
        append(iter->data);
        break;
      }
    }
  }
}

template <typename T>
bool LinkedList<T>::isEmpty() { return this->last == nullptr; }

template <typename T>
void LinkedList<T>::insertNextNode(Node<T> *node, T value) {
}

template <typename T>
LinkedList<T> *LinkedList<T>::append(int e) {
  if (isEmpty()) {
    last = new Node<T>;
    last->data = e;
    last->next = last;
    return this;
  }
  Node<T> *n = new Node<T>;
  n->data = e;
  n->next = last->next;
  last->next = n;
  last = n;

  assert(isEmpty() == false);                    // 5. empty(append(L, E)) = False
  assert(!(isEmpty() == true) && (size() != 1)); // 3. size(append(new, E)) == 1  // solo si  empty && size!=1,  falla
  assert(size() > 0);                            // 2. size(append(L, E)) > 0
  return this;
}

template <typename T>
LinkedList<T> *LinkedList<T>::append(int e, int pos) {
  if (isEmpty()) {
    return append(e);
  }
  Node<T> *iter = last;
  for (int i = 0; i < pos; i++) {
    iter = iter->next;
  }
  Node<T> *newNode = new Node<T>;
  newNode->data = e;
  newNode->next = iter->next;
  iter->next = newNode;
  return this;
}

template <typename T>
T LinkedList<T>::head() {
  assert(true);              // 7. head(append(append(new, E), F))=E // se necesitaria una variable para recordar que elemento se añadio primero
  assert(isEmpty() == false); // 6. head(new) = error // no definido para vacio
  return last->next->data;
}

// template <typename T>
// T LinkedList<T>::tail() {
//   assert(isEmpty() == true); // 8. tail(new) = error // no definido para vacio
//   Node<T> *iter = last;
//   while (iter->next != nullptr) {
//     iter = iter->next;
//   }
//   return iter->data;
// }
template <typename T>
LinkedList<T> *LinkedList<T>::tail() {
  assert(isEmpty() == false);   // 8. tail(new) = error // no definido para vacio

  LinkedList<T> *newList = new LinkedList<T>;

  Node<T> *iter = last->next->next;
  while (true) {
    newList->append(iter->data);
    iter = iter->next;
    if (iter == last) {
      newList->append(iter->data);
      break;
    }
  }

  return newList;
}

template <typename T>
int LinkedList<T>::size() {
  if (isEmpty()) {
    return 0;
  }
  int c = 0;
  Node<T> *iter = last;
  while (iter) {
    iter = iter->next;
    if (iter == last)
      iter = nullptr;
    c++;
  }
  return c;
}

template <typename T>
void LinkedList<T>::print(std::ostream &) {
  cout << "List (" << size() << "): ";
  if (!isEmpty()) {
    Node<T> *iter = last->next;
    while (true) {
      cout << iter->data << ", ";
      iter = iter->next;
      if (iter == last) {
        cout << iter->data << ", ";
        break;
      }
    }
  }
  cout << "end" << '\n';
}

template <typename T>
void LinkedList<T>::remove(int i) {
}