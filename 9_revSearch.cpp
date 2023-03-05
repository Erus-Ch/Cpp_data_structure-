#include "sLinkList.h"

template <class elemType>
	void sLinkList<elemType>:: revSearch(int k)
	{
		if k<=0||k>=currentLength
		{
			cout<<"Not Valid Entrance"<<endl;
			return 0;
		}
		else
		{
			node *pre=head->next;
			for(int i=1;i<=currentLength-k;i++)
			{
				pre=pre->next;
			}
			elemType tmp=pre->data;
			cout<< tmp <<endl;
			return 1;
		}
	}
