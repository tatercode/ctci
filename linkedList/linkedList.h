#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val);
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void insert(int val);
    void printList();
    void removeDups();
    void removeDupsNoBuff();

private:
    ListNode* head;
};
