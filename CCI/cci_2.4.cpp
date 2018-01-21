#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*2.4 Partition: Write code to partition a linked list around a value x, such that all nodes less than x 
come before all nodes greater than or equal to x. If xis contained within the list the values of x 
only need to be after the elements less than x (see below). The partition element x can appear anywhere 
in the "right partition"; it does not need to appear between the left and right partitions. 
EXAMPLE Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5] 
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8 
*/

//Trick: Find first element that is greater than or equal to partition value.
//from there, check the next element (current->next), if it is greater, increment to next node
//If current->next is smaller, add a new element with value of current->next to head and delete current->next

typedef struct node {
    struct node* next;
    int val;
}NODE;

NODE* head;

//deletes current->next
void deleteNode(NODE*& now) {
    if(now) {
        if(now->next) {
            NODE* tmp = now->next;
            now->next = tmp->next;
            delete tmp;
        }
        else {
            delete now->next;
            now->next = NULL;
            
        }
    }
}

//adds a new element at head
void addToHead(int val) {
    if(head) {
        NODE* node = new NODE;
        if(node) {
            node->val = val;
            node->next = head;
            head = node;
        }
    }
}

void partition(int partitionVal) {
    if(head) {
        NODE* current = head;
        //find first element greater than or equal to partition
        while(current) {
            if(current->val < partitionVal)
                current = current->next;
            else
                break;
        }
        
        if(!current) { //partition elemtn found, any elements smaller than partition found after this
            cout << "all elements are smaller than partition value, no rearrangement required" << endl;
            return;
        }

        cout << "Partition Element is " << current->val << endl;
        
        //start checking for elements smaller than partition and move to head
        while(current->next) {
            if(current->next->val < partitionVal) {
                addToHead(current->next->val);
                cout << "Moved " << current->next->val << " to head" << endl;
                deleteNode(current); //deletes the next node
            }
            else {
                cout << "Skipping " << current->val << endl;
                current = current->next;
            }
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
    int partitionVal = 5;
    partition(partitionVal); //rearranges elements around a partition element
    cout << "After partitioning list is " << endl;
    showList();
    return 0;
}
