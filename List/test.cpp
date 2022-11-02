#include "linkedList.h"
#include <iostream>

using namespace std;

int main() {
  LinkedList l;
  cout << l.isEmpty() << false << true << '\n';
  l.append(1);
  l.append(3);
  l.append(3);
  l.append(2);
  l.append(4);
  l.print();
  // l.append(6);
  // l.append(5);
  l.append(10, 3);
  l.print();
}