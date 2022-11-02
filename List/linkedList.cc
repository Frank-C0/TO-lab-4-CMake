#include "List.h"

#include <iostream>

using namespace std;

List::List() { last = nullptr; }
bool List::isEmpty() { return this->last == nullptr; }
List *List::append(int e) {
  if (isEmpty()) {
    // cout << "intent insert first " << e << '\n';
    last = new Node;
    last->data = e;
    last->next = last;
    // cout << "insert first " << e << '\n';
    return this;
  }
  // cout << "intent insert " << e << '\n';
  Node *n = new Node;
  n->data = e;
  n->next = last->next;
  last->next = n;
  last = n;
  // cout << "insert " << e << '\n';
  return this;
}

List *List::append(int e, int pos) {
  int n = size();
  if (pos == 0) {
    if (isEmpty()) {
      // cout << "intent insert first " << e << '\n';
      last = new Node;
      last->data = e;
      last->next = last;
      // cout << "insert first " << e << '\n';
      return this;
    }
    // cout << "intent insert " << e << '\n';
    Node *n = new Node;
    n->data = e;
    n->next = last->next;
    last->next = n;
    last = n;
    // cout << "insert " << e << '\n';
  }
	Node *iter = last;
	for(int i = 0; i<n && i<pos-1;i++){
		iter = iter->next;
		
	}
	Node *newNode = new Node;
	newNode->data=e;
	newNode->next=iter->next;
	iter->next=newNode;

  return this;
}

int List::head() { return last->next->data; }
int List::size() {
  if (isEmpty()) {
    return 0;
  }
  int c = 0;
  Node *iter = last;
  while (iter) {
    iter = iter->next;
    if (iter == last)
      iter = nullptr;
    c++;
  }
  return c;
}
void List::print(ostream &o) {
  if (isEmpty()) {
    o << "Vacio";
    return;
  }
  Node *iter = last;
  while (iter) {
    o << iter->data << ", ";
    iter = iter->next;
    if (iter == last)
      iter = nullptr;
  }
  o << '\n';
}