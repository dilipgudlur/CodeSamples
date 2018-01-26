
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

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

public:
    FixedStack(int x, int y): stackBuffer(x,0) { //initializes stack buffer to size x
        numStacks = y;
        for(int i = 0;i < x;i++) {
            cout << stackBuffer[i] <<endl;
        }
    }
    void pop();
    void push(int stackIndex, int val);
    bool isEmpty(int stackIndex);
    int top(int stackIndex);
};

void FixedStack::push(int stackIndex, int val) {
}

void FixedStack::pop() {
}

int FixedStack::top(int stackIndex) {
    return 0;
}

bool FixedStack::isEmpty(int stackIndex) {
    return false;
}

int main() {
    
    FixedStack fs(12,3);
    fs.push(0,1);
    fs.push(1,5);
    fs.push(2,3);
    fs.top(0);
    fs.top(1);
    fs.top(2);
    return 0;   
}
