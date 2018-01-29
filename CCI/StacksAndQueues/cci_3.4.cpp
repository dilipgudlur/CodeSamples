#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

/*3.4 Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks. 
*/

//Approach: Use the second stack to pop the elements from 1 stack and push to the other whenever a peek/pop is requested.
//Once the elements are pushed to the 2nd stack, pop the top most element, that is the oldest element that should be peeked/popped.
//Lazy-approach: instead of pushing the elements back to the 1st stack, keep the elements in the 2nd stack only and peek/pop from 2nd stack
//And push element happens to the 1st stack.

class MyQueue {
private:
    stack<int> newStack;
    stack<int> oldStack;
public:
    void push(int val); //pushes an element into the queue
    void pop(); //removes an element from the queue
    int peek(); //shows the element at front of queue
    void moveNewToOld(); //moves elements from new stack to old stack
};

void MyQueue::moveNewToOld() {
    while(!newStack.empty()) { //continue till new is emptied
        oldStack.push(newStack.top()); //push the topmost element of new stack into old stack 
        newStack.pop(); //remove from new stack
    }//now old stack has been populated,   
}

void MyQueue::push(int val) {
    newStack.push(val); //push to stack new
    cout << "Operation: push " << val << endl;
}

//lazy approach
void MyQueue::pop() {
    if(oldStack.empty()) {
        if(newStack.empty()) {
            cout << "No more elements left to pop" << endl;
            return;
        }
        else
            MyQueue::moveNewToOld();
    }
    cout << "Operation: pop " << oldStack.top() << endl;    
    oldStack.pop(); //remove the topmost element of old, this is the oldest element
}

int MyQueue::peek() {
    if(oldStack.empty()) {
        if(newStack.empty()) {
            cout << "No more elements left to peek" << endl;
            return INT_MIN;
        }
        else
            MyQueue::moveNewToOld();
    }
    cout << "Operation: peek " << oldStack.top() << endl;  
    return oldStack.top(); //show the topmost element of old, this is the oldest element
}

int main() {
    
   MyQueue mq;
    mq.push(4);
    mq.push(10);
    mq.push(9);
    mq.peek();
    mq.push(5);
    mq.push(1);
    mq.pop();
    mq.pop();
    mq.pop();
    mq.pop();
    mq.pop();
    mq.pop();
    mq.peek();
    return 0;   
}
