/*4.3 List of Depths: Given a binary tree, design an algorithm which creates 
a linked list of all the nodes at each depth (e.g., if you have a tree with 
depth D, you'll have D linked lists). */

//Approach: use a vector of list nodes vector<list<node*>>

  void listify(node* root, int height, vector<list<node*>>& listy) {
        if(!root)
            return;
        
        size_t n = listy.size();
        
        if(!n || n <= height) { //start a new list
            list<node*> tmp;
            tmp.push_back(root);
            listy.push_back(tmp);
        }
        else if(n > height) { //add in the same list corresponding to height
            listy[height].push_back(root);
        }
        listify(root->left,height+1,listy);
        listify(root->right,height+1,listy);
    }

int main()
{
    node* root = NULL;    
    vector<int> vec = {9,3,13,8,7,4,11};
    for(int i = 0;i < (int) vec.size();i++)
        root = insert(vec[i],root);
    int height = 0;
    vector<list<node*>> listy;
    listify(root,height,listy);
    for(int i = 0;i < (int)listy.size();i++) {
        cout << "List at depth " << i << endl;
        list<node*>::iterator it;
        for(it = listy[i].begin();it != listy[i].end();++it) {
            cout << (*it)->data << ",";
        }
        cout << endl;
    }
}
