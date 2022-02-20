#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <cstring>

using namespace std;

/*
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This file is the interface for the tree node class
 * It is used when building the binary tree
 */

class TreeNode {
public:
  //Intializing the variables and functions
  TreeNode(char newData);
  TreeNode(char newData, TreeNode* newLeft, TreeNode* newRight);
  char data;
  TreeNode* left;
  TreeNode* right;
};
#endif
