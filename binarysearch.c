#include<stdio.h>

void input(int [],int);
void binarysearch(int [],int,int);
void display(int [],int);

int main()
{
	int arr[50],n,key;
	printf("Enter the total number of elements present in array:");
	scanf("%d",&n);
	input(arr,n);
	printf("Enter the key:");
	scanf("%d",&key);
	binarysearch(arr,n,key);
	
	return 0;
}

void input(int arr[],int n)
{
	int i;
	printf("Enter the elements of array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}

void binarysearch(int arr[],int n,int key)
{
	int high=n-1;
	int low=0;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
	
	if(arr[mid]==key)
	{
		printf("Element found at position %d\n",mid+1);
		break;
	}
	if(arr[mid]<key)
	{
		low=mid+1;
	}
	else
	{
		high=mid-1;
	}
}

}


