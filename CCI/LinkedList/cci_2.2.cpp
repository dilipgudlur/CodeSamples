#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*2.2 Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
*/

typedef struct node {
    struct node* next;
    int val;
}NODE;

NODE* head;

//Iterative solution - most optimal: O(n) time and O(1) space
int kFromLast(int gap) {
    if(head) {
        NODE* current = head;
        NODE* runner = current;
        while(gap && runner) {
            runner = runner->next;
            --gap;
        }
        if(!runner) {
            cout << "Not enough elements in list" << endl;
            return -1;
        }
        
        //Now current and runner have a gap of k-1
        while(runner->next) {
            current = current->next;
            runner = runner->next;
        }
        return current->val;
    }
    return -1;
}

//Recursive solution - O(n) time and O(n) space
int kFromLast(NODE* node, int &gap) {
    
    if(node->next == NULL) {//have reached last node
        gap--;
        return -1;
    }
    
    int result = kFromLast(node->next, gap);
    
    if(result == -1) {
        if(gap > 0)
            gap--;
        else
            result = node->val;
    }
    return result;
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
    vector<int> a = {5,4,3,2,4,6,3,7,5}; //input for the list
    for(int i = 0;i < (int)a.size();i++)
        addToList(a[i]);
    int k = 5;
    int tmpIndex = k-1;
    int& gap = tmpIndex;
    cout << "Original List is " << endl;
    showList();
    NODE* tmp = head;
    cout << k << "th element from last is " << kFromLast(tmp, gap) << endl;
    return 0;
}
