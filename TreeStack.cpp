#include <iostream>
#include <cstring>
#include "TreeStack.h"
#include "BStackNode.h"

TreeStack::TreeStack(){
  top=NULL;
}

TreeStack::~TreeStack(){
  top=NULL;
}

void TreeStack::push(TreeNode* newData){
  BStackNode* temp = new BStackNode(NULL);
  temp->data=newData;
  temp->next=top;
  top=temp;
}

void TreeStack::pop(){
  BStackNode* temp;
  if(top!=NULL){
    temp=top;
    top=top->next;
    delete(temp);
  }
}

TreeNode* TreeStack::peek(){
  if(top!=NULL){
    return top->data;
  }
  else{
    return NULL;
  }
}

void TreeStack::display(){
  BStackNode* temp;
  if(top!=NULL){
    temp=top;
    while(temp!=NULL){
      cout << temp->data->data;
      temp=temp->next;
    }
    cout << endl;
  }
}

bool TreeStack::isEmpty(){
  if(top==NULL){
    return true;
  } else{
    return false;
  }
}
