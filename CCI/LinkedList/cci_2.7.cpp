/*2.7 Intersection: Given two (singly) linked lists, determine if the two lists intersect. 
Return the intersecting node. Note that the intersection is defined based on reference, not value. 
That is, if the kth node of the first linked list is the exact same node (by reference) as the jth
node of the second linked list, then they are intersecting.
*/

//Trick: First find whether or not the two lists intersect. If they do, they have a common (by reference) last node, otherwise they dont intersect.
//If they have same length, then advancing both lists one by one, its easy to find intersection.
//If they have different lengths, then advance the longer list by the difference of length, this way the lengths become equal now. From here start advancing
//both lists one by one*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) {
            cout << "here1";
            return NULL;
        }
        
        struct ListNode* l1 = headA;
        struct ListNode* l2 = headB;

        int n1 = 0;
        int n2 = 0;
        
        //find length of A
        while(l1->next) {
            n1++;
            l1 = l1->next;
        }
        //A is pointing to last node
        
        //find length of B
        while(l2->next) {
            n2++;
            l2 = l2->next;
        }
        //B is pointing to last node
        
        
        //if the lists intersect, last node must be same by reference
        if(l1 != l2) //lists dont intersect
            return NULL;
        
        l1 = headA;
        l2 = headB;
        
        
        //shorter points to shorter list
        struct ListNode* shorter = n1 <= n2 ? l1 : l2;
        
        //longer points to longer list
        struct ListNode* longer = n1 > n2 ? l1 : l2;
        
        //now advance the longer list by the difference in lengths
        int count = abs(n1-n2);
        while(count) {
            longer = longer->next;
            --count;
        }
        //from here, longer and shorter have the same length till last node, so advance one node at a time
        while(shorter != longer) {
            shorter = shorter->next;
            longer = longer->next;
        }
        
        return longer;
    }
};
