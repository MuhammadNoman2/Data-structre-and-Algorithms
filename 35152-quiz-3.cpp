#include<iostream>
using namespace std;

struct Node{
	string data;
	Node *Link;
};

Node *top = NULL;
bool isempty()
{
	if(top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void push(string value)
{
	Node *ptr = new Node();
	ptr->data=value;
	ptr->Link = top;
	top = ptr;
}
void display()
{
	if (isempty())
	{
		cout<<"\nStack is empty\n";
	}
	else
	{
		Node *temp = top;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp = temp->Link;
		}
		cout<<"NULL\n";
	}
}
int main()
{
	cout<<"\n\tMuhammad Noman \t ID : 35152\n";
	cout<<"\tDate : 12/15/2022\n";
	cout<<"\tQuiz # 03\n\n";
	
	int choice , flag =1;
	string value;
	while(flag ==1)
	{
	
	cout<<"[1] push\n";
	cout<<"[2] display\n";
	cout<<"[3] exit\n";
	cout<<"\nEnter your choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				cout<<"Enter Student ID :";
				cin>>value;
				push(value);
				cout<<"Enter Student Name :";
				cin>>value;
				push(value);
				cout<<"Enter Student Father Name :";
				cin>>value;
				push(value);
				cout<<"Enter Student Freind Name :";
				cin>>value;
				push(value);
				break;
			}
		case 2:
				{
					display();
					break;
				}
		case 3:
				{
					flag =0;
					break;
				}
	}
}
	return 0;
}
