/*4.4 Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one. 
*/

//Balanced: at any node, difference in height of left subtree and right subtree should not be more than 1
int height(node* root) { //calculates height of a tree

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
