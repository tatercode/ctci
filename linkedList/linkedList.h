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
    void printList(ListNode* temp);
    void removeDups();
    void removeDupsNoBuff();
    bool loopDetection();
    ListNode* kthToLast(int num);
    void deleteMiddleNode(ListNode* node);
    void partition(int val);
    ListNode* sumLists(ListNode* node1, ListNode* node2, int carry); 
    

private:
    ListNode* head;
};
