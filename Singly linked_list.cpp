#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node *next;
};

void inp_data(node *a)
{
    int n=0;
    for(n=0; n<3; n++)
    {
        cin>>a->data;
        a=a->next;
    }
}

void show_data(node* a)
{
    int n=0;
    for (n=0;n<3;n++)
    {
        cout<<a->data;
        a=a->next;
    }
}
int main()
{
    node *n[3];
    int i=0;
    for (i=0;i<3;i++)
    {
        n[i]=new node();
    }
//inp_data(n[0]);

//	n[0]->data=1;
	n[0]->next=n[1];
//	n[1]->data=2;
	n[1]->next=n[2];
//	n[2]->data=3;
	n[2]->next=NULL;
inp_data(n[0]);	
show_data(n[0]);

}
