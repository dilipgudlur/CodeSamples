/*2.8 Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop. DEFINITION Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list. EXAMPLE Input:A -> B -> C -> D -> E -> C [the same C as earlier] 
Output: C
*/

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
    ListNode *detectCycle(ListNode *head) {
        
        //O(1) space solution
        //Trick: use slow and fast pointers to detect point of collision 
        //1. the collision point is k steps from start and LOOP_SIZE- k steps after start or k steps behind the start point (ref to diagram             in CCI), since its a circle. Loop_size-k steps in front of start point of loop means k steps from behind the start point
        //2. Move a pointer from start of list towards start point of loop and move a pointer from behind the start point of loop
        //3. intersection point will be the start of loop

        ListNode* slow = head;
        ListNode* fast = head; //fast pointer moves twice the speed of slow
        
        //find point of collision first
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        
        //Error check - no meeting point, and therefore no loop
        if(!fast || !fast->next)
            return NULL;
        
        //slow and fast are both pointing to point of collision now, start point of loop is k steps from point of collision
        //head of list is also k steps from start point of collision
        slow = head;
        
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
