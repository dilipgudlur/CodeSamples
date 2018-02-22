#include<iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

/*4.4 Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one. 
*/

//Balanced: at any node, difference in height of left subtree and right subtree should not be more than 1

/*Approach1: this is simpler, but makes lot of unncessary calls to nodes whose height has been already calculated
Each subtree takes lgn time, but since this executes for all n nodes, it takes O(nlgn) time

isBalanced splits the problem into 2, takes lgn time and in the same function, the getHeight is another recurive call which
visits all the nodes starting from root, this take O(n). 

For isBalance function, Tn = 2T(n/2) + nc => 2[2T(n/4) + n/2*c] + nc => 4T(n/2)+ 2nc => 2^k T(n/2^k)+ knc => n + nlgn*c => O(nlgn) 

*/

using namespace std;

    struct node
    {
        int data;
        node* left;
        node* right;
    };

    node* makeEmpty(node* t)
    {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t)
    {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void displayInorder(node* t)
    {
        if(t == NULL)
            return;
        displayInorder(t->left);
        cout << t->data << " ";
        displayInorder(t->right);
    }
    
    void displayPreorder(node* t)
    {
        if(t == NULL)
            return;
        cout << t->data << " ";
        displayInorder(t->left);
        displayInorder(t->right);
    }
    
    void displayPostorder(node* t)
    {
        if(t == NULL)
            return;
        displayInorder(t->left);
        displayInorder(t->right);
        cout << t->data << " ";
    }

    node* find(node* t, int x)
    {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

/*int height(node* root) { //calculates height of a tree
    if(!root)
        return -1;
        
    return max(height(root->left),height(root->right)) + 1; 
}
    
bool isBalanced(node* root) {
    if(!root) //a null root is balanced
        return true;

    int h = height(root->left) - height(root->right);
    cout << "height at root " << root->data << " is " <<abs(h) << endl;
    if(abs(h) > 1)
        return false;
    else
        return (isBalanced(root->left) && isBalanced(root->right));
}*/

/*Approach2: Here we try to prevent making unnecessary calls if we already know if a subtree is unbalanced
Runs in O(n) time and O(H) space where H is the height of the tree. This implementation cuts down the lgn portion
but still has to visit all the nodes of the tree.

Tn = 2T(n/2) + c => 2[2T(n/4) + c] + c => 4T(n/4)+ c(1+2) => 2^k T(n/2^k) + c(1+2+4+8+..2^k) => 2^kT(n/2^k)+c*(2^(k+1) - 1)
where 2^(k+1) - 1 is sum of the geometreic progression. 
Tn = nT(1)+c*(2*lgn - 1) = n+clgn = O(n)
*/
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
    
    //after heights of both left and right subtree get evaluated and control reaches here, if height is more than 1, return error code
    if(abs(leftHeight - rightHeight) > 1)
        return INT_MIN; //use this as an error code to propagate upwards without going ahead to make further recursive calls
    else
        return max(leftHeight,rightHeight) + 1; 
}
    
bool isBalanced(node* root) {
    if(!root) //null node is considered to be balanced
        return true;
    
    int h = height(root);
    cout << "height is " << h << endl;
    return h == INT_MIN ? false: true; //converts integer return value to boolean
}

int main()
{
    node* root = NULL;    
    vector<int> vec = {9,5,7,4,13,16,17};
    for(int i = 0;i < (int) vec.size();i++)
        root = insert(vec[i],root);
    if(isBalanced(root))
        cout << "Is Balanced" << endl;
    else
        cout << "Is NOT Balanced" <<endl;
    
}
