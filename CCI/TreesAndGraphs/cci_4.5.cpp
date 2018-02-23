#include<iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

/*4.5 Validate BST: Implement a function to check if a binary tree is a binary search tree.
*/

/*Approach: this has two approaches, 

Approach1 - either using a top down approach using min/max, where starting at the root node, we trickle down. If we branch left, we set max as root node and if
we branch right, we set min as root node ad keep the checking the current node's value against min and max. If it lies in the range then we go further down

Approach2 - is a bottom up approach using a standard inorder traversal, we first recurse to lowermost left node using inorder traversal. Print the root node,
as we move up, update the last_printed node's value with the current node. This approach relies on the fact that if the subtree is truly a BST, then if the nodes
are traversed in an inorder fashion the left < root < right. So as we move from left to right, keep updating the last_printed node which will keep increasing
if its really a BST. Otherwise the condition of root > last_printed will fail if root's value is lesser and we return false for the subtree and return this upwards.
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
    
    //Approach1: Top Down approach using min and max nodes- O(n) solution
    bool checkBST(node* root,node* min, node* max) {
        if(!root)
            return true;
    
        //this is top down approach, start checking starting from top    
        if((min && root->data <= min->data) || (max && root->data >= max->data)) {
            return false;
        }
        
        return checkBST(root->left,min,root) && checkBST(root->right,root,max);

    }
    //Approach2 - this is a bottom approach using inorder traversal - O(n)
    bool checkBSTInorder(node* root,node*& last_printed) {
        if(!root)
            return true;
        
        if(!checkBSTInorder(root->left,last_printed))
            return false;
        
        if(last_printed && root->data <= last_printed->data)
            return false;
        
        last_printed = root;
        
        return checkBSTInorder(root->right,last_printed);
    }
    
    bool isValidBST(node* root) {
        if(!root)
            return true;

        node* last_printed = NULL;

        //return checkBST(root,NULL, NULL);
        return checkBSTInorder(root,last_printed);
    }
    
int main()
{
    node* root = NULL;    
    vector<int> vec = {9,5,7,4,13,16,17};
    for(int i = 0;i < (int) vec.size();i++)
        root = insert(vec[i],root);
    if(isValidBST(root))
        cout << "Binary tree is a BST" << endl;
    else
        cout << "Binary tree is not a BST" <<endl;
    
}
