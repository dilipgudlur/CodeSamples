    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> vec;
        TreeNode* cur = root;
    
       /*standard approach using stack: this approach uses O(n) space and O(n) time

        stack<TreeNode*> s;
        if(!root)
            return vec;

        while(!s.empty() || cur) {    
            if(cur) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode* tmp = s.top();
                vec.push_back(tmp->val);
                s.pop();
                cur = tmp->right;  
            }
        }*/
        
        /*Morris traversal uses no extra space O(1) space and O(n) time, 
        this is based on chaining the rightmost node of immediate left subtree to current root for inorder traversal*/
        
        while(cur) {
            if(cur->left) { //if left child is present, this could happen when we are moving first time to the left or we came here due to chaining from leftside->right
                TreeNode* leftside = cur->left;
                
                while(leftside->right && leftside->right != cur) { //keep going right till node is not null and not equal to curnode
                    leftside = leftside->right;
                }
                
                if(!leftside->right) { //this has not been chained yet
                    leftside->right = cur;
                    cur = cur->left;//continue the same with the left child
                }
                else { //tricky part: leftside->right is equal to current root, we are seeing now what we chained before
                    leftside->right = NULL; //what it was originally, we just know now that it is chained
                    vec.push_back(cur->val); //prints the root node
                    cur = cur->right; //move top right side
                }
            }
            else { //no more left child
                vec.push_back(cur->val);
                cur = cur->right;
            } 
        }
        return vec;
    }
