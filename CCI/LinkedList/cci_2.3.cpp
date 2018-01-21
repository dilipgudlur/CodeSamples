#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*2.3 Delete Middle Node: Implement an algorithm to delete a node in the middle 
(i.e., any node but the first and last node, not necessarily the exact middle) 
of a singly linked list, GIVEN ONLY ACCESS TO THAT NODE. 
EXAMPLE lnput:the node c from the linked list a->b->c->d->e->f 
Result: nothing is returned, but the new linked list looks like a ->b->d->e->f 
*/

//Trick: Note that no other node is given so deletion has to be done based on only current node.
//Copy data from next node to current node and delete the next node. If current node is the last node,
//then this cannot be done, maybe mark the node as dummy.

typedef struct node {
    struct node* next;
    int val;
}NODE;

NODE* head;

void deleteNode(NODE*& before, NODE*& now) {
    before->next = now->next;
    delete now;
    now = before;
}

//Complexity - O(1) time and O(1) space
//Trick - runner moves twice as fast as current, so while current is at middle, runner is at end
void deleteCurrentNode(NODE*& now) {
    if(!now || !now->next) //nothing can be done if this is the last node
        return;
    NODE* tmp = now->next;
    now->val = tmp->val;
    now->next = tmp->next;
    delete tmp;
}

NODE* getMiddle() {
    if(head) {
        NODE* current = head;
        NODE* runner = current;
        
        if(current->next && runner->next->next) {
            while(runner->next) {
                current = current->next;
                runner = runner->next->next;
            }
            return current;
        }
    }
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
    vector<int> a = {5,4,3,2,8,6,3,7,5}; //input for the list
    for(int i = 0;i < (int)a.size();i++)
        addToList(a[i]);
    cout << "Original List is " << endl;
    showList();
    NODE* middle = getMiddle(); //use this function to get the middle element
    cout << "Middle Element is " << middle->val << endl;
    deleteCurrentNode(middle); //delete the middle element
    cout << "After deleting middle element from list " << endl;
    showList();
    return 0;
}
