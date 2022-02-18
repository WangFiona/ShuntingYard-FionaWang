#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstring>
#include "Node.h"
#include "TreeNode.h"

using namespace std;

class Stack{
public:
  Node* top;

  Stack();
  ~Stack();
  void push(char newData);
  void pop();
  char peek();
  void display();
  bool isEmpty();
};

#endif
