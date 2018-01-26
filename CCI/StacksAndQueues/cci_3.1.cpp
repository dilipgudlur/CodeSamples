#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

/*3.1 Three in One: Describe how you could use a single array to implement three stacks.
*/

//Two approaches: 
//Approach1: Split the fixed array into multiple stacks of equal size, each stack will grow in its allocated space
//Approach2: Flexible space - Grow the stacks 

//Tricks: see how the buffer is intialized in the constructor

class FixedStack {

private:
    int numStacks;
    vector<int> stackBuffer;
    vector<int> topIndex;
    int stackCapacity;

public:
    FixedStack(int x, int y): stackBuffer(x,INT_MIN)  { //initializes stack buffer to size x
        if(x < 1 || y < 1) {
            cout << "Improper Stack Sizes" << endl;
            return;
        }
        numStacks = y;
        /*for(int i = 0;i < x;i++) {
            cout << stackBuffer[i] <<endl;
        }*/
        vector<int> tmp(y,0); //initialize topIndex of each stack with 0
        topIndex = tmp;
        /*for(int i = 0;i < y;i++) {
            cout << topIndex[i] <<endl;
        }*/
        stackCapacity = x/y;
    }
    void pop(int stackIndex);
    void push(int stackIndex, int val);
    bool isEmpty(int stackIndex);
    bool isFull(int stackIndex);
    int top(int stackIndex);
};

void FixedStack::push(int stackIndex, int val) {
    if(!isFull(stackIndex)) {
        int index = (stackCapacity * stackIndex) + topIndex[stackIndex];
        stackBuffer[index] = val;
        topIndex[stackIndex]++;
    }
    
}

void FixedStack::pop(int stackIndex) {
    if(!isEmpty(stackIndex)) {
        int index = (stackCapacity * stackIndex) + topIndex[stackIndex]-1;
        stackBuffer[index] = INT_MIN;
        topIndex[stackIndex]--;
    }
}

int FixedStack::top(int stackIndex) {
    int index = (stackCapacity * stackIndex) + topIndex[stackIndex]-1;
    int result = stackBuffer[index];
    cout << "Top of stack " << stackIndex+1 << " is " << result << endl;
    return stackBuffer[index];
}

bool FixedStack::isEmpty(int stackIndex) {
    if(!topIndex[stackIndex])
        return true;
    return false;
}

bool FixedStack::isFull(int stackIndex) {
    if(topIndex[stackIndex] == stackCapacity)
        return true;
    return false;
}

int main() {
    
    int bufferSize = 12;
    int numStacks = 3;
    FixedStack fs(bufferSize,numStacks);
    fs.push(0,1);
    fs.push(1,5);
    fs.push(2,3);
    fs.pop(1);
    fs.top(0);
    fs.top(1);
    fs.top(2);
    return 0;   
}
