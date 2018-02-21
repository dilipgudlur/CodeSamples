/*4.4 Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one. 
*/

//Balanced: at any node, difference in height of left subtree and right subtree should not be more than 1

/*Approach1: this is simpler, but makes lotof unncessary calls to nodes whose height has been already calculated
Each subtree takes lgn time, but since this executes for all n nodes, it takes O(nlgn) time
*/

/*int height(node* root) { //calculates height of a tree

    if(!root)
        return -1;
        
    return max(height(root->left),height(root->right)) + 1; 
}
    
bool isBalanced(node* root) {
    if(!root)
        return false;
    
    int h = height(root->left) - height(root->right);
    cout << "height is " << h << endl;
    if(h > 1)
        return false;
    else
        return true;
}*/


//Approach2: Here we try to prevent making unnecessary calls if we already know if a subtree is unbalanced
//Runs in O(n) time and O(H) space where H is the height of the tree
 
int height(node* root) { //calculates height of a tree

    if(!root)
        return -1;
    
    if(!root->left && !root->right) //cuts down two calls if node is leaf
        return 0;
    
    int leftHeight = height(root->left);
    if(leftHeight == INT_MIN) //we already know left subtree is not balanced, so propagate that without checking for right
        return INT_MIN;
    
    int rightHeight = height(root->right);
    if(rightHeight == INT_MIN)
        return INT_MIN;//we already know left subtree is not balanced, so propagate that without checking for right
    
    if(abs(leftHeight - rightHeight) > 1)
        return INT_MIN; //use this as an error code to propagate upwards without going ahead to make further recursive calls
    else
        return max(leftHeight,rightHeight) + 1; 
}
    
bool isBalanced(node* root) {
    if(!root)
        return false;
    
    int h = height(root);
    cout << "height is " << h << endl;
    return h == INT_MIN ? false: true;
}

int main()
{
    node* root = NULL;    
    vector<int> vec = {9,3,13,8,7,4,11,14};
    for(int i = 0;i < (int) vec.size();i++)
        root = insert(vec[i],root);
    if(isBalanced(root))
        cout << "Is Balanced" << endl;
    else
        cout << "Is NOT Balanced" <<endl;
    
}
