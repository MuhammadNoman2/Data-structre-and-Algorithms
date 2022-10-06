#include<iostream>
using namespace std;

void Binary_search(int data[], int item,int beg , int end)
{
	
	while(beg<=end)
	{
		
		int mid= ( beg + end)/2;
	
	if(data[mid]==item)
	{
		
		cout<<" Item : "<<item<<" found at location : "<<mid+1<<endl;;
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
	int data[]={ 3,4,5,6,7,8,9};
	int item;
	cout<<"\tMUHAMMAD NOMAN -  35152\n\n";
	cout<<"\tBinary Search \n\n";
	cout<<" Enter item to Search :";
	cin>>item;
	Binary_search(data,item,1,7);
	return 0;	
}
