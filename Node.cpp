#include <iostream>
#include "Node.h"
#include <cstring>

using namespace std;

/*
 * Author: Fiona Wang
 * Date: January 11, 2022
 * This is the node cpp file
 */

//Creating and setting node variables
Node::Node(char newData) {
  data=newData;
  next=NULL;
}

//Node destructor
Node::~Node() {
  //delete &value;
  next=NULL;
}

//Function for setting student information
void Node::setData(char newData){
  data=newData;
}

//Function for getting student information
char Node::getData(){
  return data;
}

//Function for setting new nodes
void Node::setNext(Node* newNode){
  next=newNode;
}

//Function for getting the nodes
Node* Node::getNext(){
  return next;
}
