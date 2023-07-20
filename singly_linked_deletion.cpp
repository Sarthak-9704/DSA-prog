#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
};

void push(node **head, float new_data)
{
	node *new_node = new node();
	new_node->data=new_data;
	new_node->next= *head;
	*head = new_node;
}

void append (node **head, float new_data)
{
	node *new_node= new node();
	new_node->data= new_data;
	new_node->next= NULL;
	node *last= *head;
	
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new_node;
	
}

void del(node **head, int key)
{
	node *temp = *head;
	node *prev= *head;
	if (temp->data==key && temp!=NULL)
	{
		*head=temp->next;
		delete temp;
	}
	else 
	{
		while(temp!=NULL && temp->data!=key)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		{
			return;
		}
		prev->next=temp->next;
		delete temp;
	}
}

void show_data(node* a)
{
//    int n=0;
    while(a!=NULL)
    {
        cout<<a->data<<endl;
        a=a->next;
    }
}

int main()
{
	node *n[5];
	int i;
	for (i=0;i<5;i++)
	{
		n[i]= new node();
	}
	
	for (i=0;i<5;i++)
	{
		n[i]->data=(i+1);
		if(i<4)
		{
			n[i]->next = n[i+1];
		}
	}
	n[4]->data=5;
	n[4]->next=NULL;
	
	show_data (n[0]);
	del(&n[0], 2);
	show_data(n[0]);

}
