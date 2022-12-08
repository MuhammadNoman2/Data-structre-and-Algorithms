#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *link;
};
// top pointer to keep track of the top of the stack

Node *top = NULL;

// function to chec if stack is empty

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

// function to insert an element in stack

void push(int value)
{
	Node *ptr = new Node();
	ptr->data = value;
	ptr->link = top;
	top = ptr;
}

//function to delete the element from the stack

void pop()
{
	if( isempty())
	{
		cout<<"Stack is empty\n";
	}
	else{
	Node *ptr = top;
	top = top->link;
	delete(ptr);
	}
}

// Function to show the element at the top of the stack

void showTop()
{
	if(isempty())
	{
		cout<<"Stack is empty and there is no value to show\n";
	}
	else
	{
		cout<<"Element at the top : "<<top->data<<"\n";
	}
	
}
	// Function to display the stack
	
void displayStack()
{
	if( isempty())
	{
		cout<<"Stack is empty\n";
	}
	else
	{
	    cout<<"\nElements in the stack: ";
		Node *temp = top;
		while(temp!= NULL)
		{
			cout<<temp->data<<"->";
			temp = temp->link;
		}
		cout<<"NULL\n";
	}
	
}
int main()
{
	cout<<"\nName -> Muhammad Noman \t ID -> 35152\n";
	cout<<"Data -> 12/8/2022\n\n";
	
	int choice , flage=1, value;
	
	// main drivemn program using switch
	while( flage == 1)
	{
		cout<<"[1]. Push\n";
		cout<<"[2]. Pop\n";
		cout<<"[3]. showTop\n";
		cout<<"[4]. displayStack\n";
		cout<<"[5]. Exit\n";
		
		cout<<"\nEnter Your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					 cout<<"\nEnter value : ";
					 cin>>value;
					 push(value);
					 break;
				}
			case 2: 
			{
				pop();
				break;
				}	
			case 3:
				{
					showTop();
					break;
				}
			case 4:
				{
					displayStack();
					break;
				}
			case 5:
				{
					flage = 0;
					cout<<"\n\tGood Bye!...";
					break;
				}
		}
	}
	return 0;
}
