#include<iostream>
using namespace std;


template <class elemType>
class seqQueue: public queue<elemType>
{
	private:
	elemType *elem;
	int maxSize;
	int front, rear;
	void doubleSpace();
	public:
	seqQueue(int size )£»
	~seqQueue() £»
	bool isEmpty() £»
	void enQueue(const elemType &x) ;
	elemType deQueue(); 
}

template <class elemType>
bool seqQueue<elemType>::isEmpty() const 
{
	return front == rear;
}

template <class elemType>
void seqQueue<elemType>::doubleSpace()
{ 
	elemType *tmp =elem;
	elem = new elemType[2 * maxSize];
	for (int i = 0; i < maxSize; ++i)
	elem[i] = tmp[(front + i + 1) % maxSize];
	front = -1;
	maxSize *= 2;
	delete tmp;
}

template <class elemType>
	seqQueue<elemType>::seqQueue(int size)
{ 
	elem = new elemType[size];
	maxSize = size; 
	front = rear = 0;
}

template <class elemType>
seqQueue<elemType>::~seqQueue()
{
	delete [] elem;
}


template <class elemType>
	seqQueue<elemType>::enQueue(const elemType &x)
{ 
	if (rear==size-1)
		cout<<"Error!OutOfSpace"<<endl;
		doubleSpace();
	else
		elem[rear]=x;
		rear=rear+1;
}

template <class elemType>
	seqQueue<elemType>::deQueue()
{ 
	if (rear==front)
		cout<<"Error!EmptyQueue"<<endl;
		return 0;
	else
		cout<< elem[front] <<endl;
		elemType *tmp=elem[front];
		for(int i=1; i<=rear; i++)
			elem[i-1]=elem[i];
		delete elem[rear];
		rear=rear-1;	
}
