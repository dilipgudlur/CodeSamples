/*4.8 First Common Ancestor: Design an algorithm and write code to find the 
first common ancestor of two nodes in a binary tree. Avoid storing additional 
nodes in a data structure. NOTE: This is not necessarily a binary search tree. 
*/

/*Approach: NOTE: this code works only if both p and q are present in the tree.
If either p is found or q is found return the node when its found. So in a 
particular subtree, if both the nodes occur then the first occurring shallower node
is returned since the shallower node will also be the LCA for the nodes.

a. if one half of subtree has a node and other half has another node, then both
leftside and rightside will be non-null so return the root at this stage, root which is
the parent of the leftside and rightside

b. if one half is null and other half is non-null, means neither p nor q was found in that subtree
so return the subtree which is non null

c. if both siddes do not have the node then return null to indicate the root doesn't have either p or q
so search at a different subtree

Complexit: this runs in O(n) complexity 
*/

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == p || root == q || !root) {
            return root;
        }
        
        TreeNode* leftside = lowestCommonAncestor(root->left, p, q); 
        TreeNode* rightside = lowestCommonAncestor(root->right, p, q);
        
        if (leftside && rightside)// p and q found in diff. subtrees 
            return root; // This is the common ancestor 
        
        return leftside ? leftside : rightside; //return the non-null node, if both null then return null
    }
