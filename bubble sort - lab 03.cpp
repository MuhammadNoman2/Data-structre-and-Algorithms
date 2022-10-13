#include<iostream>
using namespace std;

void bubble_sort(int arr[],int size)
{
	for(int step = 0; step < (size-1); ++step)
	{
		int swapped = 0;
		for(int i=0; i< (size-step-1); ++i)
		{
			//change > to < to sort in descending order
			if(arr[i] > arr[i+1])
			{
				int temp = arr[i];
				arr[i]= arr[i+1];
				arr[i+1] = temp;
				
				swapped = 1;
			}
		}
		if (swapped == 0)
			
			break;
}
}
void printarr(int arr[], int size)
	{
		for (int i= 0; i<size; i++)
		{
			cout<<" "<<arr[i];
		}
		
		cout<"\n";	

}
int main()
{
	int array[10];
	int size= sizeof(array) / sizeof(array[0]);
	cout<<"\tMUHAMMAD NOMAN \tID: 35152-BSCS"<<endl;
	cout<<"\tBubble Sort Algorithm...";
	cout<<"\nEnter elements to the Array "<<endl;
	for(int i=0; i<size;i++)
	{
		cout<<"\nEnter Element at Index ["<<i+1<<"] :";
		cin>>array[i];
	}
	bubble_sort(array,size);
	cout<<" Sorted Array in Ascending order:\n";
	bubble_sort(array,size);
	
	return 0;
	
}
