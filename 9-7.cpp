// Find the i-th smallest element in the whole binary search tree;
// The mid-order output of BinarySearchTree is totally ordered;
template<class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::midOrder(void BinarySearchTree<KEY, OTHER>::BinaryNode *t) const
{ 
	if (t == NULL) return;
	midOrder(t->left);
	k=k+1;
	cout <<k,"-th ", t->data << " ";
	midOrder(t->right);
}

template<class T>
void BinarySearchTree<KEY, OTHER>::midOrder() const
{ 
	int k=0;
	midOrder(root);
}

template <class KEY, class OTHER>
SET<KEY, OTHER> * BinarySearchTree<KEY, OTHER>::findIthMin(const KEY & i, BinaryNode * & t ) const
{
	cout << "The i-th smallest element is: /n"<<endl;
	midOrder(t);
}
