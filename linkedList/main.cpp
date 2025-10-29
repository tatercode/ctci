#include "linkedList.h"
#include <iostream>
#include <cstdlib>

int main() {
  srand(0);
  LinkedList list;

  for (int i = 0; i < 10; ++i) {
    int num = rand() % 5;
    list.insert(num);
  }
  list.printList();

  list.removeDupsNoBuff();

  std::cout << "After removing dups" << std::endl;
  list.printList();
  return 0;
}
