#include <iostream>
#include <cstring>
#include "Queue.h"
#include "Node.h"

Queue::Queue(){
  front=rear=NULL;
}

Queue::~Queue(){
  front=rear=NULL;
}

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
