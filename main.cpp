#include <iostream>
#include <cstring>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(){
  Stack* stack = new Stack();
  Queue* queue = new Queue();

  stack->push('a');
  stack->push('b');
  stack->push('c');
  stack->display();
  cout << endl;

  stack->pop();
  stack->display();
  cout << endl;
  cout << stack->peek() << endl;
  cout << endl;
  stack->display();
  cout << endl;
  
  queue->enqueue('a');
  queue->enqueue('b');
  queue->enqueue('c');
  queue->display();
  cout << endl;
  queue->dequeue();
  queue->display();
  
  return 0;
}
