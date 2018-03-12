/*8.6 Towers of Hanoi: In the classic problem of the Towers of Hanoi, you have 3 towers and N disks 
of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending 
order of size from top to bottom (i.e., each disk sits on top of an even larger one). 
You have the following constraints: 
(1) Only one disk can be moved at a time. 
(2) A disk is slid off the top of one tower onto another tower. 
(3) A disk cannot be placed on top of a smaller disk. 
Write a program to move the disks from the first tower to the last using Stacks. */

/*Approach: Use recursion, base case and build approach. Consider each of the tower as a stack.
There are three stacks, origin, destination and buffer. Initially the origin stack is full, at the end 
of operations, aim to move all the disks from origin to destination tower using the buffer tower when
required. 

For 1 disk, it will take 1 operation.
For 2 disks, it will take 1 operation to move disk from origin to buffer, 1 op to move bigger disk from origin to destination. 
Another 1 to move the smaller disk from buffer to dest. So in all 3 operations -> 2^2 - 1
Similarly for 3 disks, the operations are 7 -> 2^3 - 1. Extrapolating for n disks, we get 2^n - 1 operations.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack> 

using namespace std;

void moveTop(stack<int>& origin, stack<int>& dest) {
    int disk = origin.top();
    origin.pop();
    dest.push(disk);
}

void moveDisks(int n, stack<int>& origin, stack<int>& dest, stack<int>& buffer) {
    
    if(n <= 0) //terminating case
        return;
    
    moveDisks(n-1,origin,buffer,dest);
    moveTop(origin,dest);
    moveDisks(n-1,buffer,dest,origin);
}

int main()
{
    vector<int> disks = {5,4,3,2,1};
    stack<int> origin;
    stack<int> dest;
    stack<int> buffer;
    for(int i = 0;i < disks.size();i++)
        origin.push(disks[i]);
    
    moveDisks(disks.size(),origin, dest, buffer); 
    
    cout << "Starting from top, Destination tower has..." << endl;
    for(int i = 0;i < disks.size();i++) {
        cout << dest.top() << ",";
        dest.pop();
    }
    cout << endl;
}

