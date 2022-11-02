#include "ArrayStack.cc"
#include <gtest/gtest.h>
#include <cassert>  

// cmake -S . -B build
// cmake --build build
// cd build && ctest && cd ..
// Demonstrate some basic assertions.

//  syntax (for STACK)
//     newstack:                       ------->  STACK
//     push    : STACK x INTEGER       --------> STACK
//     pop     : STACK                 --------> STACK
//     top     : STACK                 --------> INTEGER U {undefined}
//     empty   : STACK                 --------> BOOLEAN

// AXIOMS
//    1. pop(newstack)   = newstack
//    2. pop(push(S,I))  = S
//    3. top(newstack)   = undefined
//    4. top(push(S,I))  = I
//    5. empty(newstack) = true
//    6. empty(push(S,I))= false



//    1. pop(newstack)   = newstack
TEST(ArrayTest, Axioma1) {
  ArrayStack<int> stack(4);
  Stack<int> *newstack = &stack;

  EXPECT_TRUE(newstack->empty());

  ArrayStack<int> stack_copy = stack;
  Stack<int> *newstack_copy = &stack_copy;

  newstack->pop();
  EXPECT_TRUE(stack == stack_copy);
}

//    2. pop(push(S,I))  = S
TEST(ArrayTest, Axioma2EmptyCase) {
  ArrayStack<int> stack(4);
  Stack<int> *newstack = &stack;

  ArrayStack<int> stack_copy = stack;
  Stack<int> *newstack_copy = &stack_copy;

  int val_push = 5;
  newstack->push(val_push);
  newstack->pop();
  EXPECT_TRUE(stack == stack_copy);
}
   // 2. pop(push(S,I))  = S
TEST(ArrayTest, Axioma2NoEmptyCase) {
  ArrayStack<int> stack(4);
  Stack<int> *newstack = &stack;

  newstack->push(3);
  newstack->push(5);
  newstack->push(7);
  newstack->push(11);

  ArrayStack<int> stack_copy = stack;
  Stack<int> *newstack_copy = &stack_copy;
  
  int val_push = 5;
  newstack->push(val_push);
  newstack->pop();
  EXPECT_TRUE(stack == stack_copy);
}

void doAssert() {
    assert(true);
}
   // 3. top(newstack)   = undefined
TEST(ArrayTest, Axioma3){
  ArrayStack<int> stack(4);
  Stack<int> *newstack = &stack;
  doAssert();
  ASSERT_DEATH(newstack->top(), "Assertion `empty()*");
  
}

// 4. top(push(S,I))  = I
TEST(ArrayTest, Axioma4EmptyCase) {
  ArrayStack<int> stack(4);
  Stack<int> *newstack = &stack;
  
  int val_push = 5;
  newstack->push(val_push);
  EXPECT_TRUE(newstack->top() == val_push);
}
// 4. top(push(S,I))  = I
TEST(ArrayTest, Axioma4NoEmptyCase) {
  ArrayStack<int> stack(4);
  Stack<int> *newstack = &stack;

  newstack->push(3);
  newstack->push(5);
  newstack->push(7);
  newstack->push(11);
  
  int val_push = 5;
  newstack->push(val_push);
  EXPECT_TRUE(newstack->top() == val_push);
}

//    5. empty(newstack) = true
TEST(ArrayTest, Axioma5) {
  ArrayStack<int> stack(4);
  Stack<int> *newstack = &stack;

  EXPECT_TRUE(newstack->empty());
}

  // 6. empty(push(S,I))= false
TEST(ArrayTest, Axioma6) {
  ArrayStack<int> stack(4);
  Stack<int> *newstack = &stack;

  newstack->push(100);
  EXPECT_FALSE(newstack->empty());
}