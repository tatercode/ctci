#include "linkedList.h"
#include <iostream>
#include <cstdlib>

std::string printBool(int val) {
  if (val) {
    return "true";
  }

  return "false";
}

int main() {
  srand(0);
  LinkedList list;

  for (int i = 0; i < 12; ++i) {
    int num = rand() % 30;
    list.insert(num);
  }
  list.printList();

  list.removeDupsNoBuff();

  std::cout << "After removing dups" << std::endl;

  list.printList();

  LinkedList loopList;
  loopList.insert(2);
  loopList.insert(5);
  loopList.insert(8);
  ListNode* dupe = loopList.getNode(1);
  loopList.insertDupe(dupe);

  bool checkLoop = loopList.loopDetection();

  std::cout << "There is a loop: " << printBool(checkLoop) << std::endl;

  ListNode* kthToLast = list.kthToLast(3);

  std::cout << "Kth to last is: " << kthToLast->val << std::endl;

  LinkedList list2;
  list2.insert(1);
  list2.insert(4);
  list2.insert(-10);

  ListNode* midOfList = list2.getNode(1); 

  list2.deleteMiddleNode(midOfList);
  list2.printList();



  return 0;
}







