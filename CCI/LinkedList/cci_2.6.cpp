
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

/*2.6 Palindrome: Implement a function to check if a linked list is a palindrome. 
*/

//Trick: this has 3 solutions, recurive, iterative and reverse n compare
//Below has first two solutions.

//For recursive solution, references have to be used so that while unwinding, the next node's value takes effect
//For iterative solution, find the middle element using fast and slow runner. While finding the middle element, push the first half of elements to the stack. Once middle element
//is found, compare with the remaining half of elements

typedef struct node {
    struct node* next;
    int val;
}NODE;

NODE* head;

//Iterative Solution - Use fast and slow runner to find mid point of list as well as keeping pushing the elements of slow runner to stack.
//Once found mid point, compare and keeping moving the slow runner towards end of the list
bool isPalindrome(NODE* head) {
    if(!head)
        return false;
    NODE* current = head;
    NODE* runner = head;
    
    if(!runner->next)
        return true;
    
    stack<int> st;
    
    while(runner && runner->next) {
        st.push(current->val);
        current = current->next;
        runner = runner->next->next;
    }
    
    if(runner) {//odd number of elements
        //current is pointing to middle element
        current = current->next; //increment current one forward so that stack can be compared
    }
    
    while(current) {
        if(current->val != st.top())
            return false; //not a palindrome
        else {
            current = current->next;
            st.pop();
        }
    }
    return true;
}

//Recursive Solution
bool isPalindrome(NODE*& start, NODE*& end) {
    if(!start)
        return false;
    if(!end)
        return true;
    
    if(end->next == NULL) {
        //cout << "Term cond " << start->val << " and " << end->val << endl;
        if(start->val == end->val) {
            return true;
        }
        else
            return false;
    }
    
    if(isPalindrome(start,end->next)) {
        start = start->next; //if reference is not passed, this doesnt take effect when the functions returns, will show previous node's value
        //cout << "Non Term if cond " << start->val << " and " << end->val << endl;
        if(start->val == end->val)
            return true;
    }
    //cout << "Non Term else cond " << start->val << " and " << end->val << endl;
    return false;
}

void addToList(int val) {
    if(!head) { //first element being added
        head = new NODE;
        if(head) {
            head->next = NULL;
            head->val = val;
        }
    }
    else { //already elements are present
        NODE* tmp = head;
        while(tmp->next)
            tmp = tmp->next;
        NODE* node = new NODE;
        if(node) {
            tmp->next = node;
            node->next = NULL;
            node->val = val;
        }
    }
}

void showList() {
    if(head) {
        NODE* tmp = head;
        while(tmp != NULL) {
            cout << tmp->val << "->";
            tmp = tmp->next;
        }
        cout << endl;
    }
    else
        cout << "No List to display" << endl;
}

int main()
{
    vector<int> a = {5,4,3,2,8,2,3,4,5}; //input for the list
    //vector<int> a = {5}; //input for the list
    for(int i = 0;i < (int)a.size();i++)
        addToList(a[i]);
    cout << "Original List is " << endl;
    showList();
    
    //Recursive solution
    if(head) {
        if(isPalindrome(head,head->next))
            cout << "Is Palindrome" << endl;
        else
            cout << "Not Palindrome" << endl;
    }
    //Iterative Solution - find middle element, use stack to push first half and then compare with second half
    /*if(head) {
        if(isPalindrome(head))
            cout << "Is Palindrome" << endl;
        else
            cout << "Not Palindrome" << endl;
    }*/
    
    return 0;
}
