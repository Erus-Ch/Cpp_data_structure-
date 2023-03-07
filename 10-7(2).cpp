//容量为k的最小化堆，堆中的k个节点代表着当前最大的k个元素，而堆顶显然是这K个元素中的最小值。
//遍历原数组，每遍历一个元素，就和堆顶比较，如果当前元素小于等于堆顶，则继续遍历;
//如果元素大于堆顶，则把当前元素放在堆顶位置，并调整二叉堆(下沉操作)。
//遍历结束后，堆顶就是数组的最大k个元素中的最小值，也就是第k大元素。
//时间复杂度=O(Nlogk)=O(N)遍历*O(logk)最小化堆k

template <class KEY, class OTHER>
void k_th2(SET<KEY, OTHER> a[], int k)
{
	int b[k]
	for (int i=1;i<=k;i++)
		b[i]=a[i];
	int tmp;
	buildHeap(b[]);
	for (int j=k;j<=n;j++)
	{
		if a[j]>=b[1]
			enQueue(a[j]);
	}
	return b[1];
}

template <class Type>
class priorityQueue:publicqueue<Type>
{
private:
	intcurrentSize;
	Type *array;
	intmaxSize;
	void doubleSpace();
	void buildHeap( );
	void percolateDown( int hole);
public:
	priorityQueue( intcapacity = 100 )
{ array = new Type[capacity];
	maxSize= capacity;
	currentSize= 0;}
	priorityQueue( constType data[], intsize );
	~priorityQueue() { delete [] array; }
	bool isEmpty( ) const{ return currentSize== 0; }
	void enQueue( const Type & x );
	Type deQueue();
	Type getHead() { return array[1]; }
};

template <class Type>
void priorityQueue<Type>::enQueue( const Type & x )
{
	if( currentSize== maxSize-1 ) doubleSpace();
	int 	hole = ++currentSize; 
	for( ; hole > 1 && x < array[ hole / 2 ]; hole /= 2 ) 
	array[ hole ] = array[ hole / 2 ]; 
	array[ hole ] = x; 
}

template <class KEY, class OTHER>
void heapTree<Type>::bulidHeap()
{ buildHeap(root) }

template <class KEY, class OTHER>
void heapTree<Type>::buildHeap(heapTree<T>::Node *t ）
{
	buildHeap(t->left);
	buildHeap(t->right);
	percolateDown(t); 
}

template <class Type>
priorityQueue<Type>::priorityQueue( constType *items, int size )
: maxSize(size+10 ), currentSize(size)
{
	array = new Type[maxSize];
	for( inti= 0; i< size; i++ )
	array[ i+ 1 ] = items[ i]; 
	buildHeap();
}

template <class KEY, class OTHER>
void heapSort(SET<KEY, OTHER> a[], int size)
{
	int i; 
	SET<KEY, OTHER> tmp;
	for( i = size/2-1; i>=0; i-- ) 
	percolateDown( a, i, size );
	for ( i = size-1; i > 0; --i) 
	{
	tmp = a[0]; a[0] = a[i]; a[i] = tmp; 
	percolateDown(a,0, i );
	}
}

template <class Type>
Type priorityQueue<Type>::deQueue()
{ 
	Type minItem;
	minItem= array[ 1 ]; 
	array[ 1 ] = array[ currentSize--]; 
	percolateDown( 1 ); 
	return minItem;
}
template <class KEY, class OTHER>
void percolateDown( SET<KEY, OTHER> a[], int hole, int size )
{ 
	int child;
	SET<KEY, OTHER> tmp = a[ hole ]; 
	for( ; hole * 2 + 1 < size; hole = child ) 
	{
	child = hole * 2 + 1; 
	if( child != size - 1 && a[child+1].key>a[ child ].key )
	child++;
	if( a[child].key>tmp.key) a[hole]=a[child]; 
	else break;
}
	a[hole] = tmp; 
}
