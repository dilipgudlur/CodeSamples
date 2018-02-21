/*4.3 List of Depths: Given a binary tree, design an algorithm which creates 
a linked list of all the nodes at each depth (e.g., if you have a tree with 
depth D, you'll have D linked lists). */

//Approach: use a vector of list nodes vector<list<node*>>

  //similar to preorder traversal
  void listifyRecursive(node* root, int height, vector<list<node*>>& listy) {
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

    //similar to bfs search
    void listifyIterative(node* root, vector<list<node*>>& listy) {
        queue<node*> q;
        list<node*> currentList;
        if(!root)
            return;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            node* tmp = q.front();
            q.pop();
            if(tmp != NULL) { //add in the same list
                currentList.push_back(tmp);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            else { //start a new list
                if(!currentList.empty()) {
                    listy.push_back(currentList); //push the current list, this completes current list
                    q.push(NULL);
                    currentList.clear();
                }
            }
        }
    }

int main()
{
    node* root = NULL;    
    vector<int> vec = {9,3,13,8,7,4,11};
    for(int i = 0;i < (int) vec.size();i++)
        root = insert(vec[i],root);
    int height = 0;
    vector<list<node*>> listy;
    listifyRecursive(root,height,listy);
    listifyIterative(root,listy);
    for(int i = 0;i < (int)listy.size();i++) {
        cout << "List at depth " << i << endl;
        list<node*>::iterator it;
        for(it = listy[i].begin();it != listy[i].end();++it) {
            cout << (*it)->data << ",";
        }
        cout << endl;
    }
}
