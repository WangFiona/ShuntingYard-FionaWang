#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

/*
 * Author: Fiona Wang
 * Date: Jan. 3, 2022
 * This is the node header file and contains get and set functions
 */

class Node{
 public:
  //Initializing node functions
  Node(char newData);
  ~Node();
  void setData(char newData);
  char getData();
  void setNext(Node* newNode);
  Node* getNext();

  //Initializing node variables
  char data;
  Node* next;
};
#endif
