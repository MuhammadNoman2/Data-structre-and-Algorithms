#include<iostream>
using namespace std;
void Insertion(int arr[],int N, int k , int item)
{
	int j=N;
		while(j>=k)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[k]=item;
		N++;	
}
int main()
{
	int LA[]={2,3,4,5,6};

	cout<<"\n\t MUHAMMAD NOMAN \t ID: 35152 \n\n";
	cout<<"\nOriginal Array : ";
		for(int i=0;i<5;i++)
	{
		cout<<LA[i]<<" ";
		
	}
		Insertion(LA,5,2,99);
	cout<<"\nUbdated array : ";
	for(int i=0;i<=5;i++)
	{
		cout<<LA[i]<<" ";
		
	}
	cout<<"\n";
	return 0;
}
