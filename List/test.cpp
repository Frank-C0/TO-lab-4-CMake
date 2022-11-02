#include "linkedList.cc"
#include <iostream>

using namespace std;

int main() {
  LinkedList<int> l;
  // l.head();
  l.tail();
  cout << l.isEmpty() << false << true << '\n';
  l.append(1);
  l.append(3);
  l.append(3);
  l.append(2);
  l.append(4);
  l.print(cout);
  l.append(10, 3);
  l.print(cout);

  
  LinkedList<int> l2 = l;
  l2.print(cout);
  l2.append(7);
  l2.append(8);

  l2.print(cout);

  l.print(cout);
  l.append(11);
  l.append(22);
  l.print(cout);
}