#include <iostream>
#include "TreeNode.h"
#include <cstring>

using namespace std;

TreeNode::TreeNode(char newData){
  data = newData;
  left = NULL;
  right = NULL;
}

TreeNode::TreeNode(char newData, TreeNode* newLeft, TreeNode* newRight){
  data = newData;
  left = newLeft;
  right = newRight;
}
