#include <iostream>
#include <cstring>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "TreeNode.h"
#include "BStackNode.h"
#include "TreeStack.h"

using namespace std;

/*
 * Author: Fiona Wang
 * Date: February 20, 2022
 * This is the main class for the shunting hard algorithm
 * The user can print out an infix, postfix, or prefix expression
 */

//Initialize functions
void infix(TreeNode* root);
void postfix(TreeNode* root);
void prefix(TreeNode* root);
int precedence(char operatr);
bool isOperator(char operatr);

int main(){
  //Initialize variables
  Stack* stack = new Stack();
  Queue* queue = new Queue();
  char input[30];
  char notation[15];
  char infixT[] = "infix";
  char postfixT[] = "postfix";
  char prefixT[] = "prefix";
  int prev=0;
  int now=0;

  //Ask the user for an input using infix notation
  cout << "Please enter a mathematical expression in infix notation (make sure to include a space between each token):" << endl;
  cin.get(input, 30);
  cin.get();

  //Check that the user put spaces between tokens
  for(int i=1; i<strlen(input); i=i+2){
    if(input[i]!=' '){
      cout << "Please include a space between each token" << endl;
      return 0;
    }
  }

  //Ask what type of notation the user would like to print out
  cout << "What notation would you like to translate to (infix, prefix, or postfix)?" << endl;
  cin.get(notation, 15);
  cin.get();

  //Allow both upper and lower case input
  for(int i=0; i < strlen(notation); i++) {
    notation[i] = tolower(notation[i]);
  }

  //Turn the infix input into postfix
  for(int i=0; i<strlen(input); i=i+2){
    if(isOperator(input[i])==false && input[i]!='(' && input[i]!=')'){
      //For numbers or variables
      queue->enqueue(input[i]);
    }
    else if(input[i]=='('){ //For opening parentheses
      stack->push(input[i]);
    }
    else if(input[i]==')'){ //For closing parentheses
      while(stack->isEmpty()==false && stack->peek()!='('){
	queue->enqueue(stack->peek());
	stack->pop();
      }
      stack->pop();
    }
    else { //For all five operators
      now=precedence(input[i]);

      if(now>prev){
	stack->push(input[i]);
      }
      else {
	while(stack->isEmpty()==false && now <= precedence(stack->peek())){
	  queue->enqueue(stack->peek());
	  stack->pop();
	}
	stack->push(input[i]);
      }

      prev=now;
    }
  }

  //Pop the rest of the stack
  while(stack->isEmpty()==false){
    queue->enqueue(stack->peek());
    stack->pop();
  }

  
  //Creating the binary expression tree
  TreeStack* treeStack = new TreeStack();
  TreeNode* root = new TreeNode('\0');
  char* postfixChar = queue->returnPostfix();

  //Go through the postfix expression
  //Referenced from Techie Delight
  for(int i=0; i<strlen(postfixChar); i++){
    if(isOperator(postfixChar[i])==false){ //For numbers and variables
      treeStack->push(new TreeNode(postfixChar[i]));
    }
    else if(isOperator(postfixChar[i])==true){ //For operators
      TreeNode* right = treeStack->peek();
      treeStack->pop();

      TreeNode* left = treeStack->peek();
      treeStack->pop();

      //Create a node using the operator
      TreeNode* node = new TreeNode(postfixChar[i], left, right);

      treeStack->push(node);
    }
  }

  root = treeStack->peek();

  //Print out the different notations
  if(strcmp(notation, infixT) == false){
    cout << "Infix notation:" << endl;
    infix(root);
    cout << endl;
  } else if(strcmp(notation, postfixT) == false){
    cout << "Postfix notation:" << endl;
    postfix(root);
    cout << endl;
  } else if(strcmp(notation, prefixT) == false){
    cout << "Prefix notation:" << endl;
    prefix(root);
    cout << endl;
  } else {
    cout << "Please enter infix, postfix, or prefix" << endl;
  }
  
  return 0;
}

//Function for printing in infix notation
void infix(TreeNode* root){
  if(root!=NULL){
    if(isOperator(root->data)==true){
      cout << '(';
    }
    infix(root->left);
    cout << root->data;
    infix(root->right);
    if(isOperator(root->data)==true){
      cout << ')';
    }
  }
}

//Function for printing in postfix notation
void postfix(TreeNode* root){
  if(root!=NULL){
    postfix(root->left);
    postfix(root->right);
    cout << root->data;
  }
}

//Function for printing in prefix notation
void prefix(TreeNode* root){
  if(root!=NULL){
    cout << root->data;
    prefix(root->left);
    prefix(root->right);
  }
}

//Check if the operator has a higher or lower precedence
int precedence(char operatr){
  int prec;
  if(operatr=='^') prec=3;
  else if(operatr=='*' || operatr=='/') prec=2;
  else if(operatr=='+' || operatr=='-') prec=1;
  else if(operatr=='(') prec=0;
  return prec;
}

//Determine if the input is an operator
bool isOperator(char operatr){
  if(operatr=='^' || operatr=='*' || operatr=='/' || operatr=='+' ||
     operatr=='-'){
    return true;
  } else{
    return false;
  }
}
