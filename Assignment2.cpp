#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    Node* insert(Node* root, int d) {
        if (root == nullptr) {
            Node* newnode = new Node(d);
            return newnode;
        }

        if (d > root->data) {
            root->right = insert(root->right, d);
        }
        else {
            root->left = insert(root->left, d);
        }

        return root;
    }

    void create() {
        root = insert(root, 5);
        root = insert(root, 4);
        root = insert(root, 7);
    }

    int Height(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int lh = Height(root->left);
        int rh = Height(root->right);

        return 1 + max(lh, rh);
    }

    int Maxi(Node* root){
        while(root != NULL){
            root = root->right;
        }

        return root->data;

    }

    int Mani(Node* root){
        while(root->left != NULL){
            root = root->left;
        }

        return root->data;

    }

    void swaping(Node* root){
        if(root == NULL){
            return;
        }

        swap(root->left , root->right);

        swaping(root->left);
        swaping(root->right);
    }

    Node* search(Node* root , int d){
        if(root == NULL ){
            return NULL;
        }
        Node* node = root;

        if(node->data == d){
            return node;
        }

        else if(node->data < d){
            return search(node->right , d);
        }


        else{
             return  search(node->left , d);
        }

        return NULL;

        
    }
    
    void Reccursive_preorder(Node* root){
           if(root != NULL){
             cout<<root->data<<" ";
             Reccursive_preorder(root->left);
             Reccursive_preorder(root->right);
           }

    }
};

int main() {
    BinarySearchTree obj;

    obj.create();
    obj.insert(obj.root , 8);
    obj.insert(obj.root , 1);
    obj.insert(obj.root , 4);
    obj.insert(obj.root , 7);

    int h = obj.Height(obj.root);

    cout << "Height of the tree: " << h << endl;

 Node * node =    obj.search(obj.root , 4);

 if(node == NULL){
    cout<<"No"<<endl;
 }
 else{
    cout<<"Yes"<<endl;
 }

 int mini = obj.Mani(obj.root);
 cout<<mini<<endl;

 obj.Reccursive_preorder(obj.root);


 obj.swaping(obj.root);
   int h1 = obj.Height(obj.root);

    cout << "Height of the tree: " << h1 << endl;

    obj.Reccursive_preorder(obj.root);
 

    return 0;
}
