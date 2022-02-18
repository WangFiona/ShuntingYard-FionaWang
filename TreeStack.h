#ifndef TREESTACK_H
#define TREESTACK_H
#include <iostream>
#include <cstring>
#include "TreeNode.h"
#include "BStackNode.h"

using namespace std;

class TreeStack{
public:
  BStackNode* top;

  TreeStack();
  ~TreeStack();
  void push(TreeNode* data);
  void pop();
  TreeNode* peek();
  void display();
  bool isEmpty();
};
#endif
