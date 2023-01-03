#include<iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

string check(int);
int display1();
int search(int);

struct node{
    node *prev;
    int data;
    int x,y,sum;     //x == quantity
    string name,nam;   //y == price
    node *next;
};

struct node *start=NULL;
node* create_node(){
    node *n = new node;
    cout<<"ENTER PRODUCT ID: "<<endl;
    cin>>n->data;
    cout<<"ENTER PRODUCT NAME: "<<endl;
    cin>>n->name;
    cout<<"ENTER QUANTITY: "<<endl;
    cin>>n->x;
    cout<<"ENTER PRICE OF EACH PRODUCT: "<<endl;
    cin>>n->y;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void insert_node(){
    node *temp;
    temp = create_node();
    if(start == NULL){
    start = temp;
    }
    else{
    node *traverse;
    traverse = start;
    while(traverse->next != NULL){
        traverse = traverse->next;
    }
    traverse->next=temp;
    temp->prev=traverse;
}
}
bool isempty()
{
	if(start == NULL)
	{

		return true;
	}
	else
	{
		return false;
	}
}
void add_begin(){
node *temp;
temp = create_node();
temp->next = start;
start->prev = temp;
start=temp;
}

void add_after(){
node *temp;
temp= create_node();
int value;
cout<<"Enter the product id after which the product has to be inserted :"<<endl;
cin>>value;
node *traverse;
traverse = start;
while(traverse->data!=value){
    traverse = traverse->next;
}
//temp->data=value;
temp->next=traverse->next;
temp->prev = traverse;
traverse->next = temp;
traverse->next->prev = temp;
}

void display(){
node *traverse;
traverse  = start;
system("cls");
cout<<"\n\n\t\t\t**********************ALL MART STORE*****************************"<<endl;
cout<<"\nPRODUCT ID\t"<<"PRODUCT NAME\t"<<"QUANTITY\t"<<"PRICE"<<endl;
while(traverse!=NULL){
    cout<<traverse->data<<"\t\t";
    cout<<traverse->name<<"\t\t";
    cout<<traverse->x<<"\t\t";
    cout<<traverse->y<<"\n\n";
    traverse = traverse->next;

}
}

void delete_beg(){
	if(isempty())
	{
			cout<<"\n\n\tStack is empty There is no product in the store\n\n";
	}
	else
	{
	
    node *temp;
    temp = start;
    start = start->next;
    cout<<"\n\n\t\t\tProduct at the Begining successfully Deleted...\n"<<endl;
    delete(temp);
}
}

void delete_end(){
	if(isempty())
	{
			cout<<"\n\n\tStack is empty There is no product in the store\n\n";
	}
	else
	{
	
    node *traverse;
    traverse = start;
    while(traverse->next != NULL){
    traverse = traverse->next;
    }
    traverse->prev->next = NULL;
   	cout<<"\n\n\t\t\tProduct at the End successfully Deleted...\n"<<endl;
    delete(traverse);
}
}

void delete_after(){
	if(isempty())
	{
			cout<<"\n\n\tStack is empty There is no product in the store\n\n";
	}	
	else
	{
	
		int value;
		cout<<"Enter the product ID after which the node has to be deleted"<<endl;
		cin>>value;
		node *traverse;
		traverse = start;
		while(traverse->data != value){
    	traverse = traverse->next;
			}
if(traverse->next==NULL)
{
	cout<<"\ncan't Deleted...\n";
}
	else if(traverse->next->next==NULL)
	{	
		traverse->next=NULL;
	}
	else{
	
		node *temp;
		temp = traverse->next;
		traverse->next = temp->next;
		temp->next->prev = traverse;
		delete(temp);
		}
	}
}
void buy(){
    system("cls");
    string products[20];
    int pay=0,no,c=0,price,id,i=1;
    if(start==NULL) {
	cout<<"\n<<<<There is no items to buy>>>>\n\n";
        }
	else{
        cout<<"How many items you wanna to buy!\n";
		cin>>no;
			int count= display1();
	while (i<=no){
			struct node *cur=start;
    int quant,cho;
	cout<<"Enter id of item that you want to buy: \n";
    int id,pos=0;
	cin>>id;
	pos=search(id);
	if(pos<=count){
		while(cur->data!=id){
			cur=cur->next;
		}
	cout<<"How many quantities you want: \n";
	cin>>quant;
	products[c]=cur->name; c++;
	pay=pay+(cur->y*quant);
	cur->x=cur->x-quant;
	i++;
	}
	else{
		cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
	    }
}
	//system("cls");
cout<<"\n\n\n\t\t\tYou have bought : ";
for(int i=0;i<no;i++){
	cout<<products[i]<<",";
}
price=pay*(0.95);
	cout<<"\n\nOriginal price : "<<pay;
    cout<<"\n with 5% discount: "<<price<<"\nThank you! for the shopping\n\n";
}
}
	int search(int id)
 {
 	int count=1;
 	struct node *p=start;
 	while(p!=NULL)
 	{
 		if(p->data==id)
 		{

 			break;    }
 		else
 			count++;
 			p=p->next;
	}

 	return count;
 }

int display1(){
	//	system("cls");
    int c=0;
    struct node *p=start;
    cout<<"Existing products are:\n";
    cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    while(p!=NULL)
		{
			cout<<p->data<<"\t\t"<<p->name<<"\t\t\t"<<p->y<<"\t\t"<<check(p->x)<<"\n";
			p=p->next;
			c=c+1;
		}
    cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
    return c;
}

string check(int quant){
    int a = quant;
    stringstream ss;
    ss << a;
    string quantity = ss.str();
    if(quant<=0)
    return "out of stock!";
    else
    return quantity;
}

void srch(){
    system("cls");
    cout<<"\n\n\t\t\t**********************ALL MART STORE*****************************\n\n\n"<<endl;
    string nam;
    cout<<"Enter Product Name "<<endl;
    cin>>nam;
    int f=0;
 	struct node *p=start;
 	while(p!=NULL)
 	{
 		if(nam==p->name)
 		{
 		    f=1;
 			break;
 			    }

 			p=p->next;
	}

	if(f==1)
    {
        	cout<<"\n\t\tProduct is available\n"<<endl;
        	cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
        	cout<<p->data<<"\t\t"<<p->name<<"\t\t\t"<<p->y<<"\t\t"<<check(p->x)<<"\n\n";
        	
    }
    else{
            cout<<"Out of Stock"<<endl;

    }
}

int main(){
system("color 1E");
int option;
 cout<<"\n\n\t\t\t**********************ALL MART STORE*****************************\n"<<endl;
cout<<"\t\t\t**********************\tImplemnted by\t**********************\n"<<endl;
cout<<"\t\t\t**********************\tMuhammad Noman\t**********************\n"<<endl;
 cout<<"\t\t\t*****************************************************************\n"<<endl;
 system("pause");
 system("cls");
  cout<<"\n\n\t\t\t**********************ALL MART STORE*****************************\n"<<endl;
do{

cout<<"\t1 ADD PRODUCT"<<endl;
cout<<"\t2 ADD PRODUCT AT FIRST POSITION"<<endl;
cout<<"\t3 ADD PRODUCT AFTER A GIVEN POSITION"<<endl;
cout<<"\t4 DELETE PRODUCT AT LAST POSITION"<<endl;
cout<<"\t5 DELETE PRODUCT AT FIRST POSITION"<<endl;
cout<<"\t6 DELETE PRODUCT AT AFTER A GIVEN POSITION"<<endl;
cout<<"\t7 DISPLAY"<<endl;
cout<<"\t8 BUY"<<endl;
cout<<"\t9 SEARCH"<<endl;
cout<<"\t0 Exit"<<endl;
cin>>option;
   switch(option){
   case 1:
   {
   		insert_node();
   		cout<<"\n\n\t\t\tProduct successfully inserted...\n"<<endl;
   		display1();
          break;
      }
   case 2: 
   {
   		add_begin();
   		cout<<"\n\n\t\t\tProduct at the Begining successfully added...\n"<<endl;
   		display1();
           break;
       }
   case 3: 
   {
   		add_after();
   		cout<<"\n\n\t\t\tProduct successfully added...\n"<<endl;
   		display1();
           break;
       }
   case 4:
   {
		delete_end();
   		display1();
           break;
       }
   case 5: 
   {	
   		delete_beg();
   		display1();
           break;
       }
   case 6: 
   {
   		delete_after();
   		cout<<"\n\n\t\t\tProduct successfully Deleted...\n"<<endl;
   		display1();
           break;
       }
   case 7: 
   {
   		display();
           break;
       }
   case 8:  
   {
   		buy();
           break;
       }
   case 9: 
   {
   		srch();
   		
            break;
        }
   }

}while(option != 0);
return 0;
}
