#include <iostream>
#include <cstring>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "TreeNode.h"
#include "BStackNode.h"
#include "TreeStack.h"

using namespace std;

int precedence(char operatr);

int main(){
  Stack* stack = new Stack();
  Queue* queue = new Queue();
  char input[30];
  char expression[20];
  char notation[15];
  int prev=0;
  int now=0;

  cout << "Please enter a mathematical expression using infix notation (include a space between each token):" << endl;
  cin.get(input, 30);
  cin.get();

  cout << "What notation would you like to translate to (infix, prefix, or postfix)?" << endl;
  cin.get(notation, 15);
  cin.get();

  /*int x=0;
  for(int i=0; i<strlen(input); i=i+2){
    expression[x]=input[i];
    x++
    }*/

  for(int i=0; i<strlen(input); i=i+2){
    if(input[i]>='0' && input[i]<='9'){
      queue->enqueue(input[i]);
    }
    else if(input[i]=='('){
      stack->push(input[i]);
    }
    else if(input[i]==')'){
      while(stack->isEmpty()==false && stack->peek()!='('){
	queue->enqueue(stack->peek());
	stack->pop();
      }
      stack->pop();
    }
    else{
      now=precedence(input[i]);

      if(now>prev){
	stack->push(input[i]);
      }
      else {
	while(stack->isEmpty()==false && now <= precedence(stack->peek())){
	  queue->enqueue(stack->peek());
	  stack->pop();
	  //cout << "test" << endl;
	}
	stack->push(input[i]);
      }

      prev=now;
    }
  }

  while(stack->isEmpty()==false){
    queue->enqueue(stack->peek());
    stack->pop();
  }

  queue->display();
  
  return 0;
}

int precedence(char operatr){
  int prec;
  if(operatr=='^') prec=3;
  else if(operatr=='*' || operatr=='/') prec=2;
  else if(operatr=='+' || operatr=='-') prec=1;
  else if(operatr=='(') prec=0;
  return prec;
}
