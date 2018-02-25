/*4.6 Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given 
node in a binary search tree. You may assume that each node has a link to its parent.*/

/*Approach: asusmes that the node p exists in the tree. Keep searching for the node depending whether its bigger (right subtree) or smaller than root (left subtree)
Once found, have to return the right child of this node. If right child is non-null then return the leftmost node of this right child. Its tricky when the right child is null.
The you have to return the parent but only that parent on whose left subtree node p was found, not the parent if node p was on its right subtree.
Starting from top, send a "result" node by reference, everytime you move left update the result node as root since this becomes the parent to be returned in case p is found on the
left. If moving right, then don't update the result node meaning the right subtree will have the same inorder parent as the current root so don't update the result while moving right
*/

TreeNode* successor(TreeNode* root, TreeNode* p, TreeNode*& result) {
        
        if(!root)
            return NULL;

        if(p->val < root->val) { //if moving left, change the result node to current root as that will be the inorder successor
            //result = root; //update the result node
            return successor(root->left,p,root);
        }
        else if (p->val > root->val) { //if you are moving right, dont change the result node, let it be whatever it was
            return successor(root->right,p,result);
        }
        else { //root==p
            if(root->right) { //return leftmost child of right node
                root = root->right;
                while(root->left)
                    root = root->left;
                return root;
            }
            else //no right node, then return the result node since it contains the inorder successor already
                return result;
        }
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        if(!root)
            return NULL;
        
        TreeNode* result = NULL;
        return successor(root,p,result);
    }
