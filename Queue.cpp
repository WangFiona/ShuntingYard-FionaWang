#include <iostream>
#include <cstring>
#include "Queue.h"
#include "Node.h"

/*
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This file is the implentation for the queue class
 */

//Constructor
Queue::Queue(){
  front=rear=NULL;
}

//Destructor
Queue::~Queue(){
  front=rear=NULL;
}

//Function for adding into the queue
//Referenced from GeeksforGeeks
void Queue::enqueue(char newData){
  Node* temp = new Node('\0');
  temp->data = newData;
  if(rear==NULL){
    front=rear=temp;
    return;
  }

  rear->next=temp;
  rear = temp;
}

//Function for deleting characters in the queue
//Referenced from GeeksforGeeks
void Queue::dequeue(){
  if(front!=NULL){
    Node* temp = front;
    front = front->next;
    if(front==NULL){
      rear = NULL;
    }
    delete(temp);
  }
}

//Function for displaying the entire queue
void Queue::display(){
  Node* temp;
  if(front!=NULL){
    temp=front;
    while(temp!=NULL){
      cout << temp->data;
      temp=temp->next;
    }
    cout << "\n";
  }
}

//Function for returning the entire postfix
char* Queue::returnPostfix(){
  char* postfix = new char[40];
  Node* temp;
  if(front!=NULL){
    temp=front;
    int x=0;
    while(temp!=NULL){
      postfix[x]=temp->data;
      x++;
      temp=temp->next;
    }
  }
  return postfix;
}
