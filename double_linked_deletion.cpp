#include<iostream>
using namespace std;

class node{
	public: 
	int data;
	node* prev;
	node* next;
};

void push(node **head, float new_data)
{
	node *new_node = new node();
	new_node->data = new_data;
	new_node->prev=NULL;
	new_node->next=*head;
	(*head)->prev= new_node;
	*head=new_node;
}

void del_beg(node *head)
{
	head=head->next;
	head->prev=NULL;	
}

void delete_node(node **head, node *del)
{
	node *temp = *head;
	while(temp->next!=del)
	{
		temp=temp->next;
	}
	
	del->prev=NULL;
	del->next->prev=temp;
	temp->next=del->next;
}

void show_data(node* a)
{
    while(a!=NULL)
    {
        cout<<a->data<<endl;
        a=a->next;
    }
}

void reverse_show_data(node** head)
{
	node *last = *head;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	while(last!=NULL)
	{
		cout<<last->data<<endl;
		last=last->prev;
	}
}
int main()
{
	node *head = new node();
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);
	
	delete_node(&head, head->next->next);
	show_data(head);
	reverse_show_data(&head);
}
