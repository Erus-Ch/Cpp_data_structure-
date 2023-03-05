#include "sLinkList.h"

template <class elemType>
	void sLinkList<elemType>::erase(int x, int y)
	{
		if x>y||x<=0||y<=0||x>=currentLength||y>=currentLength
		{
			cout<<"Not Valid Entrance"<<endl;
			return 0;
		}
		else
		{
			node *pre = head;
			while (x-- >= 0) pre = pre->next;
			
			for(int i=x;i<=y;i++)
			{
				node *delp=pre->next;
				elemType tmp=delp->data;
				pre->next=delp->next;
				delete delp;
				--currentLength;
			}
			return 1;
		}
	}
	
