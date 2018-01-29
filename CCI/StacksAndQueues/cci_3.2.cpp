#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

/*3.2 Stack Min: How would you design a stack which, in addition to push and pop, 
has a function min which returns the minimum element? Push, pop and min should all operate in 0(1) time.
*/

//Two approaches: 
//Approach1: While pushing each element, push the min value as observed by that node too. Make a data structure that stores min associated with a node. Drawback: lot of space
//Approach2: Keep a parallel stack that stores the min values. This is better in terms of space, min values are stored in stack only when a new smaller element is found
//Below code implements Approach 2

class MyStack {
private:
    vector<int> stack;
    vector<int> minstack;//add element to minstack only if a smaller element comes
    int stackCapacity;
    int top = 0;
    int minval = INT_MAX;
public:
    
    MyStack(int buffer):stack(buffer,INT_MIN) {
        stackCapacity = buffer;
        
    }
    void push(int val);
    void pop();
    int getMin(); 
};

void MyStack::push(int val) {
    if(top < stackCapacity) {//stack is not full
        stack[top] = val;
        top++;
        if(val < minval) {
            minstack.push_back(val);
            minval = minstack.back(); //assign last element of minstack to minval
        }
    }
    else
        cout << "Stack is full, cannot insert more elements" << endl;
}

void MyStack::pop() {
    if(top > 0) {
        top--;
        
        //remove element from minstack, adjust minval
        if(stack[top] == minval) {
            minstack.pop_back();
            if(!minstack.empty())
                minval = minstack.back();
            else
                minval = INT_MAX;
        }
        stack[top] = INT_MIN;
        
    }
}

int MyStack::getMin() {
    if(minstack.empty())
        return INT_MIN;
    else
        return minstack.back();
}

int main() {
    
    int stackbuffer = 12;
    MyStack st(stackbuffer);
    st.push(4);
    st.push(10);
    st.push(9);
    st.push(5);
    st.push(1);
    st.pop();
    //st.push(6);
    //st.push(5);
    //st.push(4);
    //st.push(3);
    //st.push(2);
    //st.push(1);
    //st.push(0);
    //st.push(11);

    cout << "Min element is " << st.getMin() << endl;;
    return 0;   
}
