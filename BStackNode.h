#ifndef BSTACKNODE_H
#define BSTACKNODE_H
#include <iostream>
#include <cstring>
#include "TreeNode.h"

using namespace std;

class BStackNode{
 public:
  BStackNode(TreeNode* newData);
  ~BStackNode();
  
  TreeNode* data;
  BStackNode* next;
};
#endif
