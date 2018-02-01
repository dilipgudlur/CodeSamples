#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

/*3.5 Sort Stack: Write a program to sort a stack such that the smallest items are on the top. 
You can use an additional temporary stack, but you may not copy the elements into any other data 
structure (such as an array). The stack supports the following operations: push, pop, peek, and is Empty. 
*/

//Approach: For keeping the stack sorted, use another tmp stack to store elements. Instead of pushing all elements to the tmp stack, 
//push only those that are smaller than the incoming element. While st.top < incoming element, push st.top onto tmp stack, then push the incoming
//element to st, then push back the elements from tmp stack to st. Refer to sortAndPush function


/*This algorithm is O ( N2) time and O ( N) space. 
If we were allowed to use unlimited stacks, we could implement a modified quicksort or mergesort. 
With the mergesort solution, we would create two extra stacks and divide the stack into two parts. We would recursively sort each stack, 
and then merge them back together in sorted order into the original stack. Note that this would require the creation of two additional stacks per level of recursion. 
With the quicksort solution, we would create two additional stacks and divide the stack into the two stacks based on a pivot element. 
The two stacks would be recursively sorted, and then merged back together into the original stack. 
Like the earlier solution, this one involves creating two additional stacks per level of recursion*/

class SortedStack {
private:
    stack<int> st;
    stack<int> tmp;

public:
    void push(int val); //pushes an element into the stack
    void pop(); //removes an element from the stack
    int peek(); //shows the element at top of stack
    void sortAndPush(int val); //sorts such that smallest element is on top
};

void SortedStack::sortAndPush(int val) {
    
    //populate tmp, assuming st is already sorted
    while(!st.empty() && val > st.top()) {
        tmp.push(st.top());
        st.pop();
    }
    
    //Now either st is empty or val is lesser than st.top
    //In either case, insert val into st
    st.push(val);
    //Now repopulate st with the elements of tmp
    while(!tmp.empty()) {
        st.push(tmp.top());
        tmp.pop();
    }
}

void SortedStack::push(int val) {
    if(st.empty()) {
        st.push(val);
        return;
    }

    if(val > st.top())
        SortedStack::sortAndPush(val);
    else {
        st.push(val);
    }
}

void SortedStack::pop() {
    if(!st.empty()) {
        cout << "Pop " << st.top() << endl;
        st.pop();
        return;
    }
    cout << "No more elements left to pop" << endl;
}

int SortedStack::peek() {
    if(!st.empty()) {
        cout << "Top element is " << st.top() << endl;
        return st.top();
    }
    return INT_MIN;
}

int main() {
    SortedStack ss;
    ss.push(4);
    ss.peek();
    ss.push(1);
    ss.peek();
    ss.push(10);
    ss.peek();
    ss.push(9);
    ss.peek();
    ss.pop();
    ss.peek();
    ss.push(5);
    ss.peek();
    ss.push(1);
    ss.pop();
    ss.pop();
    ss.pop();
    ss.pop();
    ss.pop();
    ss.pop();
    return 0;   
}
