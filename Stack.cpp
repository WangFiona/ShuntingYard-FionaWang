#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Node.h"

Stack::Stack(){
  top=NULL;
}

Stack::~Stack(){
  top=NULL;
}

void Stack::push(char newData){
  Node* temp = new Node('\0');
  temp->data = newData;
  temp->next=top;
  top=temp;
}

void Stack::pop(){
  Node* temp;
  if(top!=NULL){
    temp=top;
    top=top->next;
    delete(temp);
  }
}

char Stack::peek(){
  if(top!=NULL){
    return top->data;
  }
  else{
    return '\0';
  }
}

void Stack::display(){
  Node* temp;
  if(top!=NULL){
    temp=top;
    while(temp!=NULL){
      cout << temp->data << endl;
      temp=temp->next;
    }
  }
}
