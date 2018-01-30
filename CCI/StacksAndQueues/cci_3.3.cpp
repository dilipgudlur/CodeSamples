#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

/*3.3 Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple. 
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. 
Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks 
and should create a new stack once the previous one exceeds capacity. SetOfStacks. push() and SetOfStacks. pop() 
should behave identically to a single stack (that is, pop () should return the same values as it would if there 
were just a single stack). FOLLOW UP Implement a function popAt(int index) which performs a pop operation on a 
specific substack. 
*/

//Approach: Use vector of stacks
//Incomplete: popAt function has not been implemented, needs shifting of elements

class SetOfStacks {
private:
    vector<stack<int>> SoS; //data structure: vector of integer stacks
    int stackCapacity;
    int stackIndex = 0;
public:
    
    SetOfStacks(int threshold) {
        stackCapacity = threshold;
        SetOfStacks::createNewStack(); //first stack in the vector added
    }
    void push(int val);
    void pop();
    int popAt(int index);
    void createNewStack();
};

void SetOfStacks::createNewStack() {
    stack<int> tmp;
    SoS.push_back(tmp);
}

void SetOfStacks::push(int val) {

    if((int)SoS[stackIndex].size() == stackCapacity) {
        stackIndex++;
        SetOfStacks::createNewStack();
    }
    SoS[stackIndex].push(val);
}

void SetOfStacks::pop() {
    if(SoS[stackIndex].empty()) {
        SoS.pop_back();
        stackIndex--;
        if(stackIndex < 0) {
            cout << "No more elements to pop" << endl;
            return;
        }
    }
    SoS[stackIndex].pop();
}

//this pops an element from a stack at a specific index, either you could keep the stack at less than capacity or 
//have to shift the elements from the next stack to fill this stack to capacity
int SetOfStacks::popAt(int index) {
    
    return 0;
}

int main() {
    
    int stackthreshold = 2;
    SetOfStacks st(stackthreshold);
    st.push(4);
    st.push(10);
    st.push(9);
    st.push(5);
    st.push(1);
    st.pop();
    return 0;   
}
