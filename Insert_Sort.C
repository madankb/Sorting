/******************************************************************************************************************************************************************************************
Insert sorting :- Start from the element leaving one before element, compare previous element if it is bigger then swap (insert into that position). Now the array before the started 
                  position is sorted, now increase the position and continue until the length of array. Do the swappings only if previous element is bigger, if the previous element is
		  not bigger, no need to go back further because previous set of arrays is already sorted.
		  
Best case :- O(n) - If array is already sorted.

Worst case :- O(n^2) - If array is in descending order.

Good for small set of array. Good for reasonably sorted arrays.
*******************************************************************************************************************************************************************************************/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int A[]={15,14,13,12,11,10};
	
	int n=sizeof(A)/sizeof(A[0]);
	
	for(int i=1;i<n;i++)
	{
		int j=i;
		
		while (j > 0 && A[j-1] > A[j])
		{
			int temp=A[j-1];
			A[j-1]=A[j];
			A[j]=temp;
			
			j=j-1;
		}	
		
	}

	for(int j=0;j<n;j++)
	{
		printf("%d ",A[j]);
	}
	cout<<endl;
}	
