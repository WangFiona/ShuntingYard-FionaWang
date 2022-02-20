#ifndef BSTACKNODE_H
#define BSTACKNODE_H
#include <iostream>
#include <cstring>
#include "TreeNode.h"

using namespace std;

/*
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This file is the interface for the BStackNode class
 * It is used in the stack when making the binary tree
 */

class BStackNode{
 public:
  //Initializing functions
  BStackNode(TreeNode* newData);
  ~BStackNode();

  //Initializing variables
  TreeNode* data;
  BStackNode* next;
};
#endif
