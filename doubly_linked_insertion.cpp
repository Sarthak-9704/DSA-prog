#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		node *prev;
};

void push(node **head, float new_data)
{
	node *new_node = new node();
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next=*head;
	(*head)->prev= new_node;
	*head=new_node;
}

void insert_end(node **head, float new_data)
{
	node* last=*head;
	node* new_node = new node();
	new_node->data=new_data;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new_node;
	new_node->next=NULL;
	new_node->prev=last;
	
}

void insert_after(node *prev_node, int new_data)
{
	node *new_node = new node();
	new_node->data=new_data;
	new_node->prev=prev_node;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
}
void reverse_show_data(node** head)
{
	node *last = *head;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	while(last->prev!=NULL)
	{
		cout<<last->data<<endl;
		last=last->prev;
	}
}
void show_data(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<endl;
        head=head->next;
    }
}

int main()
{
	node *head=new node();
//	head->next=NULL;
	int i;
	for (i=1;i<=10;i++)
	{
		push(&head, i);
	}
	cout<<"list is "; show_data(head);
	
//	insert_after(head->next->next->next, 999);
//	cout<<endl<<"reverse list is ";
//	reverse_show_data(&head);
//	insert_end(&head, 999);
	show_data(head);
}
