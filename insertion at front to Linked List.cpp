// INSERTION AT THE START-FRONT OF THE LINKED LIST

#include<iostream>
using namespace std;

class Node {
	public:
	int data;
	Node *Next;
};

// Node **head is the addresss part 
void insertFront(Node **head, int data)
{
	// new node() is a build in function used to allocate the memory at run time
	// Node* new_node is a class type pointer variable
	Node *new_node = new Node();
	// assign data
	// -> access operator work as a . dot operator
	new_node->data = data;
	//change the next node of the newNode
	// to current head of Linked List
	new_node->Next = *head;
	
	// new_node should become the new head of Linked List
	*head = new_node;
	
	cout<<"Inserted Item : "<< new_node->data<<endl;
}

void printList(Node* node)
{
	
	cout<<"\n Linked List : ";
	// as linked List will end when Node is Null
	while(node != NULL)
	{
		cout<<node->data<< " ";
		node = node->Next;
	}
	cout<<endl;
}
int man()
{
	cout<<"\t--------------------------------------------\n";
		cout<<"\t-MUHAMMAD NOMAN - 35152 BSCS             -\n";
		cout<<"\t--------------------------------------------\n\n";
	Node *head = NUll;
	insertFront(&head,4)
	insertFront(&head,5)
	insertFront(&head,6)
	insertFront(&head,7)
	insertFront(&head,8)
	insertFront(&head,9)
	
	printList(head);
	return 0;
}
