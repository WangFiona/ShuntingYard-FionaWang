#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

/*
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This file is the interface for the queue class
 */

class Queue{
 public:
  //Initializing variables
  char data;
  Node* front;
  Node* rear;

  //Initializing functions
  Queue();
  ~Queue();
  void enqueue(char newData);
  void dequeue();
  void display();
  char* returnPostfix();
};
#endif
