#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
};

void insert_beg(node **head, float newdata)
{
	node *new_node= new node();
	new_node->data=newdata;
	new_node->next=(*head);
	(*head)=new_node;
}

void insert_end(node **head, float newdata)
{
	node *new_node= new node();
	new_node->data=newdata;
	new_node->next=NULL;
	node *last= *head;
	
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new_node;
}

void insert_mid(node* prev, float newdata)
{
	
	if(prev==NULL)
	{
//		insert_end(node **head, int newdata)
		cout<<"error";
	}
	else
	{
		node *new_node = new node();
		new_node->data=newdata;
		new_node->next=prev->next;
		prev->next=new_node;
	}
}
void show_data(node* a)
{
    int n=0;
    while(a->next!=NULL)
    {
        cout<<a->data<<endl;
        a=a->next;
    }
}

int main()
{
	node *head = new node();
	node *n[3];
	int i=0;
    for (i=0;i<3;i++)
    {
        n[i]=new node();
    }
	node *tail= new node();
	
	head->data=0;
	head->next=n[0];
	
	for(i=0;i<3;i++)
	{
		n[i]->data=(i+1);
		if (i!=2)
		n[i]->next=n[i+1];
		else
		n[i]->next=tail;
	}
	
	tail->data=4;
	tail->next=NULL;
	
	show_data(head);
//	insert_beg(&head, -1);
//	cout<<"\n";
//	show_data(head);
	
	insert_mid(n[1], 999);
	show_data(head);
	
	insert_end(&head, 4);
	cout<<endl;
	show_data(head);
}




