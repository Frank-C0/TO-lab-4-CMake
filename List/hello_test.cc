#include "linkedList.cc"
#include <gtest/gtest.h>
#include <cassert>  

// cmake -S . -B build
// cmake --build build
// cd build && ctest && cd ..


// new :  --> LIST
// append : LIST x E  --> LIST
// head    : LIST    -/-> ELEMENT (partial)
// tail    : LIST    -/-> LIST (partial)
// size    : LIST    --> INT
// isEmpty  : LIST   --> BOOL

// Axioms
// 1. size(new) == 0
// 2. size(append(L, E)) > 0
// 3. size(append(new, E)) == 1
// 4. empty(new) == True
// e. 5mpty(append(L, E)) = False
// 6. head(new) = error
// 7. head(append(append(new, E), F)) =   //primer elemento
// 8. tail(new) = error


// 1. size(new) == 0
TEST(ListTest, Axioma1){
  LinkedList<int> list;
  List<int> *newList = &list;

  EXPECT_TRUE(newList->size() == 0);
}
// 2. size(append(L, E)) > 0
TEST(ListTest, Axioma2Emptycase){
  LinkedList<int> list;
  List<int> *newList = &list;

  EXPECT_TRUE(newList->append(99)->size() > 0);
}

// 2. size(append(L, E)) > 0
TEST(ListTest, Axioma2NoEmptycase){
  LinkedList<int> list;
  List<int> *newList = &list;
  newList->append(11);
  newList->append(43);

  EXPECT_TRUE(newList->append(99)->size() > 0);
}

// 3. size(append(new, E)) == 1
TEST(ListTest, Axioma3){
  LinkedList<int> list;
  List<int> *newList = &list;

  EXPECT_TRUE(newList->append(99)->size() == 1);
}

// 4. empty(new) == True
TEST(ListTest, Axioma4){
  LinkedList<int> list;
  List<int> *newList = &list;

  EXPECT_TRUE(newList->isEmpty() == true);
}

// 5. 5mpty(append(L, E)) = False
TEST(ListTest, Axioma5){
  LinkedList<int> list;
  List<int> *newList = &list;

  EXPECT_TRUE(newList->append(99)->isEmpty() == false);
}
// 6. head(new) = error
TEST(ListTest, Axioma6){
  LinkedList<int> list;
  List<int> *newList = &list;

  ASSERT_DEATH(newList->head(), "Assertion*");
}
// 7. head(append(append(new, E), F)) =   //primer elemento
TEST(ListTest, Axioma7){
  LinkedList<int> list;
  List<int> *newList = &list;
  int E = 123;
  int F = 11;
  
  EXPECT_TRUE(newList->append(E)->append(F)->head() == E);
}

// 8. tail(new) = error
TEST(ListTest, Axioma8){
  LinkedList<int> list;
  List<int> *newList = &list;
  ASSERT_DEATH(newList->tail(), "Assertion*");
}

