/***************************************************************************************************************************************************************************************

Merge sort is dividing the group of elements into single element(divide) and compare the elements to form sorted subsets and comparision between subsets to form sorted superset.

Merge sort is a stable sort which mainitains the posistion of duplicate elements.

Time complexity :- O(n.log n) - Best,Average and Worst case
****************************************************************************************************************************************************************************************/
#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
	int key;
	struct node* next;
};
void push(struct node** a,int key)
{
	struct node* temp=new node;
	temp->key=key;
	temp->next=*a;
	
	*a=temp;
}
void print(struct node* a)
{
	while (a != NULL)
	{
		printf("%d ",a->key);
		a=a->next;
	}
	cout<<endl;
}
void FrontBacksplit(struct node* a,struct node** front,struct node** back)
{
	if (a == NULL)
		return;
	
	struct node* slow=a;
	struct node* fast=a->next;
	
	while (fast != NULL)
	{
		if (fast->next != NULL)
		{
			slow=slow->next;
			fast=fast->next->next;
		}
		else
			fast=fast->next;
	}

	*front=a;
	*back=slow->next;
	slow->next=NULL;
	
	return;
}
struct node* SortedMerge(struct node* f,struct node* b)
{
	struct node* result=NULL;
	struct node** ref=&result;
	
	while(1)
	{
	        if (f == NULL)
		{
			*ref=b;
			break;
		}	
		else if (b == NULL)
		{
			*ref=f;
			break;
		}
		else
		{
			if (f->key <= b->key)
			{
				*ref=f;
				f=f->next;
			}
			else
			{
				*ref=b;
				b=b->next;
			}
			
			ref=&((*ref)->next);
		}
	}		

	return result;
}
void Merge_sort(struct node** c)
{
	if (*c == NULL || (*c)->next == NULL)
		return;
	
	struct node* front=NULL;
	struct node* back=NULL;
	
	FrontBacksplit(*c,&front,&back);
	
	Merge_sort(&front);
	Merge_sort(&back);
	
	*c=SortedMerge(front,back);
}	
int main()
{
	struct node* a=NULL;
	push(&a,16);
	push(&a,15);
	push(&a,14);
	push(&a,13);
	//push(&a,12);
	
	struct node* f=NULL;
	struct node* b=NULL;
	
	FrontBacksplit(a,&f,&b);
	
	print(f);
	print(b);
	
	struct node* merge=SortedMerge(f,b);//You made mistake here, (f,b) without including the function.
	
	print(merge);
	
	struct node* c=NULL;
	push(&c,23);
	push(&c,16);
	push(&c,12);
	push(&c,1);
	push(&c,8);
	push(&c,92);
	push(&c,45);
	
	print(c);
	Merge_sort(&c);
	print(c);

}	
