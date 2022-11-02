#include "./ArrayStack/ArrayStack.h"
#include <gtest/gtest.h>

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
TEST(ArrayTest, Axioma1Test) {
  ArrayStack<int> stack(4);
  Stack<int> *newstack = &stack;

  EXPECT_TRUE(newstack->empty());

  ArrayStack<int> stack_copy = stack;
  Stack<int> *newstack_copy = &stack_copy;

  newstack->pop();
  EXPECT_TRUE(stack == stack_copy);
}

//    2. pop(push(S,I))  = S
TEST(ArrayTest, Axioma2TestEmptyCase) {
  ArrayStack<int> stack(4);
  Stack<int> *newstack = &stack;

  ArrayStack<int> stack_copy = stack;
  Stack<int> *newstack_copy = &stack_copy;

  int val_push = 5;
  newstack->push(val_push);
  newstack->pop();
  EXPECT_TRUE(stack == stack_copy);
}
//    2. pop(push(S,I))  = S
TEST(ArrayTest, Axioma2TestNoEmptyCase) {
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

//    3. top(newstack)   = undefined
// TEST(ArrayTest, Axioma3TestNoEmptyCase){
//   ASSERT_DEATH({
//     ArrayStack<int> stack(4);
//     Stack<int> *newstack = &stack;
//     newstack.pop();
//   }, "Error on line .* of Foo()");
// }