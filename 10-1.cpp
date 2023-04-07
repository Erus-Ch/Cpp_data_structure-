#include<iostream>
using namespace std;

template <class KEY, class OTHER>
void quickSort(SET<KEY, OTHER> a[], int low, int high)
{ 
	int mid;
	if (low >= high) return; 
	mid = divide(a, low, high); 
	quickSort( a, low, mid-1);
	quickSort( a, mid+1, high);	
}

template <class KEY, class OTHER>
int divide( SET<KEY, OTHER> a[], int low, int high) 
{
	SET<KEY, OTHER> k = a[low]; 
	do {
	while (low < high && a[high].key >= k.key) --high; 
	if (low < high) { a[low] = a[high]; ++low;} 
	while (low < high && a[low].key <= k.key) ++low; 
	if (low < high) {a[high] = a[low]; --high;} 
	}
	while (low != high); 
	a[low] = k; 
	return low;
}

template <class KEY, class OTHER>
void quickSort(SET<KEY, OTHER> a[], int size)
{
	quickSort(a, 0, size-1);
}

int main()
{
	int tmp, size, a;
	cin>>size;
	int A[size];
	tmp=size;
	for (int i=1;i<=size;i++)
		cin>>A[i];
	quickSort(A[size],size)
	for (int i=1;i<=tmp;i++)
		if (A[i]==A[i+1])
			size--;
			delete A[i];
	return size;
}




