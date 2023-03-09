#include <iostream>
using namespace std;
template <class Type>
//最小化整型优先队列 
class priorityQueue
{
public:
    int maxsize;
    int currentLength;
    void doubleSpace();
    void buildHeap(){
        for (int i=currentLength/2; i>0; i--) percolateDown(i);
    }
    void percolateDown(int hole);
    void percolateUp(int hole);
public:
    Type *array;
    priorityQueue(int capacity=100){
        array = new Type[capacity];
        currentLength=0;
        maxsize=capacity;
    }
    priorityQueue(const Type item[],int size);
    ~priorityQueue(){delete[] array;};
    bool isEmpty()const{return currentLength==0;}
    void enQueue(const Type &x);
    void print(){
        for (int i=1; i<=currentLength; i++) {
            cout<<array[i];
        }
    }
    Type deQueue();
    Type getHead()const{return array[1];}
    int find(int x);
    void decrease(int i,int v)
	{
        array[i]-=v;
        int x=array[i];
         int hole =i;
           for (;hole>1&&x<array[hole/2]; hole/=2) array[hole]=array[hole/2];
           array[hole]=x;
    }
};

template <class Type>
void priorityQueue<Type>:: doubleSpace(){
    maxsize*=2;
    Type *tmp=array;
    array=new Type[maxsize];
    for (int i=1; i<currentLength; i++) {
        array[i]=tmp[i];
    }
    delete []tmp;
}

template <class Type>
priorityQueue<Type>:: priorityQueue(const Type item[],int size):maxsize(size+10),currentLength(size)
{
    array=new Type[size+10];
    for (int i=0; i<size; i++) array[i+1]=item[i];
    buildHeap();
}

template <class Type>
void priorityQueue<Type>:: enQueue(const Type &x)
{
    if (currentLength==maxsize-1) doubleSpace();
    int hole =++currentLength;
    for (;hole>1&&x<array[hole/2]; hole/=2) {array[hole]=array[hole/2];}
    array[hole]=x;
}

template <class Type>
void priorityQueue<Type>:: percolateUp(int hole)
{
    Type tmp = array[hole];
    for(;tmp<array[hole/2]&&hole>1;hole/=2) {
        array[hole]=array[hole/2];
    }
    array[hole]=tmp;
}

template <class Type>
Type priorityQueue<Type>::deQueue()
{
    Type minItem=array[1];
    array[1]=array[currentLength--];
    percolateDown(1);
    return minItem;
}

template <class Type>
void priorityQueue<Type>:: percolateDown(int hole)
{
    int child=2*hole;
    Type tmp=array[hole];
    for (; child<=currentLength; hole*=2) {
        if (child+1<=currentLength && array[child]>array[child+1]) child++;
        if(array[child]<tmp)array[hole]=array[child];
        else break;
    }
    array[hole]=tmp;
}

// int findMin(x) Function
template <class Type>
int  priorityQueue<Type>:: findMin(int x)
{
    int subscript=currentLength;
    int ans=1000000;
    for (int i=currentLength; i>=1; i--) 
	{
        if (array[i]>x && array[i]<=ans) 
		{
            subscript=i;
            ans=array[i];
        }
    }
    return subscript;
}// Complexity O(N)

//decreaseKey(i,value)
template <class Type>
void priorityQueue<Type>:: decreaseKey(int i, int value)
{
	array[i]=array[i]-value;
	percolateUp(i);
}

int main() 
{
   
}

