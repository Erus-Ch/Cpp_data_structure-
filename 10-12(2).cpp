//利用二叉堆排序O(NlogN);
//进行二分查找O(NlogN)
//总时间复杂度为O（NlogN) 

template <class KEY, class OTHER>
void searchSum(SET<KEY, OTHER> a[],int size, int k)
{
	heapSort(a[],size);
	for(int i=1;i<=size/2;i++)
	{
			if (binarySearch(a[],size,k)==true)
		cout<<a[i],k-a[i]<<endl;
	}

}

template <class KEY, class OTHER>
void heapSort(SET<KEY, OTHER> a[], int size)
{
	int i; 
	SET<KEY, OTHER> tmp;
	for( i = size / 2 - 1; i >= 0; i-- ) 
	percolateDown( a, i, size );
	for ( i = size - 1; i > 0; --i) {
	tmp = a[0]; a[0] = a[i]; a[i] = tmp; 
	percolateDown(a,0, i ); 
}
}

template <class KEY, class OTHER>
void binarySearch(SET<KEY, OTHER> a[], int size, int p)
{
	int low=1, high=size;
	while (low-high<=1)
	{
		if (a[high/2]>p)
			low=high/2;
		else if (a[high/2]<p)
			high=high/2;
		else 
			return true;
			break;
	}
}

