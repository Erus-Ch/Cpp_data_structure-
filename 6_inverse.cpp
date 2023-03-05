#include "sLinkList.h"

template <class elemType>
	void sLinkList<elemType>::inverse()
	{
		node *first=head->next;
		node *alpha,*beta;
		for(int i=1;i<=currentLength;i++)
		{
			alpha=first->next;
			beta=alpha->next;
			beta=first->next;
			alpha=head->next;
			first=alpha->next;
		}
	return 1;
	}
	
