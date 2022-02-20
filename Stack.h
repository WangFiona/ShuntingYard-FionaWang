#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstring>
#include "Node.h"
#include "TreeNode.h"

using namespace std;

/*
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This file is the interface for the stack class
 */

class Stack{
public:
  //Initializing variables
  Node* top;

  //Initiazling functions
  Stack();
  ~Stack();
  void push(char newData);
  void pop();
  char peek();
  void display();
  bool isEmpty();
};

#endif
