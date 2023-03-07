// Check whether every node of tree is ordered;
// Using recursive meyhod;

<class KEY, class OTHER>
SET<KEY, OTHER> * BinarySearchTree<KEY, OTHER>::check(BinaryNode * & t) const
{ 
	return check( root ); 
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::check( BinaryNode *t ) const
{ 
	if ( t == NULL  )
		printf("Binary Tree is Ordered.") ; 
	temp=t->data.key;
	BinaryNode *leftNode=t->left;
	BinaryNode *rightNode=t->right;
	leftData=leftNode->data.key;
	rightData=rightNode->data.key;
	if( leftData<=temp &&  rightData>=data) 
		return check( t->left ); //Check left child
		return check( t->right ); //Check right child
	else
		printf("Binary Tree is not ordered.");
		return 0;
}
