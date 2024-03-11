#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree{
    public:

    Node* root;

    BinaryTree(){
        root = NULL;
    }

    ~BinaryTree(){
        deleteTree(root);
    }

    void deleteTree(Node* root){
          if(root == NULL){
            return;
          }

          deleteTree(root->left);
          deleteTree(root->right);

          delete root;
    }

     BinaryTree(const BinaryTree& other) {
        root = copyTree(other.root);
    }

    BinaryTree& operator=(const BinaryTree& other){
        if(this == &other){
            return *this;
        }

        deleteTree(root);
        
        root = copyTree(other.root);
        return *this;

    }

    Node* copyTree(Node* node){
        if(node == NULL){
            return NULL;
        }
        Node* newnode = new Node(node->data);
        newnode->left = copyTree(node->left);
        newnode->right = copyTree(node->right);
        return newnode;
    }

void creatTree() {
    Node* p, *t;
    if (root == NULL) {
        cout << "Enter the data to be inserted in root: ";
        int data;
        cin >> data;
        root = new Node(data);
        // root->left = NULL;
        // root->right = NULL;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        int leftData, rightData;

        if (p->left == NULL) {
            cout << "Enter the data to be inserted at left of " << p->data << " (Enter -1 if no left child): ";
            cin >> leftData;
            if (leftData != -1) {
                t = new Node(leftData);
                t->left = NULL;
                t->right = NULL;
                p->left = t;
                q.push(t);
            }
        }

        if (p->right == NULL) {
            cout << "Enter the data to be inserted at right of " << p->data << " (Enter -1 if no right child): ";
            cin >> rightData;
            if (rightData != -1) {
                t = new Node(rightData);
                t->left = NULL;
                t->right = NULL;
                p->right = t;
                q.push(t);
            }
        }
    }
}



    vector<int>  Iterative_Preorder(Node* root){
        vector<int> preorder;
        if(root == NULL){
              return preorder;
        }

        stack<Node*> st;

        st.push(root);
        Node* node = root;

        while(!st.empty()){
             node = st.top();
             st.pop();

             if(node->right){
                st.push(node->right);
             }
             if(node->left){
                st.push(node->left);
             }

             preorder.push_back(node->data);
        }
         
         return preorder;

    }

    void Reccursive_preorder(Node* root){
           if(root != NULL){
             cout<<root->data<<" ";
             Reccursive_preorder(root->left);
             Reccursive_preorder(root->right);
           }

    }


    vector<int> Iterative_Inorder(Node* root){
        vector<int> inorder;
        if(root == NULL){
            return inorder;
        }

        stack<Node*> st;

        st.push(root);


        Node* node = root;

        while(!st.empty()){
            
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                node = st.top();
                st.pop();
                inorder.push_back(node->data);
                node = node->right;
            }
        }
         
         return inorder;
    }


     void Reccursive_inorder(Node* root){
           if(root != NULL){
            Reccursive_preorder(root->left);
             cout<<root->data<<" ";
             Reccursive_preorder(root->right);
           }

    }


    vector<int> Interative_postorder(Node* root){
        vector<int> postoder;
        if(root == NULL){
            return postoder;
        }

        stack<Node*> st1, st2;

        st1.push(root);

        Node* node = root;

        while(!st1.empty()){
            node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left){
                 st1.push(node->left);
            }
            if(node->right){
                st1.push(node->right);
            }

        }


        while(!st2.empty()){
            postoder.push_back(st2.top()->data);
            st2.pop();
        }

        return postoder;
    }

    void Reccursive_postorder(Node* root){
           if(root != NULL){
            Reccursive_preorder(root->left);
             Reccursive_preorder(root->right);
              cout<<root->data<<" ";
           }

    }

     void swapLeftRight(Node* node) {
        if (node == NULL)
            return;
        swap(node->left, node->right);
        swapLeftRight(node->left); 
        swapLeftRight(node->right); 
    }

    int Height(Node* root){
        if(root == NULL){
            return 0;
        }

        int lh = Height(root->left);
        int rh = Height(root->right);

        return 1 + max(lh , rh);
    }


    int countLeaves(Node* root){
        if(root == NULL){
            return 0;
        }

        else if(root->left == NULL && root->right == NULL){
            return 1;
        }

        return countLeaves(root->left) +  countLeaves(root->right);
    }

    int numberOfNodes(Node* root){
        if(root == NULL){
            return 0;
        }

        int lh = Height(root->left);
        int rh = Height(root->right);

        return 1 + lh + rh;
    }

    int numberofInternal(Node* root){
        int ans1 = numberOfNodes(root);
        int ans2 = countLeaves(root);

        return (ans1 - ans2);
    }



    void Erase(Node* root){
        deleteTree(root);

        root = NULL;
    }




};


int main(){

    BinaryTree obj;
    char choice;

     obj.creatTree();

     cout<<"Iterative Preorder : ";
    vector<int> v;
    v =  obj.Iterative_Preorder(obj.root);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;

     cout<<"Iterative Inorder : ";
    vector<int> v1;
    v1=  obj.Iterative_Inorder(obj.root);
    for(int i=0; i<v.size(); i++){
        cout<<v1[i]<<" ";
    }cout<<endl;

     cout<<"Iterative postorder: ";
    vector<int> v2;
    v2 =  obj.Interative_postorder(obj.root);
    for(int i=0; i<v.size(); i++){
        cout<<v2[i]<<" ";
    }cout<<endl;

    cout<<"recurrsive pre: ";
    obj.Reccursive_preorder(obj.root);

     cout<<"recurrsive In: ";
    obj.Reccursive_inorder(obj.root);

     cout<<"recurrsive post: ";
    obj.Reccursive_postorder(obj.root);


return 0;
}