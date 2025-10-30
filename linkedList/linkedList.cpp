#include "linkedList.h"
#include <iostream>
#include <unordered_set>

ListNode::ListNode(int val) : val(val), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    ListNode* current = head;
    std::unordered_set<ListNode*> visited;
    while (current != nullptr) {
        if (visited.count(current)) {
            break;
        }
        visited.insert(current);
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

void LinkedList::insertDupe(ListNode* node) {
  ListNode* current = head;

  while (current->next) {
    current = current->next;
  }

  current->next = node;
}

ListNode* LinkedList::getNode(int pos) {
  if (pos < 1) {
    return head;
  }
  ListNode* current = head;

  while (pos != 0) {
    // If invalid position just return head
    if (!current) {
      return head; 
    }
    --pos;
    current = current->next;
  }
  return current;
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

// O(n) time O(1) space
bool LinkedList::loopDetection() {
  if (!head || !head->next) return false;
  ListNode* current = head;
  ListNode* runner = head->next;

  while (runner && runner->next) {
    if (current == runner) {
      return true;
    }
    current = current->next;
    runner = runner->next->next;
  }  

  return false;
}

ListNode* LinkedList::kthToLast(int k) {
  // Handle edge cases for an empty list or invalid k.
  if (head == nullptr || k < 1) {
    return nullptr;
  }

  ListNode* p1 = head;
  ListNode* p2 = head;

  // Move p2 k nodes into the list.
  for (int i = 0; i < k; ++i) {
    if (p2 == nullptr) {
      return nullptr; // k is larger than the size of the list.
    }
    p2 = p2->next;
  }

  // Move p1 and p2 at the same pace. When p2 reaches the end,
  // p1 will be at the k-th to last element.
  while (p2 != nullptr) {
    p1 = p1->next;
    p2 = p2->next;
  }

  return p1;
}

void LinkedList::deleteMiddleNode(ListNode* node) {
  if (!node || !node->next) {
    return;
  }

  ListNode* next = node->next;
  node->val = next->val;
  node->next = next->next;

  delete next;
  return; 
}
