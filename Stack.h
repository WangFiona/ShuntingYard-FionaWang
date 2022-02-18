#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

class Stack{
public:
  char data;
  Node* top;

  Stack();
  ~Stack();
  void push(char newData);
  void pop();
  char peek();
  void display();
  bool isEmpty();
};

#endif
