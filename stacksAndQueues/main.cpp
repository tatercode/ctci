#include <iostream>
#include "MinStack.h"


int main(int argc, char* argv[]) {
  std::cout << "Design stack min" << std::endl;
  MinStack minStack;
  minStack.push(3);
  std::cout << "Pushed 3, Min is: " << minStack.getMin() << std::endl;
  minStack.push(7);
  std::cout << "Pushed 7, Min is: " << minStack.getMin() << std::endl;
  minStack.push(1);
  std::cout << "Pushed 1, Min is: " << minStack.getMin() << std::endl;
  minStack.push(10);
  std::cout << "Pushed 10, Min is: " << minStack.getMin() << std::endl;

  std::cout << "Popped: " << minStack.pop() << ", Min is now: " << minStack.getMin() << std::endl;
  std::cout << "Popped: " << minStack.pop() << ", Min is now: " << minStack.getMin() << std::endl;
  std::cout << "Popped: " << minStack.pop() << ", Min is now: " << minStack.getMin() << std::endl;

  return 0;
}
