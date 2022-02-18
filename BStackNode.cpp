#include <iostream>
#include "BStackNode.h"
#include "TreeNode.h"
#include <cstring>

using namespace std;

BStackNode::BStackNode(TreeNode* newData) {
  data=newData;
  next=NULL;
}

//Node destructor                                                               
BStackNode::~BStackNode() {
  //delete &value;                                                              
  next=NULL;
}
