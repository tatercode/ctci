#include "MinStack.h"
#include <limits>
#include <iostream>


MinStack::MinStack() : head(nullptr) {}

void MinStack::push(int num) {
  if (!head) {
    head = new ListNode(num, num);
  } else {
    int newMin = std::min(num, head->minVal);
    ListNode* newNode = new ListNode(num, newMin);
    newNode->next = head;
    head = newNode;
  }
}

int MinStack::pop() {
    if (!head) {
      return std::numeric_limits<int>::max(); 
    }
    int tempVal = head->val;
    ListNode* tempNode = head;
    head = head->next;
    delete tempNode;
    return tempVal;
  }

int MinStack::getMin() {
  if (!head) {
    return std::numeric_limits<int>::max();
  }
  return head->minVal;
}

int MinStack::top() {
  if (!head) {
      return std::numeric_limits<int>::max();
  }
  return head->val;
}
