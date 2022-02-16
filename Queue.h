#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

class Queue{
 public:
  char data;
  Node* front;
  Node* rear;

  Queue();
  ~Queue();
  void enqueue(char newData);
  void dequeue();
  void display();
};
#endif
