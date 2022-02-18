#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <cstring>

using namespace std;

class TreeNode {
public:
  TreeNode(char newData);
  TreeNode(char newData, TreeNode* newLeft, TreeNode* newRight);
  char data;
  TreeNode* left;
  TreeNode* right;
};
#endif
