#include<iostream>
using namespace std;

//用一次快速排序，0作为划分界限 
int main()
{
	int tmp, size;
	cin>>size;
	int A[size+1];
	for (int i=1;i<=size;i++)
		cin>>A[i];
	A[0]=0;
	int low=0, high=size;
	while(low!=high)
	{
		while (low<high&&A[high]>0)--high;
		if (low<high){A[low]=A[high];++low;}
		while (low<high&&A[low]<0)++low;
		if (low<high){A[high]=A[low];--high;}	
	}
	A[low]=0;
	for (int i=0;i<=size;i++)
		cout<<A[i]<<" ";
}
