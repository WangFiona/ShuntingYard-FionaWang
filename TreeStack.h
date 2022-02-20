#ifndef TREESTACK_H
#define TREESTACK_H
#include <iostream>
#include <cstring>
#include "TreeNode.h"
#include "BStackNode.h"

using namespace std;

/*
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This file is the interface for the tree stack class
 * It is used when making the binary tree
 */

class TreeStack{
public:
  //Initializing the variable
  BStackNode* top;

  //Initializing the functions
  TreeStack();
  ~TreeStack();
  void push(TreeNode* data);
  void pop();
  TreeNode* peek();
  void display();
  bool isEmpty();
};
#endif
