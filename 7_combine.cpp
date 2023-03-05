#include "sLinkList.h"
	
template <class elemType>
	void sLinkList<elemType>::combine(sLinkList<elemType> *head1, currentLenth1; sLinkList<elemType> *head2, currentLenth2)
	{
		node *pre = head1;
		while (currentLength1-- >= 0) pre = pre->next;
		head2->next=pre->next;
		delete head2;	
		return 1;
	}
