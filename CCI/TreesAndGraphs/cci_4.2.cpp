#include<iostream>
#include <vector>

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

/*This is the important function, key is to find the middle element as set that as root. To have a minimal height tree,
it is key that maximum number of elements can be accomodated at a given height. The max number of nodes can be 
//accomodated when both the left and right sub children are populated. When equal number of left and right sub children are
present, then tree will have minimal height. Therefore the key is to have the root somewhere in the middle of the range
of elements */

    node* createMinimalBST(node*& root, vector<int> vec, int low, int high) {
        if(low > high)
            return NULL;
        int mid = (low+high)/2;
        root = insert(vec[mid],root); //adds mid element as root
        root->left = createMinimalBST(root->left,vec,low,mid-1);
        root->right = createMinimalBST(root->right,vec,mid+1,high);
        return root;
    }

int main()
{
    node* root = NULL;    
    vector<int> vec = {1,3,5,7,9,11};
    /*for(int i = 0;i < vec.size();i++)
        root = insert(vec[i],root);*/
    int low = 0;
    int high = vec.size()-1;
    root = createMinimalBST(root,vec,low,high);
    displayInorder(root);
    cout << endl;
    displayPreorder(root);
    cout << endl;
    displayPostorder(root);
}
