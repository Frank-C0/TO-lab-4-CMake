#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
  public:
  // new :  --> LIST
  virtual List<T> *append(T e) = 0; // append : LIST x E  --> LIST
  virtual T head() = 0;             // head    : LIST    -/-> ELEMENT (partial)
  virtual List<T> *tail() = 0;      // tail    : LIST    -/-> LIST (partial) ???
  // virtual T tail() = 0;      
  virtual int size() = 0;           // size    : LIST    --> INT
  virtual bool isEmpty() = 0;       // isEmpty  : LIST   --> BOOL
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