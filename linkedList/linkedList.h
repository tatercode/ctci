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
    void insertDupe(ListNode* node);
    ListNode* getNode(int pos);
    void printList();
    void removeDups();
    void removeDupsNoBuff();
    bool loopDetection();
    ListNode* kthToLast(int num);
    void deleteMiddleNode(ListNode* node);

private:
    ListNode* head;
};
