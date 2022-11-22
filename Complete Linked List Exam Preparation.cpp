#include<iostream>
using namespace std;
 struct Node{
 	int data;
 	Node *Next;
 };
 
 void insertAtFront(Node **head, int data){
 	
 	Node * new_node = new Node();
 	new_node->data = data;
 	new_node->Next = *head;
 	*head = new_node;
 	cout<<"Inserted Item: "<<new_node->data<<endl;
 	
 }
 
 void insertAtEnd(Node **head , int data){
 	Node *new_node = new Node();
 	new_node->data=data;
 	new_node->Next=NULL;
 	
 	if(head==NULL)
 	{
 		*head = new_node;
 		
	 }
	 else
	 {
	 	Node *Last = *head;
	 	while(Last->Next !=NULL)
	 	{
	 		Last = Last->Next;
	 	
		 }
		 	Last->Next = new_node;
	 }
	 cout<<"\nInserted Item: "<<new_node->data<<" At the End."<<endl;
 }
 
 void insertAtGivenPosition(Node **head , int data , int pos){
 	Node *new_node = new Node();
 	new_node->data = data;
 	new_node->Next = NULL;
 	
 	if(pos==0)
 	{
 		cout<<"\nPosition must be >= 0\n";
 		
	 }
	 else if(pos == 1)
	 {
	 	new_node->Next = *head;
	 	*head = new_node;
	 }
	 else{
	 	Node *temp = *head;
	 	for(int i =0; i<(pos-1); i++)
	 	{
	 		if(temp!=NULL)
	 		{
	 			temp = temp->Next;
			 }
		 }
	 
	 if(temp != NULL)
	 {
	 	new_node->Next = temp->Next;
	 	temp->Next = new_node;
	 }
	 else{
	 	cout<<"\nThe previous node is null.";
	 }
 }
 cout<<"\nInserted Item: "<<new_node->data<<" At the position : "<<pos<<endl;
}

void pop_front(Node **head){
	if(*head == NULL)
	{
		cout<<"List is empty\n";
	}
	else if(head != NULL){
		Node *temp = *head;
		*head = (*head)->Next;
		temp->data;
		delete(temp);
	}
}

void pop_back(Node **head)
{
	if(*head!=NULL)
	{
		if((*head)->Next == NULL){
			*head = NULL;
		}
		else{
			Node *temp = *head;
			while(temp->Next->Next != NULL)
			{
				temp = temp->Next;
			}
			Node *LastNode = temp->Next;
			temp->Next = NULL;
			delete(LastNode);
		}
	}
}

 void pop_At(Node **head , int pos){
 	
 	if(pos<=0)
 	{
 		cout<<"\nPosition must be >= 0\n";
 		
	 }
	 else if(pos == 1)
	 {
	 	if(*head != NULL){
	 		Node * NodeToDelete = *head;
	 		*head = (*head)->Next;
	 		delete(NodeToDelete);
		 }
    }
	 else{
	 	Node *temp = *head;
	 	for(int i =0; i<(pos-1); i++)
	 	{
	 		if(temp!=NULL)
	 		{
	 			temp = temp->Next;
			 }
		 }
	 
	 if(temp != NULL)
	 {
	 	if(temp->Next!=NULL)
	 	{
	 		Node * NodeToDelete = temp->Next;
	 		temp->Next = temp->Next->Next;
	 		delete(NodeToDelete);
		 }
	 }
	 else{
	 	cout<<"\nThe previous node is null.";
	 }
 }
}

 void printList(Node* node)
 {
 	cout<<"\nLinked List : ";
 	while(node!=NULL){
 		cout<<node->data<<"->";
 		node = node->Next;
	 }
	 cout<<"Null\n";
 }
 int main(){
 	int elem,pos,size;
 	Node *head = NULL;
	 
 	insertAtFront(&head, 1);
 	insertAtFront(&head, 2);
 	insertAtFront(&head, 3);
 	insertAtFront(&head, 4);
 	
 	printList(head);
 	cout<<"\nEnter Element to insert at end: ";
 	cin>>elem;
 	insertAtEnd(&head, elem);
 	printList(head);
 
 	cout<<"\nEnter Element to insert : ";
 	cin>>elem;
 	cout<<"\nEnter position : ";
 	cin>>pos;
 	insertAtGivenPosition(&head, elem , pos);
 	printList(head);
 	
 	pop_front(&head);
 	cout<<"\nDeleted First Node of the Linked List.";
 	printList(head);
 	
 	pop_back(&head);
 	cout<<"\n Deleted Last Node of the Linked List.";
 	printList(head);
 	cout<<"\nEnter Position of node to delete : ";
 	cin>>pos;
 	pop_At(&head,pos);
 	cout<<"\nDeleted node sucessfully at position : "<<pos<<endl;
 	printList(head);
 	return 0;
 }
