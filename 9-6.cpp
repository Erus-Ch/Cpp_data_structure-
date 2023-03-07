//Return to the maximum of all elements;
template <class KEY, class OTHER>
SET<KEY, OTHER> * BinarySearchTree<KEY, OTHER>::findMax(BinaryNode * & t ) const
{ 
	return findMax( root ); 
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::findMax( BinaryNode *t ) const
{ 
	BinaryNode *tmp = t; 
	while (t->right != NULL) 
		tmp = t-> right; 
	cout<< tmp->data <<endl;
}


//Return to the minimum of all elements;
template <class KEY, class OTHER>
SET<KEY, OTHER> * BinarySearchTree<KEY, OTHER>::findMin(BinaryNode * & t ) const
{ 
	return findMin( root ); 
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::findMin( BinaryNode *t ) const
{ 
	BinaryNode *tmp = t; 
	while (t->left != NULL) 
		tmp = t-> left; 
	cout<< tmp->data <<endl;
}
