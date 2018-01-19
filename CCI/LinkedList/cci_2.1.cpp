#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*2.1 Remove Dups: Write code to remove duplicates from an unsorted linked list. 
FOLLOW UP How would you solve this problem if a temporary buffer is not allowed? 
*/

typedef struct node {
    struct node* next;
    int val;
}NODE;

NODE* head;

void deleteNode(NODE*& before, NODE*& node) {
    if(before && node) {
        before->next = node->next;
        delete node;
        node = before;
    }
}

//Solution1 - uses map with O(n) time and O(n) space complexity using maps for lookup of duplicate
void removeDuplicates() {
    if(head) { //valid list
        unordered_map<int,int> map;
        unordered_map<int,int>::iterator it;
        NODE* tmp = head;
        int index = 0;
        NODE* before;
        while(tmp != NULL) {
            it = map.find(tmp->val);
            if(it != map.end() && index != it->second) {
                cout << "At index " << index+1 << ", deleting " << tmp->val << endl;
                deleteNode(before,tmp);
            }
            else {
                map.insert({tmp->val,index++}); //insert the value and index 
            }
            before = tmp;
            tmp = tmp->next;
        }
    }
}

//Solution2 - O(n^2) time complexity but with O(1) space complexity
void removeDuplicates() {
    if(head) {
        NODE* current = head;
        if(!current->next) //no duplicates
            return;
        while(current != NULL) {
            NODE* before = current;
            NODE* runner = current->next;
            while(runner != NULL) {
                if(current->val == runner->val)
                    deleteNode(before,runner);
                before = runner;
                runner = runner->next;
            }
            current = current->next;
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
    vector<int> a = {5,4,3,2,4,6,3,7,5}; //input for the list
    for(int i = 0;i < (int)a.size();i++)
        addToList(a[i]);
    cout << "Original List is " << endl;
    showList();
    cout << "List after removing duplicate is " << endl;
    removeDuplicates();
    showList();
    return 0;
}
