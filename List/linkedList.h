#ifndef LinkedList_h
#define LinkedList_h

struct Node {
  int data;
  Node *next;
};
class LinkedList {
  Node *last;

public:
  LinkedList();              // new :  --> LIST
  LinkedList *append(int e); // append : LIST x E  --> LIST
  LinkedList *append(int e, int pos);
  int head();         // head    : LIST    -/-> ELEMENT (partial)
  LinkedList *tail(); // tail    : LIST    -/-> LIST (partial)
  int size();         // size    : LIST    --> INT
  bool isEmpty();     // isEmpty  : LIST   --> BOOL
  void print(ostream &);
};
#endif