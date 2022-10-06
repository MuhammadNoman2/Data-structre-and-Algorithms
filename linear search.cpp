#include<iostream>
using namespace std;

void linear_search(int data[],int N, int item)
{
	data[N+1]=item;
	int loc=0;
	while(data[loc]!=item)
	{
		loc=loc+1;
	}
	if(loc==N+1)
	{
		cout<<"Item not found"<<endl;
	}
	else
	{
		cout<<" Item "<<item <<" Found at location : "<<loc<<endl;
	}
}
int main()
{
	int data[] = {3,6,1,8,9,4,10};
	int item=9;
	int size=7;
	cout<<"\n\t MUHAMMAD NOMAN \n";
	cout<<"\t 35152 \n\n";
	cout<<"\n\t LINEAR SEARCH \n\n";
	linear_search(data,size,item);
	return 0;
}

