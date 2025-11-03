#pragma once

struct ListNode {
  int val;
  int minVal;
  ListNode* next;

  ListNode(int v, int minV) : val(v), minVal(minV), next(nullptr) {}
};

class MinStack {
public:
  MinStack(); 
  void push(int num);
  int pop();
  int getMin(); 
  int top();

private:
  ListNode* head;
};
