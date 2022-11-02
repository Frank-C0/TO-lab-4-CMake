#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
public:
  List();                // new :  --> LIST
  List *append(T e);     // append : LIST x E  --> LIST
  T head();              // head    : LIST    -/-> ELEMENT (partial)
  List *tail();          // tail    : LIST    -/-> LIST (partial)
  int size();            // size    : LIST    --> INT
  bool isEmpty();        // isEmpty  : LIST   --> BOOL
};

#endif


// new :  --> LIST
// append : LIST x E  --> LIST
// head    : LIST    -/-> ELEMENT (partial)
// tail    : LIST    -/-> LIST (partial)
// size    : LIST    --> INT
// isEmpty  : LIST   --> BOOL

// Axioms
// size(new) == 0
// size(append(L, E)) > 0
// size(append(new, E)) == 1
// empty(new) == True
// empty(append(L, E)) = False
// head(new) = error
// head(append(append(new, E), F)) =   //primer elemento
// tail(new) = error