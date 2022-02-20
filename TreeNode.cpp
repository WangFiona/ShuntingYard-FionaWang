#include <iostream>
#include "TreeNode.h"
#include <cstring>

using namespace std;

/* 
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This file is the implementation of the tree node class
 */

//Constructor for just a character
TreeNode::TreeNode(char newData){
  data = newData;
  left = NULL;
  right = NULL;
}

//Constructor for the character and nodes
TreeNode::TreeNode(char newData, TreeNode* newLeft, TreeNode* newRight){
  data = newData;
  left = newLeft;
  right = newRight;
}
