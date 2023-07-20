#include<iostream>
using namespace std;

 class node{
 	public:
 		int data;
 		node *next;
 };

 void insert(node **tail, int element, int d)
 {
 	if (*tail==NULL)
 	{
 //		cout<<"if loop commence ";
 		node *new_node = new node();
 		new_node->data=d;
 		new_node->next=new_node;
 //		cout<<new_node->next->data;
 		*tail=new_node;
 	}
 	else 
 	{
 		node *current = *tail;
 		while (current->data!=element)
 		{
 			current=current->next;
 		}
 		if (current->data==element)
 		{
 			cout<<"element found, now inserting data "<<endl;
 			node *new_node = new node();
 			new_node->data=d;
 			new_node->next=current->next;
 			current->next=new_node;
 		}
 		else
 		{
 			cout<<"element not found "<<endl;	
 		}
 	}
 }

 void delete_node(node *tail, int element)
 {
 	node *prev = tail;
 	node *curr = prev->next;
 	if (curr->data==element)
 	{
 		cout<<"element found. Now deleting #1"<<endl;
 		prev->next=curr->next;
 		curr->next=NULL;
 	}
// 	else if (tail->data==element)
// 	{
// 		cout<<"tail found"<<endl;
// 		tail=tail->next;
//	}
 	else
 	{
 		while(curr->data!=element)
 		{
 			curr=curr->next;
 		}
		
 		if(curr->data==element)
 		{
 			cout<<"element found. Now deleting #2"<<endl;
 			node *temp = curr;
 			while (temp->next!=curr)
 			{
 				temp=temp->next;
			}
// 			insert code to point the element just before element to the element after current so as to skip current and take it out of the linked list
 			temp->next=curr->next;
 			curr->next=NULL;
 		}
 	}
 }
 void show_data(node* tail)
 {
 	node *temp = tail;
 	do{
         cout<<tail->data<<endl;
         tail=tail->next;
     }while (tail!=temp);
 }

 int main()
 {
 	node *tail = NULL;
 	insert(&tail, 0, 1);
 	show_data(tail);
 //cout<<tail->data;	
 	insert (&tail, 1, 2);
 	show_data(tail);
 	insert (&tail, 2,3);
 	show_data(tail);
 	insert (&tail, 3,4);
 	insert (&tail, 4,5);
 	show_data(tail);
 	delete_node(tail,3);
 	show_data(tail);
 }

