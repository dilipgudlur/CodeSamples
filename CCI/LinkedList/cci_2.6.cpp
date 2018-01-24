
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*2.6 Palindrome: Implement a function to check if a linked list is a palindrome. 
*/

//Trick: References have to be used so that the next node's value takes effect

typedef struct node {
    struct node* next;
    int val;
}NODE;

NODE* head;

bool isPalindrome(NODE*& start, NODE*& end) {
    
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
    vector<int> a = {5,4,3,2,8,7,3,4,5}; //input for the list
    for(int i = 0;i < (int)a.size();i++)
        addToList(a[i]);
    cout << "Original List is " << endl;
    showList();
    if(head && head->next) {
        if(isPalindrome(head,head->next))
            cout << "Is Palindrome" << endl;
        else
            cout << "Not Palindrome" << endl;
    }
    return 0;
}
