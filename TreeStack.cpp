#include <iostream>
#include <cstring>
#include "TreeStack.h"
#include "BStackNode.h"

/*
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This file is the implementation of the tree stack class
 */

//Constructor
TreeStack::TreeStack(){
  top=NULL;
}

//Destructor
TreeStack::~TreeStack(){
  top=NULL;
}

//Function for pushing into the stack
void TreeStack::push(TreeNode* newData){
  BStackNode* temp = new BStackNode(NULL);
  temp->data=newData;
  temp->next=top;
  top=temp;
}

//Function for deleting the top value
void TreeStack::pop(){
  BStackNode* temp;
  if(top!=NULL){
    temp=top;
    top=top->next;
    delete(temp);
  }
}

//Function for looking at the top value
TreeNode* TreeStack::peek(){
  if(top!=NULL){
    return top->data;
  }
  else{
    return NULL;
  }
}

//Function for displaying the entire stack
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

//Function for checking if the stack is empty
bool TreeStack::isEmpty(){
  if(top==NULL){
    return true;
  } else{
    return false;
  }
}
