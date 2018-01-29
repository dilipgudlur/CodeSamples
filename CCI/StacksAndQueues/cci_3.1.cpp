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
//Approach2: Flexible space - Grow the stacks. This has not be implemented yet.

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
        vector<int> tmp(y,0); //initialize topIndex of each stack with 0
        topIndex = tmp;
        stackCapacity = x/y;
    }
    void pop(int stackIndex);
    void push(int stackIndex, int val);
    bool isEmpty(int stackIndex);
    bool isFull(int stackIndex);
    int top(int stackIndex);
    int getTopIndex(int stackIndex);
};

//returns the index where element has to be inserted
int FixedStack::getTopIndex(int stackIndex) {
    int index = (stackCapacity * stackIndex) + topIndex[stackIndex];
    return index; 
}

void FixedStack::push(int stackIndex, int val) {
    if(!isFull(stackIndex)) {
        int index = getTopIndex(stackIndex);
        stackBuffer[index] = val;
        topIndex[stackIndex]++;
    }  
}

void FixedStack::pop(int stackIndex) {
    if(!isEmpty(stackIndex)) {
        int index = getTopIndex(stackIndex) - 1;
        stackBuffer[index] = INT_MIN;
        topIndex[stackIndex]--;
    }
}

int FixedStack::top(int stackIndex) {
    if(!isEmpty(stackIndex)) { //show top only if empty
        int index = getTopIndex(stackIndex)-1;
        cout << "Top of stack " << stackIndex+1 << " is " << stackBuffer[index] << endl;
        return stackBuffer[index];
    }
    cout << "Stack " << stackIndex+1 << " is empty" << endl;
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
    fs.push(0,1); //0
    fs.push(1,5); //4
    fs.push(0,6); //1
    fs.push(2,9); //8
    fs.push(0,8); //2
    fs.push(0,1); //3
    fs.push(0,3); //will not be inserted
    
    fs.pop(1);
    fs.top(0);
    fs.top(1);
    fs.top(2);   
    return 0;   
}
