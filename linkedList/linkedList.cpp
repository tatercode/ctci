#include "linkedList.h"
#include <iostream>
#include <unordered_set>

ListNode::ListNode(int val) : val(val), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

void LinkedList::insert(int val) {
    if (head == nullptr) {
        head = new ListNode(val);
        return;
    }

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new ListNode(val);
}

void LinkedList::printList() {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << "->";
        temp = temp->next;
    }
    std::cout << "null" << std::endl;
}

// O(n)
void LinkedList::removeDups() {
  ListNode* temp = head;
  ListNode* prev = nullptr;
  
  std::unordered_set<int> exists;

  while (temp != nullptr) {
    if (exists.count(temp->val)) {
      prev->next = temp->next;
      ListNode* nodeToDelete = temp;
      temp = temp->next;
      delete nodeToDelete;
      continue;
    }
    prev = temp;
    exists.insert(temp->val);
    temp = temp->next;
  }
}

// O(n^2) time complexity 
void LinkedList::removeDupsNoBuff() {
  ListNode* current = head;
  while (current != nullptr) {
    ListNode* runner = current;
    while (runner->next != nullptr) {
      if (runner->next->val == current->val) {
        runner->next = runner->next->next;
      } else {
        runner = runner->next;
      }
    }
    current = current->next;
  }
}











