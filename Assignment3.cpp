
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *left;
	Node *right;
	bool rbit;
	bool lbit;

	Node(int n)
	{
		data=n;
		left=NULL;
		right=NULL;
		rbit=0;
		lbit=0;
	}
	friend class TBST;
};

class TBST
{
	Node *head,*root;
public:
	TBST()
	{
		root=NULL;
		head=NULL;
	}

	Node *getroot()
	{
		return root;
	}
	void insert(int x)
	{
		if(root==NULL)
		{
			head=new Node(-999);
			head->right=head;
			root=new Node(x);
			head->left=root;
			head->lbit=1;
			root->left=head;
			root->right=head;
			return;
		}
		else
		{
			Node *p=root;
			Node *q=new Node(x);
			while(true)
			{
				if(x==p->data)
				{
					delete q;
					return;
				}
				else if(x<p->data)
				{
					if(p->lbit==1)
					{
						p=p->left;
					}
					else
					{
						q->left=p->left;
						q->right=p;
						p->left=q;
						p->lbit=1;
						return;

					}
				}

				else
				{
					if(p->rbit==1)
					{
						p=p->right;
					}
					else
					{
						q->right=p->right;
						q->left=p;
						p->right=q;
						p->rbit=1;
						return;
					}
				}
			}
		}
	}

    void inorder()
    {
    	Node *p=root;
    	while(p->lbit==1)
    	{
    		p=p->left;
    	}
    	while(p!=head)
    	{
    		cout<<p->data<<" ";
    		if(p->rbit==1)
    		{
    			p=p->right;
    			while(p->lbit==1)
    			{
    				p=p->left;
    			}

    		}

    		else
    		{
    		p=p->right;
    		}


    	}
    	cout<<endl;
    }

    void preorder()
   {
       bool flag = 0;
       Node *p=root;
       while(p!=head)
       {
           if(flag==0)
           {
               cout <<p->data<<" ";
           }

           if(flag==0 && p->lbit==1)
           {
               p=p->left;
           }
           else
           {
               if(p->rbit==1)
               {
            	   flag=0;
               }
               else
               {
            	   flag=1;
               }
               p = p->right;
           }
       }

       cout<<endl;
    }

    // search
    bool search(int key, Node *&current, Node *&parent)
    {
        while (current != head)
        {
            if (current->data == key)
            {
                 return true;
            }
            else
            {
                parent = current;
                if (key < current->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
        }
        return false;
    }

    void deleteNode( Node *&t)  //p points to NULL  and t points root of the tree
    {
    	Node *p=NULL;

        if (t->lbit==1 && t->rbit==1) ///checking if root has both left and right bit set to 1;
            {
                Node *cs=t->right;    //cs will point to right of root
                p=t;                 // p will now point to root of the Tree
                while (cs->lbit==1)
                {
                    p=cs;
                    cs=cs->left;
                }
                t->data = cs->data;
                t = cs;
                cout<<"Deleting Node Having 2 links"<<endl;
            }


            if (t->lbit == 0 && t->rbit == 0)
            {
                if (p->left == t)
                {
                    cout<<"Deleting Leaf (Left)"<<endl;
                    p->left = t->left;
                    p->lbit = 0;
                }
                else
                {
                    cout<<"Deleting Leaf (Right)"<<endl;
                    p->right = t->right;
                    p->rbit = 0;
                }
                delete t;
            }


            if (t->lbit == 1 && t->rbit == 0)
            {
                Node *temp = t->left;
                if (p->left == t)
                {
                    p->left = temp;
                }

                else
                {
                    p->right = temp;
                }

                while (temp->rbit == 1)
                {
                    temp = temp->right;
                }
                temp->right = t->right;
                cout<<"Deleting Node with left link"<<endl;
                delete t;
            }


            if (t->lbit == 0 && t->rbit == 1)
            {
                Node *temp = t->right;
                if (p->left == t)
                {
                    p->left = temp;
                }
                else
                {
                    p->right = temp;
                }

                while (temp->lbit == 1)
                {
                    temp = temp->left;
                }
                temp->left = t->left;
                cout<<"Deleting Node with right link"<<endl;
                delete t;
            }
        }


};
int main() {
	TBST t;
    int temp;
    int n;
    int data;
	int choice;
	Node *parent;
	Node *current;
	do
	{
		cout<<endl;
		cout<<"1->Non-Recursive Inorder Traversal\n2->Non-Recursive Preorder Traversal\n3->Deletion of a node\n4->Insert Node\n5->Exit"<<endl;
		cin>>choice;
        cout<<endl;
		switch(choice)
		{
			case 1:
				cout<<"The inorder traversal gives:";
				t.inorder();
				break;

			case 2:
				cout<<"The preorder traversal gives:";
				t.preorder();
				break;

			case 3:
				cout<<"Enter the data of node to delete:";
				cin>>temp;
                parent=NULL;
                current=t.getroot();

				if(t.search(temp,current,parent))
				{
					t.deleteNode(current);
					cout<<temp<<" is deleted successfully!"<<endl;
				}

				else
				{
					cout<<temp<<" is not present."<<endl;
				}
				break;

			case 4:

				cout<<"Enter number of nodes to insert:";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"Enter data to insert:";
					cin>>data;
					t.insert(data);
				}
				break;

			default:
				cout<<"You entered wrong choice!"<<endl;
				break;
		}
	}while(choice!=0);
//	t.insert(5);
//	t.insert(10);
//	t.insert(3);
//	t.insert(2);
//	t.insert(1);
//	t.insert(10);
//	t.insert(9);
//	t.inorder();
//    cout<<"Reached here"<<endl;
//    t.preorder();
//    cout<<endl;
//    int temp;
//    cout<<"Enter node to delete:";
//    cin>>temp;
//    Node *parent=NULL;
//    Node *current=t.getroot();
//    if(t.search(temp, current, parent))
//    {
//    	t.deleteNode(parent, current);
//    	cout<<temp<<" is deleted successfully!"<<endl;
//
//    }
//    else
//    {
//    	cout<<temp<<" is not present!"<<endl;
//    }
//
//    t.inorder();
//    cout<<endl;
//
//    t.preorder();
      return 0;
}
