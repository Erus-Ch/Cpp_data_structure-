//Function 1
//最大化堆进行k次deQueue操作
//O(N+klogN)=建堆(O(N)和输出O(klogN) 
template <class KEY, class OTHER>
void k_th1(SET<KEY, OTHER> a[], int k)
{
	int tmp;
	a[]=buildHeap();
	for (int i=1; i<=k;i++)
	{
		tmp=array[1];
		deQueue();
	}
	return tmp;
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


