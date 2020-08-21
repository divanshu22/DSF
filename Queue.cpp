/*Implement priority queue as ADT using single linked list for servicing patients in an hospital
with priorities as i) Serious (top priority) ii) medium illness (medium priority) iii) General (Least
priority).*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class queue1
{
public:
     struct node
     {
         int data;
         char name[10];
         int reg;
         struct node * next;
     };

     struct node *head;
     struct node *rear;

queue1()
{
    head=NULL;
}

~queue1();
 void Enqueue();
 void Deque();
 int Qempty();
 void PrintTop();
 void display();
 void displayspecific();

};
void queue1::Enqueue()
{
    struct node *p,*q;
    p=new node;
    cout<<"\nEnter patient's name:- ";
    cin>>p->name;
    cout<<"\nEnter Patient's Reg. Number:-";
    cin>>p->reg;
    cout<<"\nEnter Priority:-\n3-Max 2-Medium 1-Least\n";
    cin>>p->data;

    p->next=NULL;
    if(head==NULL)
    {
        head=p;
    }

    else
    {
       if(p->data>head->data)
       {
           p->next=head;
           head=p;
       }
       else
        {
            q=head;
            while(q->next!=NULL && (p->data <= (q->next->data)))
                q=q->next;
                p->next=q->next;
                q->next=p;
        }
    }
}
void queue1::Deque()
{

 struct node *p;
 p=head;

 head=p->next;
 cout<<"\nDeleted element priority\t"<<p->data;
 cout<<"\nDeleted element name\t"<<p->name;
 cout<<"\nDeleted element registration number\t"<<p->reg;
 delete p;
}
void queue1::displayspecific()
{
    int k;
    node *p;
    p=head;
    cout<<"Enter The Priority Number:";
    cin>>k;
    while(p!=NULL)
    {
        if(k==p->data)
        {
            cout<<p->data<<'\t'<<p->name<<'\t'<<p->reg<<'\n';
        }
        else
            cout<<"Not Found";
       p=p->next;
    }
}

int queue1::Qempty()
{
    if(head==NULL)
    {
        return (1);
    }
else
 return (0);
}

void queue1::display()
{
    node *p;
    p=head;
    while(p!=NULL)
    {
        cout<<p->data<<'\t'<<p->name<<'\t'<<p->reg<<'\n';
        cout<<"===============================================\n";
        p=p->next;
    }
}

void queue1::PrintTop()
{
    cout<<head->data<<'\t'<<head->name<<'\t'<<head->reg;
}

queue1::~queue1()
{

 struct node *p;
 p=head;
 while(head!=NULL)
    {

  p=head;
  head=head->next;
  delete p;

    }
}

int main()
{
 queue1 s;
 int x,n,ch,i;
 char c;
 struct node *head;
 char pname[10];
 do
 {
     cout<<"Enter Your Choice-\n1.Create\n2.Insert\n3.Sevice Fulfill\n4.Top Display\n5.Display Overall\n6.Display Specific\n";
     cin>>ch;
     switch(ch)
     {
     case 1:
        s.Enqueue();
        break;
     case 2:
        cout<<"Insert :\n";
        s.Enqueue();
     case 3:
        if(s.Qempty())
        {
            cout<<"Queue is empty and can't be deleted.\n";
        }
        else
            s.Deque();
        break;
     case 4:
        cout<<"Element at the Front of queue:";
        s.PrintTop();
        break;
     case 5:
        cout<<"Display:-";
        s.display();
        break;
     case 6:
        s.displayspecific();
     }
cout<<"\nWant to continue:";
cin>>c;
}while(c!='n');

return 0;
}
