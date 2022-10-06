#include<iostream>
using namespace std;

void Binary_search(int data[], int item,int beg , int end)
{
	while(beg<=end)
	{	
		int mid = ( beg + end)/2;
	
	if(data[mid]==item)
	{	
		cout<<" \n Item : "<<item<<" found at Index : "<<mid+1<<endl;;
		break;
	}
	else if(item<data[mid])
	{	
		end=mid-1;
	}
	else if(item>data[mid])
	{	
		beg=mid+1;
	}
}
}
int main()
{
	int data[10];
	
	int item,i;
	cout<<"\tMUHAMMAD NOMAN -  35152\n\n";
	cout<<"\tBinary Search \n\n";
	cout<<"Enter Elements To array... \n\n";
	for(i=0;i<10;i++)
	{
		cout<<"Enter Element At index : "<<i+1<<" : ";
		cin>>data[i];
	}
	cout<<" Enter item to Search :";
	cin>>item;
	Binary_search(data,item,1,7);
	return 0;	
}
