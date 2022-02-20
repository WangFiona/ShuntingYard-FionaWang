#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Node.h"

/*
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This file is the implementation of the stack class
 */

//Constructor
Stack::Stack(){
  top=NULL;
}

//Destructor
Stack::~Stack(){
  top=NULL;
}

//Function for pushing into the stack
void Stack::push(char newData){
  Node* temp = new Node('\0');
  temp->data=newData;
  temp->next=top;
  top=temp;
}

//Function for deleting the top variable in the stack
void Stack::pop(){
  Node* temp;
  if(top!=NULL){
    temp=top;
    top=top->next;
    delete(temp);
  }
}

//Function for looking at the top value
char Stack::peek(){
  if(top!=NULL){
    return top->data;
  }
  else{
    return '\0';
  }
}

//Function for displaying the entire stack
//Referenced from GeeksforGeeks
//https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
void Stack::display(){
  Node* temp;
  if(top!=NULL){
    temp=top;
    while(temp!=NULL){
      cout << temp->data;
      temp=temp->next;
    }
    cout << endl;
  }
}

//Function for checking if the stack is empty
bool Stack::isEmpty(){
  if(top==NULL){
    return true;
  } else{
    return false;
  }
}
