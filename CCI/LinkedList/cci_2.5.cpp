#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*2.5 Sum Lists: You have two numbers represented by a linked list, where each node contains a single digit. 
The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a function 
that adds the two numbers and returns the sum as a linked list. 
EXAMPLE Input: (7-> 1 -> 6) + (5 -> 9 -> 2).Thatis,617 + 295. 
Output: 2 -> 1 -> 9. That is, 912. 
FOLLOW UP Suppose the digits are stored in forward order. Repeat the above problem. 
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).Thatis,617 + 295. 
Output: 9 -> 1 -> 2. That is, 912
*/

typedef struct node {
    struct node* next;
    int val;
}NODE;

NODE* headA;
NODE* headB;
NODE* headC;

void addToList(NODE*& head, int val) {
    if(!head) { //first element being added
        head = new NODE;
        if(head) {
            head->next = NULL;
            head->val = val;
            //cout << "Adding " << head->val << endl;
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
            //cout << "Adding " << node->val << endl;
        }
    }
}

//Recursive solution
void sumDigitsInReverse(NODE* headA, NODE* headB,int carry) {
    int tmp = 0;
    int sum = 0;
    bool AisNULL = true;
    bool BisNULL = true;
    
    if(!headA && !headB) {
        if(carry)
            addToList(headC,carry);
        return;
    }
    
    if(headA) {
        tmp += headA->val;
        AisNULL = false;
    }
    
    if(headB) {
        tmp += headB->val;
        BisNULL = false;
    }
    
    tmp += carry;
    sum = tmp%10;
    carry = tmp/10;
    
    addToList(headC,sum);
    
    if(AisNULL)
        sumDigitsInReverse(NULL,headB->next, carry);
    else if(BisNULL)
        sumDigitsInReverse(headA->next,NULL, carry);
    else
        sumDigitsInReverse(headA->next,headB->next, carry);
}

//Iterative solution
void sumDigitsInReverse(NODE* l1, NODE* l2) {
    
    if(!l1 && !l2)
        return;
    
    int sum = 0;
    int carry = 0;
    
    //this is a better method as it reduces the code
    while(l1 || l2) {
        int tmp = 0;
        if(l1) {
            tmp += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            tmp += l2->val;
            l2 = l2->next;
        }
        
        tmp += carry;
        sum = tmp%10;
        carry = tmp/10;
        
        addToList(headC,sum);
    }
    
    if(carry) { //carry can be non-zero even when the nodes are finished
        addToList(headC,carry);
    }
}

void showList(NODE* head) {
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
    vector<int> a = {7,1,6,9}; //input for first list
    vector<int> b = {5,9,4}; //input for second list
    
    for(int i = 0;i < (int)a.size();i++)
        addToList(headA, a[i]);
    for(int i = 0;i < (int)b.size();i++)
        addToList(headB, b[i]);
    cout << "Original List is " << endl;
    showList(headA);
    showList(headB);
    
    sumDigitsInReverse(headA,headB,0);
    //sumDigitsInReverse(headA,headB);
    cout << "Sum is " << endl;
    showList(headC);
    return 0;
}
