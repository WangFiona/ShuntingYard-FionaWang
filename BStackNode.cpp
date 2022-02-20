#include <iostream>
#include "BStackNode.h"
#include "TreeNode.h"
#include <cstring>

using namespace std;

/* 
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This file is the implementation for the BStackNode class
 * It is used in the stack when making the binary tree
 */

//Constructor
BStackNode::BStackNode(TreeNode* newData) {
  data=newData;
  next=NULL;
}

//Node destructor
BStackNode::~BStackNode() {
  next=NULL;
}
