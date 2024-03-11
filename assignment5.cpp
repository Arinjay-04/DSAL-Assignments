#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    string key;
    string value;
    Node* next;

    Node(string s , string v){
        
        this->key = s;
        this->value = v;
        this->next = NULL;
    }

};


class Hashing{
    public: 
    Node* head;
     int size;
    Node *arr[];
    

    Hashing(int s){
        this->size = s;
        this->head = NULL;
        for(int i=0; i<size; i++){
              arr[i] = NULL;
        }
    }


    int hashing(string key){
        int hash = 0;

        for(char c: key){
            hash += c;
        }

        return hash%size;
    }

    void insert(string key , string value){
        int hash = hashing(key);

        if(arr[hash] == NULL){
            Node* newnode = new Node(key , value);
            arr[hash] = newnode;
        }

        else{
            Node* curr = arr[hash];
            while(curr->next != NULL){
                   curr = curr->next;
            }

            Node* newnode = new Node(key , value);
            curr->next = newnode;
        }
    }

    void search(string key){
        int hash = hashing(key);

        int original_ele = hash;

        Node* temp = arr[hash];

        while(temp != NULL){
            if(temp->key == key){
                cout<<"Element found";
                return ;

            }
            temp = temp->next;
        }

        cout<<"Elemnt Not Found"<<endl;
    }


void deletion(string key){
    int hash = hashing(key);

    Node* newnode = arr[hash];
    Node* prev = NULL;

    if(newnode == NULL){
        cout<<"Node not found for deletion"<<endl;
        return;
    }

    if(newnode->key == key){
            arr[hash] = newnode->next;
            delete newnode;
            cout<<"Node deleted"<<endl;
            return;
        }


    while(newnode != NULL && newnode->key != key ){
        prev = newnode;
        newnode = newnode->next;
    }

    if(newnode == NULL){
        cout<<"Node not Found for dletion"<<endl;
    }

    prev->next = newnode->next;
    delete newnode;
    cout<<"Node has been deleted"<<endl;
}


void print(){
    for(int i=0; i<size; i++){
        Node* temp = arr[i];

        while(temp != NULL){
            cout<<temp->key <<" : " <<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;

    }cout<<endl;
}
   


};


int main(){
    
    int size ;
    cout<<"Enter the size of hashtable : ";
    cin>>size;
    Hashing h(size);
    while (true) {
        int choice;
        cout << "Enter the operation you want to perform: " << endl;
        cout << "\t1. Insertion \t\t\t 2. Searching" << endl;
        cout << "\t3. Display \t\t\t 4. Delete an element" << endl;
        cout << "\t5. Exit" << endl;
        cin >> choice;
        if (choice == 1) {
            string key;
            string value;
            cout << "Enter the key: ";
            cin >> key;
            cout << "Enter Value: ";
            cin >> value;
            h.insert(key, value);
        } else if (choice == 2) {
            string key;
            cout << "Enter the key you want to search: ";
            cin >> key;
            h.search(key);
        } else if (choice == 3) {
            h.print();
        } else if (choice == 4) {
            string key;
            cout << "Enter the key you want to delete: ";
            cin >> key;
            h.deletion(key);
        } else if (choice == 5) {
            return 0;
        } else {
            cout << "Invalid choice entered.." << endl;
        }
    }


return 0;
}