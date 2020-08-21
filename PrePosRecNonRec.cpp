#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	char name;
	node *left=NULL,*right=NULL;
}node;
typedef struct node1
{
	node *link;
	node1 *next;
}node1;
typedef struct node2
{
	node2 *next=NULL;
	node *link;
	int flag=0;
}node2;
class Stack
{
	node1 *top;
		public:
  			Stack()
			{
    		top = NULL;
  			}
		void push( node* a)
			{
    		 node1 *ptr = new node1;
   			 ptr->link = a;
    		 ptr->next = top;
    		 top = ptr;
  			}
		 node *pop()
			{
    		 struct node1 *ptr;
   			 ptr = top;
   			 top = top->next;
    		 return ptr->link;
  			}
		bool is_empty()
			{
			  if(top == NULL)
     		  return true;
    		  return false;
  			}
};
class Stack2
{
	node2 *top;
		public:
  			Stack2()
			{
    			top = NULL;
  			}
	void push(node *a, int b)
	{
		node2 *ptr = new node2;
		ptr->link = a;
		ptr->next = top;
		ptr->flag = b;
		top = ptr;
	}
	struct node* pop(int * a){
    struct node2* ptr;
    ptr = top;
    *a = top->flag;
    top = top->next;
    return ptr->link;
  }
	bool is_empty()
	{
		if(top == NULL)
		return true;
		return false;
	}
};
class ex_tree
{
	node *head;
		public:
  			ex_tree()
			{
    			head = NULL;
  			}
		bool is_operand(char a)
		{
    		if(a=='/' || a=='+' || a=='-' || a=='*' || a=='^')
      			return false;
    		return true;
		}
	void build_tree(string a,int f)
		{
			class Stack S;
			node *ptr;
			int len = a.length();
			if(f == 1)
			{
			for(int i = len-1;i >= 0; i--)
				{
					ptr = new node;
					ptr->name = a[i];
					if(is_operand(a[i]))
					S.push(ptr);
					else
					{
						ptr->left = S.pop();
						ptr->right = S.pop();
						S.push(ptr);
        			}
      			}
			}
			else
			{
			for(int i = 0;i < len;i++)
			{
				ptr = new node;
				ptr->name = a[i];
				if(is_operand(a[i]))
				S.push(ptr);
				else
				{
					ptr->right = S.pop();
					ptr->left = S.pop();
					S.push(ptr);
				}
			}
			}
			head = S.pop();
		}
	void rec_post(node* root)
		{
			if(root == NULL)
			return;
			rec_post(root->left);
			rec_post(root->right);
			cout<<root->name<<' ';
		}

	void rec_in(node* root)
		{
			if(root == NULL)
			return;
			rec_in(root->left);
			cout<<root->name<<' ';
			rec_in(root->right);
  		}

	void rec_pre(node* root)
		{
			if(root == NULL)
			return;
			cout<<root->name<<' ';
			rec_pre(root->left);
			rec_pre(root->right);
		}

	void rec()
		{
			cout<<"Preorder:\n";
			rec_pre(head);
			cout<<'\n';
			cout<<"Inorder:\n";
			rec_in(head);
			cout<<'\n';
			cout<<"Postorder:\n";
			rec_post(head);
			cout<<'\n';
		}
	 void non_rec(){
    class Stack2 S;
    int flag;
    vector <char> inorder, preorder, postorder;
    struct node *current = head;
    struct node *ptr;
    do{
      while(current != NULL){
        S.push(current,0);
        preorder.push_back(current->name);
        current = current->left;
      }
      if(current == NULL && S.is_empty() == false){
        ptr = S.pop(&flag);
        if(flag == 1)
          postorder.push_back(ptr->name);
        else{
          S.push(ptr,1);
          inorder.push_back(ptr->name);
          current = ptr->right;
        }
      }
    }while(current != NULL || S.is_empty() == false);
    cout<<"Preorder:\n";
    for(int i =0;i<preorder.size();i++)
      cout<<preorder[i]<<' ';
    cout<<'\n';
    cout<<"Inorder:\n";
    for(int i=0; i<inorder.size();i++)
      cout<<inorder[i]<<' ';
    cout<<'\n';
    cout<<"Postorder:\n";
    for(int i=0;i<postorder.size();i++)
      cout<<postorder[i]<<' ';
    cout<<'\n';
  }


};

int main()
{
	string ex;
	class ex_tree T;
	int i;
	bool con, con2;
	do
	{
		do
		{
			con2 = false;
			cout<<"enter your choice  : \n";
			cout<<"1. enter prefix\n2. enter postfix\n";
			cin>>i;
			switch(i)
			{
				case 1:
					cout<<"enter the prefix expression  :  ";
					cin>>ex;
					T.build_tree(ex,1);
					break;
				case 2:
					cout<<"enter the postfix expression  :  ";
					cin>>ex;
					T.build_tree(ex,2);
					break;
				default:
						cout<<"$$$$$$$$$$$$  INVALID CHOICE  $$$$$$$$$$$$\n";
					con2 = true;
			}
		}while(con2);
		do
		{
			con2 = true;
			cout<<"select your choice  :  \n";
			cout<<"1. Traversal by non-recursive method\n";
			cout<<"2. Traversal by recursive method\n";
			cout<<"0. Back\n";
			cin>>i;
			switch(i)
				{
					case 1:
						T.non_rec();
						break;
					case 2:
						T.rec();
						break;
					case 0:
						con2 = false;
						break;
						default:
							cout<<"$$$$$$$$$$$$  INVALID CHOICE  $$$$$$$$$$$$\n";
				}
		}while(con2);
			cout<<"If you want to continue press 1 else press 0  :  ";
			cin>>con;
	}while(con);
}
